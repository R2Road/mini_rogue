#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/test_pmr_room.h"
#include "item/test_pmr_stage.h"

r2cm::MenuUp TestMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddItem( '1', test_pmr_room::Declaration() );
		ret->AddItem( '2', test_pmr_room::Builder() );



		ret->AddLineFeed();



		ret->AddItem( 'q', test_pmr_stage::Declaration() );



		ret->AddSplit();



		ret->AddItem(
			27
			, r2cm::eColor::FG_White
			, []()->const char* { return "Exit"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				return r2cm::eItemLeaveAction::Exit;
			}
		);
	}

	return ret;
}