#pragma once

#include "r2/r2_Grid.h"

namespace pmr
{
	using Tile = int;
	using Room = r2::Grid<Tile>;

	void RoomBuilder( Room* out_room );
}