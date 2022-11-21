#pragma once
#include <math.h>

#define PI 3.141592



namespace Nmy
{
	


	struct Vector2
	{

		static Vector2 Zero;
		static Vector2 One;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;


		float x;
		float y;

		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}


		Vector2(const Vector2& other) = default;
		Vector2() = default;
		~Vector2() = default;


		void Clear()
		{
			x = 0.0f;
			y = 0.0f;
		}

		bool operator ==(const Vector2& other)
		{
			return x == other.x && y == other.y;
		}

		bool operator !=(const Vector2& other)
		{
			return x != other.x && y != other.y;
		}

		Vector2 operator-()
		{
			return Vector2(-x, -y);
		}

		Vector2 operator + (const Vector2& other)
		{
			Vector2 temp;
			temp.x = this->x + other.x;
			temp.y = this->y + other.y;
			return temp;
		}

		Vector2 operator /(const float other)
		{
			Vector2 temp;
			temp.x = x / other;
			temp.y = y / other;
			return temp;
		}

		Vector2 operator*(const float& other)
		{
			Vector2 temp;
			temp.x = x * other;
			temp.y = y * other;
			return temp;
		}

		Vector2 operator -(const Vector2& other)
		{
			Vector2 temp;
			temp.x = this->x - other.x;
			temp.y = this->y - other.y;
			return temp;
		}

		void operator +=(const Vector2& other)
		{
			x += other.x;
			y += other.y;
		}

		void operator *=(const float other)
		{
			x *= other;
			y *= other;
		}

		Vector2& operator -=(const Vector2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		float Length()
		{
			return sqrtf(x * x + y * y);
		}

		Vector2& Normalize()
		{
			float len = Length();

			x /= len;
			y /= len;

			return *this;
		}


	};


	namespace math
	{

		inline float DegreeToRadian(float degree)
		{

			return degree * PI / 180.0f;
		}

		inline float RadianToDegree(float radian)
		{

			return radian * (180.0f / PI);
		}

		inline Vector2 Rotate(const Vector2 value , float degree)
		{
			Vector2 ret = Vector2::Zero;
			float radian = DegreeToRadian(degree);

			ret.x = value.x * cosf(radian) - value.y * sinf(radian);
			ret.y = value.x * sinf(radian) + value.y * cosf(radian);
			return ret;
		}

		float Dot(const Vector2& v1, const Vector2& v2)
		{

			return v1.x * v2.x + v1.y * v2.y;
		}



	}
}