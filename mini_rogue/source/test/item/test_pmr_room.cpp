#include "test_pmr_room.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

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
				DECLARATION_MAIN( const pmr::Room r( 2, 2, 0 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, r.GetWidth() );
				EXPECT_EQ( 2, r.GetHeight() );
				EXPECT_EQ( 4, r.GetSize() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}