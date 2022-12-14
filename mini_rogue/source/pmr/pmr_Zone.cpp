#include "pmr_Zone.h"

#include "pmr_Actor.h"
#include "r2/r2_RectInt.h"

namespace pmr
{
	Zone::Zone( const uint32_t width, const uint32_t height ) :
		mTerrain( width, height, Tile::Empty )
		, mActorContainer()
	{}

	bool Zone::AddActor( Actor* const actor )
	{
		//
		// 범위 확인
		//
		if( !mTerrain.IsIn( actor->GetX(), actor->GetY() ) )
		{
			return false;
		}

		//
		// Tile 확인
		//
		if( Tile::Wall == mTerrain.Get( actor->GetX(), actor->GetY() ) )
		{
			return false;
		}

		//
		// 겹치는 Actor 확인
		//
		for( const auto a : mActorContainer )
		{
			if( a->GetPoint() == actor->GetPoint() )
			{
				return false;
			}
		}

		mActorContainer.push_back( actor );

		return true;
	}

	void RoomBuilder( Zone* out_room )
	{
		const r2::RectInt rect( 1, 1, static_cast<int>( out_room->GetWidth() ) - 3, static_cast<int>( out_room->GetHeight() ) - 3 );

		for( int y = 0; out_room->GetHeight() > y; ++y )
		{
			for( int x = 0; out_room->GetWidth() > x; ++x )
			{
				if( rect.ContainsPoint( x, y ) )
				{
					out_room->SetTile( x, y, Tile::Empty );
				}
				else
				{
					out_room->SetTile( x, y, Tile::Wall );
				}
			}
		}
	}
}