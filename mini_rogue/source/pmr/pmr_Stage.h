#pragma once

#include "r2/r2_Grid.h"

namespace pmr
{
	class Stage
	{
	private:
		using Tile = int;
		using Room = r2::Grid<Tile>;

	public:
		Stage( const uint32_t room_width, const uint32_t room_height );

		const Room& GetRoom() const
		{
			return mRoom;
		}

	private:
		Room mRoom;
	};
}