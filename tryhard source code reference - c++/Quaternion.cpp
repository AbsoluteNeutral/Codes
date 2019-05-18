/*****************************************************************************/
/*!
\file			Quaternion.cpp
\brief			Quaternion Implmentation
*/
/*****************************************************************************/
#include "stdafx.h"
#include "Quaternion.hpp"

namespace zg {

	Quaternion::Quaternion() noexcept
		:x(0.0f), y(0.0f), z(0.0f), w(1.0f)
	{}
	Quaternion::Quaternion(float x_, float y_, float z_, float w_)
		: x(x_), y(y_), z(z_), w(w_)
	{}
	Quaternion::Quaternion(const Vector3& v, float angle){
		float rad = TO_RAD(angle) * 0.5f;
		float s = std::sin(rad);
		x = v.x * s;
		y = v.y * s;
		z = v.z * s;
		w = std::cos(rad);
	}
	
	//setters
	void Quaternion::AddScaledVector(const Vector3& vector, float scale) {
		Quaternion q(vector.x * scale, vector.y * scale, vector.z * scale, 0.0f);
		q *= *this;
		x += q.x * 0.5f;
		y += q.y * 0.5f;
		z += q.z * 0.5f;
		w += q.w * 0.5f;
	}
	
	void Quaternion::Conjugate(){
		x = -x;	y = -y;	z = -z;
	}
	
	void Quaternion::Integrate(const Vector3& vector, float scale) {
		Quaternion q(vector.x * scale, vector.y * scale, vector.z * scale, 0.0f);
		q *= *this;
		x += q.x * 0.5f;
		y += q.y * 0.5f;
		z += q.z * 0.5f;
		w += q.w * 0.5f;
	}
	void Quaternion::Invert() {
		float lengthSq = LengthSq();
		//ErrorIf(lengthSq <= EPSILON, "Quaternion - Division by zero.");
		lengthSq = 1.0f / lengthSq;
		x = -x * lengthSq;
		y = -y * lengthSq;
		z = -z * lengthSq;
		w =  w * lengthSq;
	}
	
	float Quaternion::Normalize() {
		float len = LengthSq();
		if (len == 0.0f) {
			x = y = z = 0.0f;
			w = 1.0f;
			return 0.0f;
		}
		len = 1.0f / sqrtf(len);
		x *= len; y *= len;
		z *= len; w *= len;
		return len;
	}
	
	void Quaternion::Set(float x_, float y_, float z_, float w_) {
		x = x_;	y = y_;	z = z_;	w = w_;
	}
	
	void Quaternion::SetFromEulerAngles(float RADIAN_x, float RADIAN_y, float RADIAN_z) {
		//const float halfx = LoopInclude(RADIAN_x, -TWOPI, TWOPI) * 0.5f;
		//const float halfy = LoopInclude(RADIAN_y, -TWOPI, TWOPI) * 0.5f;
		//const float halfz = LoopInclude(RADIAN_z, -TWOPI, TWOPI) * 0.5f;
	
		const float halfx = RADIAN_x * 0.5f;
		const float halfy = RADIAN_y * 0.5f;
		const float halfz = RADIAN_z * 0.5f;
		const Vector3 c{ std::cos(halfx), std::cos(halfy), std::cos(halfz) };
		const Vector3 s{ std::sin(halfx), std::sin(halfy), std::sin(halfz) };
	
		const float cosYcosZ = c.y * c.z;
		const float cosYsinZ = c.y * s.z;
		const float sinYsinZ = s.y * s.z;
		const float sinYcosZ = s.y * c.z;
		x = s.x * cosYcosZ - c.x * sinYsinZ;
		y = c.x * sinYcosZ + s.x * cosYsinZ;
		z = c.x * cosYsinZ - s.x * sinYcosZ;
		w = c.x * cosYcosZ + s.x * sinYsinZ;
	
		x = (x > -EPSILON && x < EPSILON) ? 0.0f : x;
		y = (y > -EPSILON && y < EPSILON) ? 0.0f : y;
		z = (z > -EPSILON && z < EPSILON) ? 0.0f : z;
		w = (w > -EPSILON && w < EPSILON) ? 0.0f : w;
	}
	
