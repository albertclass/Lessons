#include "header.h"
#include <cstdlib>



void do_lesson( int rows, int cols )
{
	addstr( "数值转换\n" );

	addstr( "\n----------------------\n" );
	{
		addstr( "数据上溢\n" );
		int n = 65535;
		short s = (short)n;

		printw( "n = %11d, hex(%08x)\n", n, n );
		printw( "s = %11d, hex(%08x)\n", s, s );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "数据下溢1\n" );
		int n = -65537;
		short s = (short)n;

		printw( "n = %11d, hex(%08x)\n", n, n );
		printw( "s = %11d, hex(%08x)\n", s, s );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "数据下溢2\n" );
		int n = 0x80007fff;
		short s = (short)n;

		printw( "n = %11d, hex(%08x)\n", n, n );
		printw( "s = %11d, hex(%08x)\n", s, s );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "数据溢出 - 无符号转有符号\n" );
		uint32_t n = 0x80000000;
		 int32_t s = n;

		printw( "n = %11u, hex(%08x)\n", n, n );
		printw( "s = %11d, hex(%08x)\n", s, s );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "数据溢出 - 单精度转整型\n" );
		float n = 4294967295 - 128;
		uint32_t s = n;

		printw( "n = %f, hex(%08x)\n", n, *(uint32_t*)&n );
		printw( "s = %11u, hex(%08x)\n", s, s );
		wait_key( 13 );
	}

}
