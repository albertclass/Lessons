#include "header.h"

void do_lesson( int rows, int cols )
{
    printw( "C++ tpyes!\n\n" );

	{
		int32_t i = 0xc0271eb5;

		char hex[128];
		bin2hex( (char*) &i, sizeof( i ), hex, sizeof( hex ), 0 );
		printw( "LE - HEX : %08x, DEC : %u\n", i, i );
		addstr( "------\n" );
		printw( "%s", hex );
		addstr( "------\n" );

		wait_key( 10 );
	}

	addch( '\n' );

	{
		int32_t i = 0xb51e27c0;

		char hex[128];
		bin2hex( (char*)&i, sizeof(i), hex, sizeof(hex), 0 );
		printw( "BE - HEX : %08x, DEC : %u\n", i, i );
		addstr( "------\n" );
		printw( "%s", hex );
		addstr( "------\n" );

		wait_key( 10 );
	}

}