	void Quaternion::SetFromEulerAngles(const Vector3& v) {
		float x_ = LoopInclude(v.x, -360.0f, 360.0f);	//v.x, 
		float y_ = LoopInclude(v.y, -360.0f, 360.0f);	//v.y, 
		float z_ = LoopInclude(v.z, -360.0f, 360.0f);	//v.z  
		SetFromEulerAngles(TO_RAD(x_), TO_RAD(y_), TO_RAD(z_));
	}
	
	//getters const 
	float Quaternion::Dot(const Quaternion& rhs) const {
		return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	}
	
	Vector3 Quaternion::GetAxis() const {
		float angle_rad = 1.0f / sin(acos(x));
		return Vector3{
			x * angle_rad,
			y * angle_rad,
			z * angle_rad
		};
	}
	
	Quaternion Quaternion::GetRotationAngleAxis(float& angle, Vector3& axis) const {
		//angle = std::acos(w) * 0.5f;	// Compute the roation angle
		//Vector3 rotationAxis(x, y, z);	// Compute the 3D rotation axis
		//rotationAxis.Normalize();		// Normalize the rotation axis
		//// Set the rotation axis values
		//axis.x = rotationAxis.x;
		//axis.y = rotationAxis.y;
		//axis.z = rotationAxis.z;
	
		float halfAngle = angle * 0.5f;
		float s = std::sin(halfAngle);
		Quaternion q;
		q.x = axis.x * s;
		q.y = axis.y * s;
		q.z = axis.z * s;
		q.w = std::cos(halfAngle);
		return q;
	}
	
	Quaternion Quaternion::GetConjugated() const{
		return Quaternion{ -x, -y, -z, w };
	}
	
	Quaternion Quaternion::GetExponent() const {
		float angle = Vector3{ x, y, z }.Length();
		Quaternion quaternion(x, y, z, 0.0f);
		if (fabsf(angle) > EPSILON) {
			quaternion.w = std::cos(angle);
			angle = std::sin(angle) / angle;
			quaternion.x *= angle;
			quaternion.y *= angle;
			quaternion.z *= angle;
		}
		return quaternion;
	}
	
	Quaternion Quaternion::GetInverted() const {
		float lengthSq = LengthSq();
		//ErrorIf(lengthSq <= EPSILON, "Quaternion - Division by zero.");
		lengthSq = 1.0f / lengthSq;
		return Quaternion(-x * lengthSq, -y * lengthSq, -z * lengthSq, w * lengthSq);
	}
	
	Matrix33 Quaternion::GetMatrix33() const {
		float nQ  = x * x + y * y + z * z + w * w;
		float s   = nQ > 0.0f ? 2.0f / nQ : 0.0f;
		float xs  = x * s;
		float ys  = y * s;
		float zs  = z * s;
		float wxs = w * xs;
		float wys = w * ys;
		float wzs = w * zs;
		float xxs = x * xs;
		float xys = x * ys;
		float xzs = x * zs;
		float yys = y * ys;
		float yzs = y * zs;
		float zzs = z * zs;
		return Matrix33{ 1.0f - yys - zzs,	xys - wzs,			xzs + wys,
						 xys + wzs,			1.0f - xxs - zzs,	yzs - wxs,
						 xzs - wys,			yzs + wxs,			1.0f - xxs - yys };
	}
	
	Matrix44 Quaternion::GetMatrix44() const {
		float nQ = x * x + y * y + z * z + w * w;
		float s = nQ > 0.0f ? 2.0f / nQ : 0.0f;
		float xs =  x * s;
		float ys =  y * s;
		float zs =  z * s;
		float wxs = w * xs;
		float wys = w * ys;
		float wzs = w * zs;
		float xxs = x * xs;
		float xys = x * ys;
		float xzs = x * zs;
		float yys = y * ys;
		float yzs = y * zs;
		float zzs = z * zs;
		return Matrix44{1.0f - yys - zzs,	xys - wzs,			xzs + wys,			0.0f,
						xys + wzs,			1.0f - xxs - zzs,	yzs - wxs,			0.0f,
						xzs - wys,			yzs + wxs,			1.0f - xxs - yys,	0.0f,
						0.0f,				0.0f,				0.0f,				1.0f	};
	}
	
	Quaternion Quaternion::Normalized() const {
		float len = LengthSq();
		if (len == 0.0f)
			return Quaternion{};
		len = 1.0f / sqrtf(len);
		return Quaternion{ x * len, y * len, z * len, w * len };
	}
	
