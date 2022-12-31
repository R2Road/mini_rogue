#include "test_pmr_zone.h"

#include <conio.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "pmr/pmr_Actor.h"
#include "pmr/pmr_Zone.h"

namespace test_pmr_zone
{
	std::ostream& operator<<( std::ostream& o, pmr::Tile t )
	{
		return o << static_cast<int>( t );
	}

	void PrintRoom( const pmr::Zone& z )
	{
		const auto pivot = r2cm::WindowUtility::GetCursorPoint();

		for( int y = 0; z.GetHeight() > y; ++y )
		{
			for( int x = 0; z.GetWidth() > x; ++x )
			{
				std::cout << z.GetTile( x, y ) << " ";
			}
			std::cout << r2cm::linefeed;
		}

		for( const auto& a : z.GetActorContainer() )
		{
			r2cm::WindowUtility::MoveCursorPoint( { ( pivot.x + (short)a->GetX() ) * 2, pivot.y + (short)a->GetY() } );
			std::cout << clm( r2cm::eColor::BG_Blue ) << clm( r2cm::eColor::FG_Yellow ) << "A" << clm();
		}

		r2cm::WindowUtility::MoveCursorPoint( { 0, pivot.y + (short)z.GetHeight() } );
	}

	r2cm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Zone : Declaration";
		};
	}
	r2cm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const pmr::Zone z( 2, 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, z.GetWidth() );
				EXPECT_EQ( 2, z.GetHeight() );
				EXPECT_EQ( 4, z.GetSize() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Builder::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Zone : Builder";
		};
	}
	r2cm::DoFunctionT Builder::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( pmr::Zone z( 10, 10 ) );
				PROCESS_MAIN( pmr::RoomBuilder( &z ) );

				std::cout << r2cm::linefeed;

				for( int y = 0; z.GetHeight() > y; ++y )
				{
					for( int x = 0; z.GetWidth() > x; ++x )
					{
						std::cout << z.GetTile( x, y ) << " ";
					}
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Actor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Zone : Actor";
		};
	}
	r2cm::DoFunctionT Actor::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( pmr::Zone z( 10, 10 ) );
			PROCESS_MAIN( pmr::RoomBuilder( &z ) );

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "기본" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( pmr::Actor a_1( 3, 3 ) );
				EXPECT_TRUE( z.AddActor( &a_1 ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "겹쳐지나?" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( pmr::Actor a_2( 3, 3 ) );
				EXPECT_FALSE( z.AddActor( &a_2 ) );

			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "범위 확인" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( pmr::Actor a_3( static_cast<pmr::Actor::Point::ValueT>( z.GetWidth() ), static_cast<pmr::Actor::Point::ValueT>( z.GetHeight() ) ) );
				EXPECT_FALSE( z.AddActor( &a_3 ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "타일 확인" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( pmr::Actor a_4( 0, 0 ) );
				EXPECT_FALSE( z.AddActor( &a_4 ) );
			}

			std::cout << r2cm::split;

			{
				PrintRoom( z );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Demo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Zone : Demo";
		};
	}
	r2cm::DoFunctionT Demo::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( pmr::Zone z( 10, 10 ) );
			PROCESS_MAIN( pmr::RoomBuilder( &z ) );

			std::cout << r2cm::linefeed;

			DECLARATION_MAIN( pmr::Actor a_1( 3, 3 ) );
			EXPECT_TRUE( z.AddActor( &a_1 ) );

			std::cout << r2cm::linefeed;

			DECLARATION_MAIN( pmr::Actor a_2( 5, 5 ) );
			EXPECT_TRUE( z.AddActor( &a_2 ) );

			std::cout << r2cm::split;

			{
				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
				int input = 0;

				do
				{
					switch( input )
					{
						//
						// Arrow
						//
					case 'w':
						break;
					case 'a':
						break;
					case 's':
						break;
					case 'd':
						break;

						//
						//
						//


					default:
						break;
					}

					//
					// View
					//
					r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );
					PrintRoom( z );

					//
					// Input
					//
					input = _getch();

				} while( 27 != input );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}