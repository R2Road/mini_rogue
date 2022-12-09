#include "pmr_Stage.h"

namespace pmr
{
	Stage::Stage( const uint32_t room_width, const uint32_t room_height ) :
		mRoom( room_width, room_height, 0 )
	{}
}