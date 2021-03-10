#include "NoopStream.h"

size_t NoopStream::write(uint8_t uint8)
{
	return 0;
}

int NoopStream::available()
{
	return 0;
}

int NoopStream::read()
{
	return 0;
}

int NoopStream::peek()
{
	return 0;
}
