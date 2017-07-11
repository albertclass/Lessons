#include "header.h"
#include <cstdlib>


void do_lesson( int rows, int cols )
{
	printf( "数值比较\n" );
	wait_key( 13 );

	puts( "\n----------------------\n" );
	{
		puts( "有符号数比较有符号数, n = -1, m = 32768\n" );
		int32_t n = -1;
		int16_t m = 32768;
		
		{
			// ERROR 数据溢出了
		}

		printf( "int32_t n = %11d, hex(%08x)\n", n, n );
		printf( "int16_t m = %11d, hex(%08x)\n", m, m );

		printf( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printf( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );

		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	{
		puts( "有符号数比较无符号数\n" );
		 int32_t n = -1;
		uint32_t m = 4294900000;

		{
			// ERROR 数据下溢
		}
		printf( " int32_t n = %11d, hex(%08x)\n", n, n );
		printf( "uint32_t m = %11u, hex(%08x)\n", m, m );

		printf( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printf( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	{
		puts( "无符号数比较字面值\n" );
		uint32_t n = 0;

		printf( "uint32_t n = %11u, hex(%08x)\n", n, n );

		{
			// ERROR 数据先转换为无符号数，再比较
		}

		printf( "n %c -1\n", n > -1 ? '>' : ( n < -1 ? '<' : '=' ) );
		printf( "-1 %c n\n", -1 > n ? '>' : ( -1 < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	{
		puts( "浮点数比较浮点数 - 精度问题（看代码）\n" );
		float n = 1024.000025f;
		float m = 1024.000024f;

		{
			// 精度问题
		}
		printf( "n = %11f, hex(%08x)\n", n, *((uint32_t*)&n) );
		printf( "m = %11f, hex(%08x)\n", m, *((uint32_t*)&m) );

		printf( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printf( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	{
		puts( "浮点数比较浮点数 - 精度问题（看代码）\n" );
		float n = 0.000012f;
		float m = 1.0f / 80000.0f;
		
		{
			/// 浮点数精度问题
		}
		printf( "n = %11f, hex(%08x)\n", n, n );
		printf( "m = %11f, hex(%08x)\n", m, m );

		printf( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printf( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	{
		puts( "逻辑比较\n" );
		char n = 0xc0;

		printf( "char n = %d, hex(%08x)\n", n, n );

		{
			// ERROR 数据先转换为无符号数，再比较
		}

		bool b = n & 0xef == n ;
		printf( "(n & 0xef) == n ? %s", b ? "true" : "false" );
		wait_key( 13 );
	}

}
