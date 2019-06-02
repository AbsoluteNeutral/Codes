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
	
		//____________________________________________________________ constructor
		Quaternion					() noexcept;
		Quaternion					(float x_, float y_, float z_, float w_) noexcept;
		Quaternion					(const Vector3& axis_, float degree_) noexcept;
	
		// ____________________________________________________________ setters
		void	AddScaledVector		(const Vector3& vector_, float f_);
		void	Conjugate			();
		void	Integrate			(const Vector3& vector_, float f_);
		void	Invert				();
		float	Normalize			();
		void	Set					(float x_, float y_, float z_, float w_);
		void	SetFromEulerAngles	(float RADIAN_x, float RADIAN_y, float RADIAN_z);
		void	SetFromEulerAngles	(const Vector3& degree_);

		// ____________________________________________________________ getters 
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

		// ____________________________________________________________ static
		static Quaternion Identity;
		static Vector3 ToEularDegree		(const Quaternion& q);
		static Quaternion FromEulerAngles	(float RADIAN_x, float RADIAN_y, float RADIAN_z);
		static Quaternion FromEulerAngles	(const Vector3& DEGREE_);
		static Quaternion Slerp				(const Quaternion& quaternion1, const Quaternion& quaternion2, float t);
		static Quaternion FromToRotation	(const Vector3& fromVector, const Vector3& toVector);
		static Quaternion LookRotation		(const Vector3& forward, const Vector3& upwards, const Vector3& front);
	
		// ____________________________________________________________ operator
		bool operator==			(const Quaternion& q2_)	const;

		Quaternion& operator-=	(const Quaternion& q2_);
		Quaternion& operator+=	(const Quaternion& q2_);
		Quaternion& operator*=	(float f_);
		Quaternion& operator*=	(const Quaternion& q2_);
		Quaternion& operator/=	(float f_);
		
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
		ZG_API friend Quaternion operator-(const Quaternion& q1_);
		ZG_API friend Quaternion operator-(const Quaternion& q1_, const Quaternion& q2_);
		ZG_API friend Quaternion operator+(const Quaternion& q1_, const Quaternion& q2_);
		ZG_API friend Quaternion operator*(const Quaternion& q1_, float f_);
		ZG_API friend Quaternion operator*(float f_, const Quaternion& q1_);
		ZG_API friend Vector3	 operator*(const Quaternion& q1_, const Vector3& v_);
		ZG_API friend Vector3	 operator*(const Vector3& v_, const Quaternion& q1_);
		ZG_API friend Quaternion operator*(const Quaternion& q1_, const Quaternion& q2_);
	#endif
		ZG_API friend std::ostream& operator<<(std::ostream& os, const Quaternion& v_);
	
	private:
		
	};
	Quaternion operator/(const Quaternion& lhs, float rhs);
	ZG_API Quaternion Lerp(const Quaternion& start_, const Quaternion& end_, float time_);
	ZG_API Quaternion ToQuaternion(const Matrix44& rot_matrix_);

} //namespace zg

#endif //_QUATERNION_H

