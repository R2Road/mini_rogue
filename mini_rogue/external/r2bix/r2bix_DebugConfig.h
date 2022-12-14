#pragma once

namespace r2bix
{
	class DebugConfig
	{
	public:
		struct LabelConfig
		{
			bool bShowPositionPivot = false;
		};

	private:
		DebugConfig() = default;

	public:
		static const LabelConfig& GetLabelConfig() { return instance.mLabelConfig; }

	private:
		static DebugConfig instance;

		LabelConfig mLabelConfig;
	};
}