	Vector3 Quaternion::GetRotatedVector(const Vector3& vector) const {
		Quaternion tempVec{ vector.x, vector.y, vector.z, 0.0f };
		Quaternion result(*this);
		result *= tempVec;
		result *= GetConjugated();
		return Vector3{ result.x, result.y, result.z };
	}
	
	Vector3	Quaternion::GetVector3() const {
		return Vector3{ x, y, z };
	}
	
	float Quaternion::LengthSq() const { return x * x + y * y + z * z + w * w; }
	float Quaternion::Length()	 const { return sqrtf(x*x + y * y + z * z + w * w); }
	Vector3 Quaternion::ToEularDegree() const {
		float sqw = w * w;
		float sqx = x * x;
		float sqy = y * y;
		float sqz = z * z;
		float z_ = TO_DEG(atan2(2.0f * (x * y + z * w), (sqx - sqy - sqz + sqw)));  //z
		float x_ = TO_DEG(atan2(2.0f * (y * z + x * w), (-sqx - sqy + sqz + sqw))); //x
		float y_ = TO_DEG(asin(-2.0f * (x * z - y * w)));						   //y
		z_ = (z_ > -EPSILON && z_ < EPSILON) ? 0.0f : z_;
		x_ = (x_ > -EPSILON && x_ < EPSILON) ? 0.0f : x_;
		y_ = (y_ > -EPSILON && y_ < EPSILON) ? 0.0f : y_;
		return Vector3{ x_, y_, z_ };
	}
	
	//static
	Quaternion Quaternion::Identity{};
	Vector3 Quaternion::ToEularDegree(const Quaternion& q) {
		float sqw = q.w * q.w; 
		float sqx = q.x * q.x;
		float sqy = q.y * q.y;
		float sqz = q.z * q.z;
		float z = TO_DEG(atan2(2.0f * (q.x * q.y + q.z * q.w), (sqx - sqy - sqz + sqw)));  //z
		float x = TO_DEG(atan2(2.0f * (q.y * q.z + q.x * q.w), (-sqx - sqy + sqz + sqw))); //x
		float y = TO_DEG(asin(-2.0f * (q.x * q.z - q.y * q.w)));						   //y
		x = (x > -EPSILON && x < EPSILON) ? 0.0f : x;
		y = (y > -EPSILON && y < EPSILON) ? 0.0f : y;
		z = (z > -EPSILON && z < EPSILON) ? 0.0f : z;
		return Vector3{ x, y, z };
	}
	
	Quaternion Quaternion::FromEulerAngles(float RADIAN_x, float RADIAN_y, float RADIAN_z) {
		const float halfx = RADIAN_x * 0.5f;
		const float halfy = RADIAN_y * 0.5f;
		const float halfz = RADIAN_z * 0.5f;
	
		const Vector3 c{ std::cos(halfx), std::cos(halfy), std::cos(halfz) };
		const Vector3 s{ std::sin(halfx), std::sin(halfy), std::sin(halfz) };
		const float cosYcosZ = c.y * c.z;
		const float cosYsinZ = c.y * s.z;
		const float sinYsinZ = s.y * s.z;
		const float sinYcosZ = s.y * c.z;
		float x = s.x * cosYcosZ - c.x * sinYsinZ;
		float y = c.x * sinYcosZ + s.x * cosYsinZ;
		float z = c.x * cosYsinZ - s.x * sinYcosZ;
		float w = c.x * cosYcosZ + s.x * sinYsinZ;
		x = (x > -EPSILON && x < EPSILON) ? 0.0f : x;
		y = (y > -EPSILON && y < EPSILON) ? 0.0f : y;
		z = (z > -EPSILON && z < EPSILON) ? 0.0f : z;
		w = (w > -EPSILON && w < EPSILON) ? 0.0f : w;
	
		return Quaternion{ x, y, z, w };
		//const float cx = std::cos(halfx);
		//const float cy = std::cos(halfy);
		//const float cz = std::cos(halfz);
		//const float sx = std::sqrtf(1.0f - cx * cx); //std::sin(halfx);
		//const float sy = std::sqrtf(1.0f - cy * cy); //std::sin(halfy);
		//const float sz = std::sqrtf(1.0f - cz * cz); //std::sin(halfz);
		//const float cosYcosZ = cy * cz;
		//const float cosYsinZ = cy * sz;
		//const float sinYsinZ = sy * sz;
		//const float sinYcosZ = sy * cz;
		//float x = sx * cosYcosZ - cx * sinYsinZ;
		//float y = cx * sinYcosZ + sx * cosYsinZ;
		//float z = cx * cosYsinZ - sx * sinYcosZ;
		//float w = cx * cosYcosZ + sx * sinYsinZ;
	
		//x = (x > -EPSILON && x < EPSILON) ? 0.0f : x;
		//y = (y > -EPSILON && y < EPSILON) ? 0.0f : y;
		//z = (z > -EPSILON && z < EPSILON) ? 0.0f : z;
		//w = (w > -EPSILON && w < EPSILON) ? 0.0f : w;
	}
	
