#pragma once

#include <Stream.h>

/**
 * Dummy Stream implementation.
 */
class NoopStream : public Stream
{
public:
	size_t write(uint8_t uint8) override;
	int available() override;
	int read() override;
	int peek() override;
};


