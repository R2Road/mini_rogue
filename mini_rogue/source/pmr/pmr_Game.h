#pragma once

#include "pmr_Zone.h"

namespace pmr
{
	class Game
	{
	public:
		Game( const uint32_t room_width, const uint32_t room_height );

		const Zone& GetRoom() const
		{
			return mZone;
		}

	private:
		Zone mZone;
	};
}