	Quaternion Quaternion::FromEulerAngles(const Vector3& v) {
		float x = LoopInclude(v.x, -360.0f, 360.0f);	//v.x, 
		float y = LoopInclude(v.y, -360.0f, 360.0f);	//v.y, 
		float z = LoopInclude(v.z, -360.0f, 360.0f);	//v.z  
	
		return FromEulerAngles(TO_RAD(x), TO_RAD(y), TO_RAD(z));
		//return FromEulerAngles(TO_RAD(v.x), TO_RAD(v.y), TO_RAD(v.z));
	}
	
	Quaternion Quaternion::Slerp(const Quaternion& quaternion1, const Quaternion& quaternion2, float t) {
		float invert = 1.0f;
	
		// Compute cos(theta) using the quaternion scalar product
		float cosineTheta = quaternion1.Dot(quaternion2);
	
		// Take care of the sign of cosineTheta
		if (cosineTheta < float(0.0)) {
			cosineTheta = -cosineTheta;
			invert = -1.0f;
		}
	
		// Because of precision, if cos(theta) is nearly 1,
		// therefore theta is nearly 0 and we can write
		// sin((1-t)*theta) as (1-t) and sin(t*theta) as t
		if (1 - cosineTheta < EPSILON) {
			return quaternion1 * (float(1.0f) - t) + quaternion2 * (t * invert);
		}
	
		// Compute the theta angle
		float theta = std::acos(cosineTheta);
	
		// Compute sin(theta)
		float sineTheta = std::sin(theta);
	
		// Compute the two coefficients that are in the spherical linear interpolation formula
		float coeff1 = std::sin((float(1.0f) - t)*theta) / sineTheta;
		float coeff2 = std::sin(t*theta) / sineTheta * invert;
	
		// Compute and return the interpolated quaternion
		return quaternion1 * coeff1 + quaternion2 * coeff2;
	}
	
	Quaternion Quaternion::FromToRotation(const Vector3& fromVector, const Vector3& toVector){
		float dot = fromVector.Dot( toVector);
		float k = sqrt(fromVector.LengthSq() * toVector.LengthSq());
		if (fabs(dot / k + 1) < EPSILON)
		{
			Vector3 ortho = zg::Orthogonal(fromVector);
			return Quaternion(ortho.Normalized(), 0);
		}
		Vector3 cross = fromVector.Cross(toVector);
		return Quaternion(cross, dot + k).Normalized();
	}
	
