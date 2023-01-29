#pragma once

namespace pmr
{

	//
	// 2022.05.06 by R
	//
	// �������� �ʰ� ��̰� �۾��� �̾�� �� �ֵ��� ��� ����� ������ ��.
	//

	static struct
	{

		const char VersionNumber_1 = '0';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '0';
		const char VersionNumber_4 = '0';

		const char* const String4VersionRule = {
					"### Version Rule ###"
			"\n"
			"\n"	"> " "1.0.0.0"  " : "  "���"
			"\n"	"> " "0.1.0.0"  " : "  "10���� Road ���� 1�� ����"
			"\n"	"> " "0.0.1.0"  " : "  "Road �� �����ߴ�."
			"\n"	"> " "0.0.0.1"  " : "  "������ ������ �־���."
		};

		const char String4Version[21] = { 'M', 'i', 'n', 'i', 'R', 'o', 'g', 'u', 'e', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '.', VersionNumber_4, '\0' };



		const char* const String4DevelopementRule = {
					"### Game ����( ���� �ܼ��� ������� ����� ) ###"
			"\n"
			"\n"	"> " "Game               "  " : "  "���� ũ�� ���� ����( 1�� ~ N�� )"
			"\n"	"> " "Zone               "  " : "  "10 x 10"
			"\n"	"> " "Turn               "  " : "  "�� ���Ͱ� ���ư��鼭 1ȸ�� ����"
			"\n"	"> " "Actor[ Move ]      "  " : "  "4���� ����"
			"\n"	"> " "Actor[ Interaction]"  " : "  "8���� ����"
		};



		const char* const String4Road2Version_0_0_1_0 = {
					"### Road 2 Version 0.0.1.0 ###"
			"\n"
			"\n"	"[o] " "Zone"
			"\n"	"    " "[o] " "Add Type : Zone"
			"\n"	"    " "[o] " "Member : Terrain"
			"\n"	"    " "[o] " "Member : Actor Container"
			"\n"	"    " "[o] " "Function : Add Actor"
			"\n"	"[o] " "Terrain"
			"\n"	"    " "[o] " "Add Type : Terrain"
			"\n"	"    " "[o] " "Member : Grid"
			"\n"	"    " "[o] " "Function : Grid Build : 10 x 10, ���� �ѷ��� ��"
			"\n"	"[ ] " "Actor"
			"\n"	"    " "[o] " "Add Type : Actor"
			"\n"	"    " "[ ] " "AI : Move"
			"\n"	"    " "[ ] " "AI : Interaction Between Actor 2 Actor"
			"\n"	"[ ] " "Add System : AI Base( fsm? b-tree? )"
			"\n"	"[ ] " "Add System : Statistics"
		};

		const char* const String4Road2Version_0_0_0_0 = {
			"### Road 2 Version 0.0.0.0 ###"
			"\n"
			"\n"	"[o] " "Make Project"
			"\n"	"[o] " "Cleanup"
		};

	} VersionInfo;
}