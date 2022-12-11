#include "pmr_Room.h"

#include "r2/r2_RectInt.h"

namespace pmr
{
	void RoomBuilder( Room* out_room )
	{
		const r2::RectInt rect( 1, 1, out_room->GetWidth() - 3, out_room->GetHeight() - 3 );

		for( int y = 0; out_room->GetHeight() > y; ++y )
		{
			for( int x = 0; out_room->GetWidth() > x; ++x )
			{
				if( rect.ContainsPoint( x, y ) )
				{
					out_room->Set( x, y, 0 );
				}
				else
				{
					out_room->Set( x, y, 1 );
				}
			}
		}
	}
}