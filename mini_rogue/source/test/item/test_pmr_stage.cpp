#include "test_pmr_stage.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "pmr/pmr_Stage.h"

namespace test_pmr_stage
{
	r2cm::iItem::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const pmr::Stage s( 2, 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, s.GetRoom().GetWidth() );
				EXPECT_EQ( 2, s.GetRoom().GetHeight() );
				EXPECT_EQ( 4, s.GetRoom().GetSize() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}