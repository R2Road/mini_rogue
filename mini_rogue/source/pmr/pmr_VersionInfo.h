#pragma once

namespace pmr
{

	//
	// 2022.05.06 by R
	//
	// 무리하지 않고 즐겁게 작업을 이어나갈 수 있도록 모든 방안을 강구할 것.
	//

	static struct
	{

		const char VersionNumber_1 = '0';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '0';
		const char VersionNumber_4 = '0';

		const char String4Version[21] = { 'M', 'i', 'n', 'i', 'R', 'o', 'g', 'u', 'e', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '.', VersionNumber_4, '\0' };


		const char* const String4Road2Version_0_0_1 = {
					"### Version Rule ###"
			"\n"
			"\n"	"> " "1.0.0.0" " : "	"출시"
			"\n"	"> " "0.1.0.0" " : "	"10개의 Road 마다 1씩 증가"
			"\n"	"> " "0.0.1.0" " : "	"Road 를 완주했다."
			"\n"	"> " "0.0.0.1" " : "	"자잘한 수정이 있었다."
			"\n"
			"\n"
			"\n"	"### Game 구성( 가장 단순한 방식으로 만든다 ) ###"
			"\n"
			"\n"	"> " "Stage" "\t" " : "	"같은 크기 방들( 1개 ~ N개 )"
			"\n"	"> " "Turn"	 "\t" " : "	"각 액터가 돌아가면서 1회씩 수행"
			"\n"
			"\n"
			"\n"	"### Road 2 Version 0.0.1.0 ###"
			"\n"
			"\n"	"[o] " "Make Empty Room : 10 x 10, 방을 둘러싼 벽"
			"\n"	"[o] " "Make PC"
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