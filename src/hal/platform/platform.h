#pragma once

#include <Stream.h>

namespace hal
{
	namespace platform
	{
		class Platform
		{
		public:
			Platform(Stream* raSerial, Stream* decSerial, Stream* altSerial = nullptr);

			Stream* getSerial(uint8_t rx, uint8_t tx, bool invertLogic = false);
		private:
			Stream* mRaSerial;
			Stream* mDecSerial;
			Stream* mAltSerial;
		};
	}
}


