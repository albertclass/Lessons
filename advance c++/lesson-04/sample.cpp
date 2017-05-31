#include "header.h"
#include <cstdlib>


void do_lesson( int rows, int cols )
{
	printw( "ÒÆÎ»²Ù×÷\n" );

	{
		unsigned int i = 0x80000001;

		unsigned int a = i >> 1;
		unsigned int b = i << 1;

		printw( "a = %08X, b = %08X\n", a, b );

		int j = 0x80000001;
		int c = j << 1;
		int d = j >> 1;

		printw( "c = %08X, d = %08X\n", c, d );

		wait_key( 10 );
	}
}
