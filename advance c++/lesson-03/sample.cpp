#include "header.h"
#include <cstdlib>


void do_lesson( int rows, int cols )
{
	printw( "数值比较\n" );
	wait_key( 13 );

	addstr( "\n----------------------\n" );
	{
		addstr( "有符号数比较有符号数, n = -1, m = 32768\n" );
		int32_t n = -1;
		int16_t m = 32768;
		
		{
			// ERROR 数据溢出了
		}

		printw( "int32_t n = %11d, hex(%08x)\n", n, n );
		printw( "int16_t m = %11d, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );

		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "有符号数比较无符号数\n" );
		 int32_t n = -1;
		uint32_t m = -1;

		{
			// ERROR 数据下溢
		}
		printw( " int32_t n = %11d, hex(%08x)\n", n, n );
		printw( "uint32_t m = %11d, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "无符号数比较字面值\n" );
		uint32_t n = 0;

		printw( "uint32_t n = %11u, hex(%08x)\n", n, n );

		{
			// ERROR 数据先转换为无符号数，再比较
		}

		printw( "n %c -1\n", n > -1 ? '>' : ( n < -1 ? '<' : '=' ) );
		printw( "-1 %c n\n", -1 > n ? '>' : ( -1 < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "浮点数比较浮点数\n" );
		float n = 1024.000025f;
		float m = 1024.000024f;

		{
			// 精度问题
		}
		printw( "n = %11f, hex(%08x)\n", n, n );
		printw( "m = %11f, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "浮点数比较浮点数\n" );
		float n = 0.000012f;
		float m = 1.0f / 80000.0f;
		
		{
			/// 浮点数精度问题
		}
		printw( "n = %11f, hex(%08x)\n", n, n );
		printw( "m = %11f, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}
}
