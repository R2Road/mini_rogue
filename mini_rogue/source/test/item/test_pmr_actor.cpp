#include "test_pmr_actor.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "pmr/pmr_Actor.h"

namespace test_pmr_actor
{
	std::ostream& operator<<( std::ostream& o, r2::PointUint p )
	{
		return o << "x : " << p.GetX() << "y : " << p.GetY() << r2cm::linefeed;
	}

	r2cm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Actor : Declaration";
		};
	}
	r2cm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const pmr::Actor act( 1, 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, act.GetPoint().GetX() );
				EXPECT_EQ( 2, act.GetPoint().GetY() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( act.GetPoint().GetX(), act.GetX() );
				EXPECT_EQ( act.GetPoint().GetY(), act.GetY() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Point::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Actor : Point";
		};
	}
	r2cm::DoFunctionT Point::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( pmr::Actor act( 1, 2 ) );
			EXPECT_EQ( r2::PointUint( 1, 2 ), act.GetPoint() );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( act.SetPoint( 4, 5 ) );
				EXPECT_EQ( r2::PointUint( 4, 5 ), act.GetPoint() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( act.SetX( 7 ) );
				EXPECT_EQ( 7, act.GetX() );
				PROCESS_MAIN( act.SetY( 9 ) );
				EXPECT_EQ( 9, act.GetY() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}