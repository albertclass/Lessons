#include "header.h"
#include <cstdlib>



void do_lesson( int rows, int cols )
{
	addstr( "��ֵת��\n" );

	addstr( "\n----------------------\n" );
	{
		addstr( "��������\n" );
		int n = 65536;
		short s = (short)n;

		printw( "n = %11d, hex(%08x)\n", n, n );
		printw( "s = %11d, hex(%08x)\n", s, s );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "��������\n" );
		int n = -65536;
		short s = (short)n;

		printw( "n = %11d, hex(%08x)\n", n, n );
		printw( "s = %11d, hex(%08x)\n", s, s );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "������� - �޷���ת�з���\n" );
		uint32_t n = 0x80000000;
		 int32_t s = n;

		printw( "n = %11u, hex(%08x)\n", n, n );
		printw( "s = %11d, hex(%08x)\n", s, s );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "������� - ������ת����\n" );
		float n = 4294967295 - 128;
		uint32_t s = n;

		printw( "n = %f, hex(%08x)\n", n, *(uint32_t*)&n );
		printw( "s = %11u, hex(%08x)\n", s, s );
		wait_key( 13 );
	}

}
