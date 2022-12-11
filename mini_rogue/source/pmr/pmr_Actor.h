#pragma once

#include "r2/r2_PointUint.h"

namespace pmr
{
	class Actor
	{
	public:
		using Point = r2::PointUint;

		Actor( const uint32_t x, const uint32_t y );

		//
		// Getter
		//
		const r2::PointUint& GetPoint() const
		{
			return mPoint;
		}
		Point::ValueT GetX() const
		{
			return mPoint.GetX();
		}
		Point::ValueT GetY() const
		{
			return mPoint.GetY();
		}

	private:
		r2::PointUint mPoint;
	};
}