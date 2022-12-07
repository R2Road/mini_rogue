#pragma once

#include "r2/r2_SingletonWithStaticVariable.h"
#include "r2bix/r2base_TextureTableBase.h"

namespace pmr
{
	class TextureTable : public r2base::TextureTableBase, public r2::SingletonWithStaticVariable<TextureTable>
	{
	public:
		void Load() override;
	};
}