	Quaternion Quaternion::LookRotation(const Vector3& forward, const Vector3& up, const Vector3& front){
		UNREFERENCED_PARAMETER(front);
		Vector3 vector = forward.Normalized();
		Vector3 vector2 = Cross(up, vector);
		Vector3 vector3 = Cross(vector, vector2);
		float m00 = vector2.x;
		float m01 = vector2.y;
		float m02 = vector2.z;
		float m10 = vector3.x;
		float m11 = vector3.y;
		float m12 = vector3.z;
		float m20 = vector.x;
		float m21 = vector.y;
		float m22 = vector.z;
	
		float num8 = (m00 + m11) + m22;
		Quaternion quaternion{};// = FQuat();
		if (num8 > 0.0f)
		{
			float num = (float)std::sqrt(num8 + 1.0f);
			quaternion.w = num * 0.5f;
			num = 0.5f / num;
			quaternion.x = (m12 - m21) * num;
			quaternion.y = (m20 - m02) * num;
			quaternion.z = (m01 - m10) * num;
	
			return quaternion;
		}
		if ((m00 >= m11) && (m00 >= m22))
		{
			float num7 = (float)std::sqrt(((1.0f + m00) - m11) - m22);
			float num4 = 0.5f / num7;
			quaternion.x = 0.5f * num7;
			quaternion.y = (m01 + m10) * num4;
			quaternion.z = (m02 + m20) * num4;
			quaternion.w = (m12 - m21) * num4;
	
			return quaternion;
		}
		if (m11 > m22)
		{
			float num6 = (float)std::sqrt(((1.0f + m11) - m00) - m22);
			float num3 = 0.5f / num6;
			quaternion.x = (m10 + m01) * num3;
			quaternion.y = 0.5f * num6;
			quaternion.z = (m21 + m12) * num3;
			quaternion.w = (m20 - m02) * num3;
	
			return quaternion;
		}
		float num5 = (float)std::sqrt(((1.0f + m22) - m00) - m11);
		float num2 = 0.5f / num5;
		quaternion.x = (m20 + m02) * num2;
		quaternion.y = (m21 + m12) * num2;
		quaternion.z = 0.5f * num5;
		quaternion.w = (m01 - m10) * num2;
	
		return quaternion;
	
		//// Normalize inputs
		//Vector3 forward = forward.Normalized();
		//Vector3 upwards = up.Normalized();
		//// Don't allow zero vectors
		//if (forward.LengthSq() < EPSILON || upwards.LengthSq() < EPSILON)
		//	return Quaternion::Identity();
		//// Handle alignment with up direction
		//if (1 - fabs( forward.Dot(upwards) ) < EPSILON)
		//	return FromToRotation(front, forward);
		//// Get orthogonal vectors
		//Vector3 right = Cross(upwards, forward).Normalized();
		//upwards = Cross(forward, right);
		//// Calculate rotation
		//Quaternion quaternion;
		//float radicand = right.x + upwards.y + forward.z;
		//if (radicand > 0)
		//{
		//	quaternion.w = sqrt(1.0f + radicand) * 0.5f;
		//	float recip = 1.0f / (4.0f * quaternion.w);
		//	quaternion.x = (upwards.z - forward.y) * recip;
		//	quaternion.y = (forward.x - right.z) * recip;
		//	quaternion.z = (right.y - upwards.x) * recip;
		//}
		//else if (right.x >= upwards.y && right.x >= forward.z)
		//{
		//	quaternion.x = sqrt(1.0f + right.x - upwards.y - forward.z) * 0.5f;
		//	float recip = 1.0f / (4.0f * quaternion.x);
		//	quaternion.w = (upwards.z - forward.y) * recip;
		//	quaternion.z = (forward.x + right.z) * recip;
		//	quaternion.y = (right.y + upwards.x) * recip;
		//}
		//else if (upwards.y > forward.z)
		//{
		//	quaternion.y = sqrt(1.0f - right.x + upwards.y - forward.z) * 0.5f;
		//	float recip = 1.0f / (4.0f * quaternion.y);
		//	quaternion.z = (upwards.z + forward.y) * recip;
		//	quaternion.w = (forward.x - right.z) * recip;
		//	quaternion.x = (right.y + upwards.x) * recip;
		//}
		//else
		//{
		//	quaternion.z = sqrt(1.0f - right.x - upwards.y + forward.z) * 0.5f;
		//	float recip = 1.0f / (4.0f * quaternion.z);
		//	quaternion.y = (upwards.z + forward.y) * recip;
		//	quaternion.x = (forward.x + right.z) * recip;
		//	quaternion.w = (right.y - upwards.x) * recip;
		//}
		//return quaternion;
	}
	
