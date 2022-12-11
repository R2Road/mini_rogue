#pragma once

#include "pmr_Room.h"

namespace pmr
{
	class Game
	{
	public:
		Game( const uint32_t room_width, const uint32_t room_height );

		const Room& GetRoom() const
		{
			return mRoom;
		}

	private:
		Room mRoom;
	};
}