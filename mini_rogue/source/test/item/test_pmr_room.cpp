#include "test_pmr_room.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "pmr/pmr_Actor.h"
#include "pmr/pmr_Room.h"

namespace test_pmr_room
{
	std::ostream& operator<<( std::ostream& o, pmr::Tile t )
	{
		return o << static_cast<int>( t );
	}

	void PrintRoom( const pmr::Room& r )
	{
		const auto pivot = r2cm::WindowUtility::GetCursorPoint();

		for( int y = 0; r.GetHeight() > y; ++y )
		{
			for( int x = 0; r.GetWidth() > x; ++x )
			{
				std::cout << r.Get( x, y ) << " ";
			}
			std::cout << r2cm::linefeed;
		}

		for( const auto& a : r.GetActorContainer() )
		{
			r2cm::WindowUtility::MoveCursorPoint( { ( pivot.x + (short)a->GetX() ) * 2, pivot.y + (short)a->GetY() } );
			std::cout << r2cm::clm( r2cm::eColor::BG_Blue ) << r2cm::clm( r2cm::eColor::FG_Yellow ) << "A" << r2cm::clm();
		}

		r2cm::WindowUtility::MoveCursorPoint( { 0, pivot.y + (short)r.GetHeight() } );
	}

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
				OUTPUT_NOTE( "기본" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( pmr::Actor a_1( 3, 3 ) );
				EXPECT_TRUE( r.AddActor( &a_1 ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "겹쳐지나?" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( pmr::Actor a_2( 3, 3 ) );
				EXPECT_FALSE( r.AddActor( &a_2 ) );

			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "범위 확인" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( pmr::Actor a_3( static_cast<pmr::Actor::Point::ValueT>( r.GetWidth() ), static_cast<pmr::Actor::Point::ValueT>( r.GetHeight() ) ) );
				EXPECT_FALSE( r.AddActor( &a_3 ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "타일 확인" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( pmr::Actor a_4( 0, 0 ) );
				EXPECT_FALSE( r.AddActor( &a_4 ) );
			}

			std::cout << r2cm::split;

			{
				PrintRoom( r );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}