#include "test_pmr_room.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "pmr/pmr_Actor.h"
#include "pmr/pmr_Room.h"

namespace test_pmr_room
{
	r2cm::iItem::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Room : Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const pmr::Room r( 2, 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, r.GetWidth() );
				EXPECT_EQ( 2, r.GetHeight() );
				EXPECT_EQ( 4, r.GetSize() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Builder::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Room : Builder";
		};
	}
	r2cm::iItem::DoFunctionT Builder::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( pmr::Room r( 10, 10 ) );
				PROCESS_MAIN( pmr::RoomBuilder( &r ) );

				std::cout << r2cm::linefeed;

				for( int y = 0; r.GetHeight() > y; ++y )
				{
					for( int x = 0; r.GetWidth() > x; ++x )
					{
						std::cout << r.Get( x, y ) << " ";
					}
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Actor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Room : Actor";
		};
	}
	r2cm::iItem::DoFunctionT Actor::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( pmr::Room r( 10, 10 ) );
			PROCESS_MAIN( pmr::RoomBuilder( &r ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( pmr::Actor act( 3, 3 ) );
				EXPECT_TRUE( r.AddActor( &act ) );

				std::cout << r2cm::linefeed;

				for( int y = 0; r.GetHeight() > y; ++y )
				{
					for( int x = 0; r.GetWidth() > x; ++x )
					{
						std::cout << r.Get( x, y ) << " ";
					}
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}