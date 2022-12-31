#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/test_pmr_actor.h"
#include "item/test_pmr_demo.h"
#include "item/test_pmr_game.h"
#include "item/test_pmr_zone.h"

r2cm::TitleFunctionT TestMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Test Menu";
	};
}
r2cm::DescriptionFunctionT TestMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2cm::WriteFunctionT TestMenu::GetWriteFunction() const
{
	return []( r2cm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_pmr_actor::Declaration() );
		ret->AddItem( '2', test_pmr_actor::Point() );



		ret->AddLineFeed();



		ret->AddItem( '5', test_pmr_zone::Declaration() );
		ret->AddItem( '6', test_pmr_zone::Builder() );
		ret->AddItem( '7', test_pmr_zone::Actor() );
		ret->AddItem( '8', test_pmr_zone::Demo() );



		ret->AddLineFeed();



		ret->AddItem( 'q', test_pmr_game::Declaration() );



		ret->AddLineFeed();



		ret->AddItem( 32, test_pmr_demo::Basic() );



		ret->AddSplit();



		ret->AddItem(
			27
			, r2cm::eColor::BG_Purple
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eDoLeaveAction
			{
				return r2cm::eDoLeaveAction::Exit;
			}
		);
	};
}