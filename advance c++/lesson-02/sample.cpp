#include "header.h"
#include <cstdlib>

void do_lesson( int rows, int cols )
{
	puts( "数值转换\n" );

	puts( "\n----------------------\n" );
	{
		puts( "数据上溢 1\n" );
		 int32_t n = 65538;
		 int16_t s = ( int16_t)n;
		uint16_t u = (uint16_t)n;
		// movzx       eax,word ptr [rbp+4]  
		// mov         word ptr [rbp+24h],ax  

		printf( "  int32_t n = %11d, hex(%08x)\n", n, n );
		printf( "( int16_t)n = %11d, hex(%08x)\n", s, s );
		printf( "(uint16_t)n = %11u, hex(%08x)\n", u, u );

		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	{
		puts( "数据上溢 2\n" );
		 int32_t n = -32769;
		 int16_t s = ( int16_t)n;
		uint16_t u = (uint16_t)n;
		// movzx       eax,word ptr [rbp+4]  
		// mov         word ptr [rbp+24h],ax  

		printf( "  int32_t n = %11d, hex(%08x)\n", n, n );
		printf( "( int16_t)n = %11d, hex(%08x)\n", s, s );
		printf( "(uint16_t)n = %11u, hex(%08x)\n", u, u );

		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	{
		puts( "数据下溢 1\n" );
		 int32_t n = -65537;
		 int16_t s = (int16_t)n;
		uint16_t u = (uint16_t)n;
		// movzx       eax,word ptr [rbp+44h]  
		// mov         word ptr [rbp+64h],ax  

		printf( "  int32_t n = %11d, hex(%08x)\n", n, n );
		printf( "( int16_t)n = %11d, hex(%08x)\n", s, s );
		printf( "(uint16_t)n = %11u, hex(%08x)\n", u, u );
		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	{
		puts( "数据下溢 2\n" );
		 int32_t n = 0x80007fff;
		 int16_t s = (int16_t)n;
		uint16_t u = (uint16_t)n;

		printf( "  int32_t n = %11d, hex(%08x)\n", n, n );
		printf( "( int16_t)s = %11d, hex(%08x)\n", s, s );
		printf( "(uint16_t)s = %11u, hex(%08x)\n", u, u );
		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	{
		puts( "数据溢出 - 无符号转有符号\n" );
		uint32_t n = 0x80000000;
		 int32_t s = n;

		printf( "uint32_t n = %11u, hex(%08x)\n", n, n );
		printf( "(int32_t)s = %11d, hex(%08x)\n", s, s );
		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	{
		puts( "数据溢出 - 单精度转整型\n" );
		float f = 4294967295 - 128;
		uint32_t u = f;
		 int32_t n = f;

		printf( "float f = %f, hex(%08x)\n", f, *(uint32_t*)&f );
		printf( "(uint32_t)u = %11u, hex(%08x)\n", u, u );
		printf( "( int32_t)n = %11d, hex(%08x)\n", n, n );
		wait_key( 13 );
	}

}
