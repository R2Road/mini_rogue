#pragma once

#include "pmr_Room.h"

namespace pmr
{
	class Stage
	{
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