	//operator
	Quaternion& Quaternion::operator-=(const Quaternion& rhs){ x -= rhs.x;	y -= rhs.y;	z -= rhs.z;	w -= rhs.w;	return *this; }
	Quaternion& Quaternion::operator+=(const Quaternion& rhs){ x += rhs.x;	y += rhs.y; z += rhs.z; w += rhs.w; return *this; }
	Quaternion& Quaternion::operator*=(float f)				 { x *= f;		y *= f;		z *= f;		w *= f;		return *this; }
	Quaternion& Quaternion::operator*=(const Quaternion& rhs){
		Quaternion lhs{ *this };
		//x = lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y;
		//y = lhs.w * rhs.y + lhs.y * rhs.w + lhs.z * rhs.x - lhs.x * rhs.z;
		//z = lhs.w * rhs.z + lhs.z * rhs.w + lhs.x * rhs.y - lhs.y * rhs.x;
		//w = lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z;
	
		w = lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z;
		x = lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y;
		y = lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x;
		z = lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w;
		return *this;
	}
	Quaternion& Quaternion::operator/=(float rhs) {
		ErrorIf(rhs <= EPSILON, "Quaternion - Division by zero.");
		float reciprocal = 1.0f / rhs;
		x *= reciprocal;
		y *= reciprocal;
		z *= reciprocal;
		w *= reciprocal;
		return *this;
	}
	bool Quaternion::operator==(const Quaternion &r) const { return ((x == r.x) && (y == r.y) && (z == r.z) && (w == r.w)); }
	#ifdef USING_SOL2
	Quaternion Quaternion::operator-()						const { return Quaternion{ -x, -y, -z, w }; }
	Quaternion Quaternion::operator-(const Quaternion& rhs) const	{ return Quaternion{ x - rhs.x,	y - rhs.y,	z - rhs.z,	w - rhs.w }; }
	Quaternion Quaternion::operator+(const Quaternion& rhs) const	{ return Quaternion{ x + rhs.x,	y + rhs.y,	z + rhs.z,	w + rhs.w }; }
	Quaternion Quaternion::operator*(float f)			    const	{ return Quaternion{ x * f,		y * f,		z * f,		w * f	  }; }
	Vector3 Quaternion::operator*(const Vector3& rhs)	const {
		const float prodX = w * rhs.x + y * rhs.z - z * rhs.y;
	    const float prodY = w * rhs.y + z * rhs.x - x * rhs.z;
	    const float prodZ = w * rhs.z + x * rhs.y - y * rhs.x;
	    const float prodW = -x * rhs.x - y * rhs.y - z * rhs.z;
	    return Vector3(w * prodX - prodY * z + prodZ * y - prodW * x,
	                   w * prodY - prodZ * x + prodX * z - prodW * y,
	                   w * prodZ - prodX * y + prodY * x - prodW * z);
	}
	Quaternion Quaternion::operator*(const Quaternion& rhs) const {
		return Quaternion{
			w * rhs.x + x * rhs.w + y * rhs.z - z * rhs.y,
			w * rhs.y + y * rhs.w + z * rhs.x - x * rhs.z,
			w * rhs.z + z * rhs.w + x * rhs.y - y * rhs.x,
			w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z
		};
	}
	Quaternion Quaternion::operator/(float rhs) const {
		ErrorIf(rhs <= EPSILON, "Quaternion - Division by zero.");
		float reciprocal = 1.0f / rhs;
		return Quaternion{
			x * reciprocal,
			y * reciprocal,
			z * reciprocal,
			w * reciprocal
		};
	}
	void Quaternion::BindLua(sol::state & lua)
	{
		lua.new_usertype<Quaternion>("Quaternion",
			sol::constructors<
			Quaternion(),
			Quaternion(float, float, float, float),
			Quaternion(const Vector3&, float)>(),
	
			"x", &Quaternion::x,
			"y", &Quaternion::y,
			"z", &Quaternion::z,
			"w", &Quaternion::w,
	
			"SetToZero", &Quaternion::SetToZero,
			"Normalize", &Quaternion::Normalize,
			"Normalized", &Quaternion::Normalized,
			"Dot", &Quaternion::Dot,
			"LengthSq", &Quaternion::LengthSq,
			"Length", &Quaternion::Length,
			"Conjugate", &Quaternion::Conjugate,
			"GetConjugated", &Quaternion::GetConjugated,
			"Invert", &Quaternion::Invert,
			"GetInverted", &Quaternion::GetInverted,
			"GetExponent", &Quaternion::GetExponent,
			"GetAxis", &Quaternion::GetAxis,
	
			"EulerToQ", sol::overload(
				static_cast<void (Quaternion::*)(float, float, float)>(&Quaternion::FromEulerAngles),
				static_cast<void (Quaternion::*)(const Vector3&)>(&Quaternion::FromEulerAngles)),
	
			"Degree", &Quaternion::Degree,
			"GetRotatedVector", &Quaternion::GetRotatedVector,
			"Integrate", &Quaternion::Integrate,
			"AddScaledVector", &Quaternion::AddScaledVector,
			sol::meta_function::addition, &Quaternion::operator+,
			sol::meta_function::subtraction, 
	      static_cast<Quaternion(Quaternion::*)(const Quaternion&) const>(&Quaternion::operator-),
			sol::meta_function::multiplication, sol::overload(
				static_cast<Quaternion(Quaternion::*)(float) const>(&Quaternion::operator*),
				static_cast<Quaternion(Quaternion::*)(const Quaternion&) const>(&Quaternion::operator*)
	
			),
			sol::meta_function::division, &Quaternion::operator/,
	    sol::meta_function::unary_minus, 
	      static_cast<Quaternion(Quaternion::*)()const>(&Quaternion::operator-)
			);
	
	
		lua["Quaternion_Identity"] = Identity;
		lua["Quaternion_Slerp"] = Slerp;
		lua["Quaternion_FromToRotation"] = FromToRotation;
		lua["Quaternion_LookRotation"] = LookRotation;
	}
	#else
	Quaternion operator-(const Quaternion& lhs)						   { return Quaternion{ -lhs.x, -lhs.y, -lhs.z, lhs.w }; }
	Quaternion operator-(const Quaternion& lhs, const Quaternion& rhs) { return Quaternion{ lhs.x - rhs.x,	lhs.y - rhs.y,	lhs.z - rhs.z,	lhs.w - rhs.w }; }
	Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs) { return Quaternion{ lhs.x + rhs.x,	lhs.y + rhs.y,	lhs.z + rhs.z,	lhs.w + rhs.w }; }
	Vector3 operator*(const Quaternion& q, const Vector3& rhs) {
		const float prodX = q.w * rhs.x + q.y * rhs.z - q.z * rhs.y;
		const float prodY = q.w * rhs.y + q.z * rhs.x - q.x * rhs.z;
		const float prodZ = q.w * rhs.z + q.x * rhs.y - q.y * rhs.x;
		const float prodW = -q.x * rhs.x - q.y * rhs.y - q.z * rhs.z;
		return Vector3(q.w * prodX - prodY * q.z + prodZ * q.y - prodW * q.x,
			q.w * prodY - prodZ * q.x + prodX * q.z - prodW * q.y,
			q.w * prodZ - prodX * q.y + prodY * q.x - prodW * q.z);
	}
	Quaternion operator*(const Quaternion& lhs, float f)	{ return Quaternion{ lhs.x * f,	lhs.y * f,	lhs.z * f,	lhs.w * f }; }
	Quaternion operator*(const Quaternion& l, const Quaternion& r) {
		return Quaternion{
			l.w * r.x + l.x * r.w + l.y * r.z - l.z * r.y,
			l.w * r.y - l.x * r.z + l.y * r.w + l.z * r.x,
			l.w * r.z + l.x * r.y - l.y * r.x + l.z * r.w,
			l.w * r.w - l.x * r.x - l.y * r.y - l.z * r.z
		};
	}
	Quaternion operator/(const Quaternion& lhs, float rhs) {
		ErrorIf(rhs <= EPSILON, "Quaternion - Division by zero.");
		float reciprocal = 1.0f / rhs;
		return Quaternion{
			lhs.x * reciprocal,
			lhs.y * reciprocal,
			lhs.z * reciprocal,
			lhs.w * reciprocal
		};
	}
	#endif
	
	Quaternion Lerp(const Quaternion& start, const Quaternion& end, float tValue)
	{
	  float alpha = tValue;
	  float oneMinusAlpha = 1.0f - alpha;
	  Quaternion quaternion(start.x * oneMinusAlpha + end.x * alpha,
	                        start.y * oneMinusAlpha + end.y * alpha,
	                        start.z * oneMinusAlpha + end.z * alpha,
	                        start.w * oneMinusAlpha + end.w * alpha);
	
	  return quaternion.Normalized();
	}
	
	Quaternion ToQuaternion(const Matrix44& mat)
	{
	  Quaternion res;
	
	  res.w = sqrt(1.0f + mat.md[0][0] + mat.md[1][1] + mat.md[2][2]) / 2.f;
	  float w4 = 4.f * res.w;
	  res.x = (mat.md[2][1] - mat.md[1][2]) / w4;
	  res.y = (mat.md[0][2] - mat.md[2][0]) / w4;
	  res.z = (mat.md[1][0] - mat.md[0][1]) / w4;
	
	  return res;
	}
	
	std::ostream& operator<<(std::ostream& os, const Quaternion& v) {
		printf("{ %.6f %.6f %.6f %.6f }\n", v.x, v.y, v.z, v.w);
		//os << "{" << v.x << "," << v.y << "," << v.z << "," << v.w << "}\n";
		return os;
	}

} //namespace zg
