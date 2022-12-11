#pragma once

#include "r2/r2_PointUint.h"

namespace pmr
{
	class Actor
	{
	public:
		Actor( const uint32_t x, const uint32_t y );

		//
		// Getter
		//
		const r2::PointUint& GetPoint() const
		{
			return mPoint;
		}

	private:
		r2::PointUint mPoint;
	};
}