/*****************************************************************************/
/*!
\file		Quaternion.h
\brief		Quaternion Implmentation
Uploaded: 18 May 2019
*/
/*****************************************************************************/
#ifndef _QUATERNION_H
#define _QUATERNION_H

#include "Vector3.hpp"

namespace zg {
	class Matrix33;
	class Matrix44;

	class ZG_API Quaternion
	{
	public:
		float x, y, z, w;
	
		//constructor
		Quaternion() noexcept;
		Quaternion(float x_, float y_, float z_, float w_);
		Quaternion(const Vector3& v, float angle);
	
		//setters
		void	AddScaledVector		(const Vector3& vector, float scale);
		void	Conjugate			();
		void	Integrate			(const Vector3& vector, float scalar);
		void	Invert				();
		float	Normalize			();
		void	Set					(float x_, float y_, float z_, float w_);
		void	SetFromEulerAngles	(float RADIAN_x, float RADIAN_y, float RADIAN_z);
		void	SetFromEulerAngles	(const Vector3& DEGREE_);
		//getters const 
		float		Dot					(const Quaternion& rhs) const;
		Vector3		GetAxis				()						const;
		Quaternion	GetRotationAngleAxis(float& angle, Vector3& axis) const;
		Quaternion	GetConjugated		()						const;
		Quaternion  GetExponent			()						const;
		Quaternion  GetInverted			()						const;
		Matrix33	GetMatrix33			()						const;
		Matrix44	GetMatrix44			()						const;
		Quaternion	Normalized			()						const;
		Vector3		GetRotatedVector	(const Vector3& v)		const;
		Vector3		GetVector3			()						const;
		float		LengthSq			()						const;
		float		Length				()						const;
		Vector3		ToEularDegree		()						const;
		//static
		static Quaternion Identity;
	
		static Vector3 ToEularDegree		(const Quaternion& q);
		static Quaternion FromEulerAngles	(float RADIAN_x, float RADIAN_y, float RADIAN_z);
		static Quaternion FromEulerAngles	(const Vector3& DEGREE_);
		static Quaternion Slerp				(const Quaternion& quaternion1, const Quaternion& quaternion2, float t);
		static Quaternion FromToRotation	(const Vector3& fromVector, const Vector3& toVector);
		static Quaternion LookRotation		(const Vector3& forward, const Vector3& upwards, const Vector3& front);
	
		//operator
		Quaternion& operator-=	(const Quaternion& rhs);
		Quaternion& operator+=	(const Quaternion& rhs);
		Quaternion& operator*=	(float rhs);
		Quaternion& operator*=	(const Quaternion& rhs);
		Quaternion& operator/=	(float rhs);
		bool operator==			(const Quaternion &r)	const;
	#ifdef USING_SOL2
		Quaternion operator-()				const;
		Quaternion operator-	(const Quaternion& rhs) const;
		Quaternion operator+	(const Quaternion& rhs) const;
		Quaternion operator*	(float rhs)				const;
		Vector3	   operator*	(const Vector3& rhs)	const;
		Quaternion operator*	(const Quaternion& rhs) const;
		Quaternion operator/	(float rhs)				const;
		static void BindLua(sol::state& lua);
	#else
		ZG_API friend Quaternion operator-(const Quaternion& lhs);
		ZG_API friend Quaternion operator-(const Quaternion& lhs, const Quaternion& rhs);
		ZG_API friend Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs);
		ZG_API friend Quaternion operator*(const Quaternion& lhs, float f);
		ZG_API friend Vector3	operator*(const Quaternion& lhs, const Vector3& v);
		ZG_API friend Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs);
	#endif
		ZG_API friend std::ostream& operator<<(std::ostream& os, const Quaternion& v);
	
	private:
		
	};
	Quaternion operator/(const Quaternion& lhs, float rhs);
	ZG_API Quaternion Lerp(const Quaternion& start, const Quaternion& end, float tValue);
	ZG_API Quaternion ToQuaternion(const Matrix44& mat);

} //namespace zg

#endif //_QUATERNION_H

