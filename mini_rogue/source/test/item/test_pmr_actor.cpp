#include "test_pmr_actor.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "pmr/pmr_Actor.h"

namespace test_pmr_actor
{
	r2cm::iItem::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Actor : Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
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

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}