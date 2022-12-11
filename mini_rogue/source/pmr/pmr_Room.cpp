#include "pmr_Room.h"

#include "pmr_Actor.h"
#include "r2/r2_RectInt.h"

namespace pmr
{
	Room::Room( const uint32_t width, const uint32_t height ) :
		mGrid( width, height, 0 )
		, mActorContainer()
	{}

	bool Room::AddActor( Actor* const actor )
	{
		if( !mGrid.IsIn( actor->GetX(), actor->GetY() ) )
		{
			return false;
		}

		mActorContainer.push_back( actor );

		return true;
	}

	void RoomBuilder( Room* out_room )
	{
		const r2::RectInt rect( 1, 1, static_cast<int>( out_room->GetWidth() ) - 3, static_cast<int>( out_room->GetHeight() ) - 3 );

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