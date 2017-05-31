#include "header.h"
#include <cstdlib>


void do_lesson( int rows, int cols )
{
	printw( "��ֵ�Ƚ�\n" );

	addstr( "\n----------------------\n" );
	{
		addstr( "�з������Ƚ��з�����\n" );
		int32_t n = 65535;
		int16_t m = 65535;
		
		printw( "n = %11d, hex(%08x)\n", n, n );
		printw( "m = %11d, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�з������Ƚ��޷�����\n" );
		 int32_t n = -1;
		uint16_t m = -1;

		printw( "n = %11d, hex(%08x)\n", n, n );
		printw( "m = %11d, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�з������Ƚ�����ֵ 1\n" );
		int16_t n = -1;

		printw( "n = %11d, hex(%08x)\n", n, n );

		printw( "n %c -1\n", n > -1 ? '>' : ( n < -1 ? '<' : '=' ) );
		printw( "-1 %c n\n", -1 > n ? '>' : ( -1 < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	{
		addstr( "�з������Ƚ�����ֵ 2\n" );
		int16_t n = -1;

		printw( "n = %11d, hex(%08x)\n", n, n );

		printw( "n %c 65537\n", n > 65537 ? '>' : ( n < 65537 ? '<' : '=' ) );
		printw( "65537 %c n\n", 65537 > n ? '>' : ( 65537 < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�޷������Ƚ�����ֵ 1\n" );
		uint16_t n = -1;

		printw( "n = %11d, hex(%08x)\n", n, n );

		printw( "n %c -1\n", n > -1 ? '>' : ( n < -1 ? '<' : '=' ) );
		printw( "-1 %c n\n", -1 > n ? '>' : ( -1 < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	{
		addstr( "�޷������Ƚ�����ֵ 2\n" );
		uint16_t n = -1;

		printw( "n = %11d, hex(%08x)\n", n, n );

		printw( "n %c 65537\n", n > 65537 ? '>' : ( n < 65537 ? '<' : '=' ) );
		printw( "65537 %c n\n", 65537 > n ? '>' : ( 65537 < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�������Ƚϸ�����\n" );
		float n = 1024.0000023f;
		float m = 1024.0000024f;

		printw( "n = %11f, hex(%08x)\n", n, n );
		printw( "m = %11f, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�������Ƚϸ�����\n" );
		float n = 1024.0000023f;
		float m = 1024.0000024f;

		printw( "n = %11f, hex(%08x)\n", n, n );
		printw( "m = %11f, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	union ServerID
	{
		struct
		{
			uint32_t area : 4;
			uint32_t group : 4;
			uint32_t type : 3;
			uint32_t index : 5;
		};

		uint32_t val;
	};


}
