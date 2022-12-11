#include "pmr_Game.h"

namespace pmr
{
	Game::Game( const uint32_t room_width, const uint32_t room_height ) :
		mRoom( room_width, room_height, 0 )
	{}
}