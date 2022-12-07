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

		const char String4Version[19] = { 'M', 'i', 'n', 'i', 'R', 'o', 'g', 'u', 'e', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };


		const char* const String4Road2Version_0_0_1 = {
			"### Road 2 Version 0.0.1 ###"
			"\n"
			"\n"	"[ ] " "Make Empty Stage"
			"\n"	"[ ] " "Make PC"
			"\n"	"[ ] " "Move PC"
			"\n"	"[ ] " "Make Dummy Object"
			"\n"	"[ ] " "Add Statistics System"
			"\n"	"[ ] " "Interaction PC to Dummy Object : Attack"
		};

		const char* const String4Road2Version_0_0_0 = {
			"### Road 2 Version 0.0.0 ###"
			"\n"
			"\n"	"[o] " "Make Project"
			"\n"	"[o] " "Cleanup"
		};

	} VersionInfo;
}