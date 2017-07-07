#include "header.h"

void printm( void* data, int s, int n )
{
	puts( "M : " );
	for( int i = s, c = 1; i < n; ++i, ++c )
	{
		if( BIT_CHK( data, i ) )
		{
			printf( "1/%u ", (1 << c) );
		}
	}
}

void do_lesson( int rows, int cols )
{
    puts( "整数存储\n" );

	puts( "\n----------------------\n" );
	puts( "整数 - LE存储\n" );
	{
		int32_t i = 0xc0271eb5;

		char hex[128];
		bin2hex( (char*) &i, sizeof( i ), hex, sizeof( hex ), 0 );
		printf( "LE - HEX : %08x, DEC : %u\n", i, i );
		puts( "------\n" );
		printf( "%s", hex );
		puts( "------\n" );

		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	puts( "整数 - BE存储\n" );

	{
		int32_t i = 0xb51e27c0;

		char hex[128];
		bin2hex( (char*)&i, sizeof(i), hex, sizeof(hex), 0 );
		printf( "BE - HEX : %08x, DEC : %u\n", i, i );
		puts( "------\n" );
		printf( "%s", hex );
		puts( "------\n" );

		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	puts( "浮点数示例 - 1\n" );
	{
		puts( "浮点数的计算\n" );
		float i = 32.5;
		int space[] = {1, 9, 32, 0};
		// int space[] = {8, 16, 24, 32, 0};

		unsigned char *p = (unsigned char*)&i;
		unsigned char v[4] = { p[3], p[2], p[1], p[0] };

		printf( "FLOAT : %f, %08x\n", i, *(unsigned int*)&i );
		printf( "BINARY : " );
		
		print_bit( v, space );
		putch('\n');

		int exp = (((*(unsigned int*)&i) & 0x4fc00000) >> 23) - 127;
		printf( "E : %d\n", exp );
		printm( v, 9, 23 );
		putch( '\n' );
		printf( "N = M * 2 ^ %d\n", exp );
		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	puts( "浮点数示例 - 2\n" );
	{
		float i = 3.14169265354;
		int space[] = {1, 9, 32, 0};

		unsigned char *p = (unsigned char*)&i;
		unsigned char v[4] = { p[3], p[2], p[1], p[0] };

		printf( "FLOAT : %f, %x\n", i, *(unsigned int*)&i );
		printf( "BINARY : " );
		print_bit( v, space );
		putch('\n');
		int exp = (((*(unsigned int*)&i) & 0x4fc00000) >> 23) - 127;
		printf( "E : %d\n", exp );
		printm( v, 9, 23 );
		putch( '\n' );
		printf( "N = M * 2 ^ %d\n", exp );
		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	puts( "浮点数示例 - 3\n" );

	{
		unsigned int n = 0;
		n = 0b01111111100000000000000000000000;
		printf( "float : 0 11111111 00000000 00000000 0000000 = %f\n", *((float*)&n) );
		n = 0b11111111100000000000000000000000;
		printf( "float : 1 11111111 00000000 00000000 0000000 = %f\n", *((float*)&n) );
		n = 0b01111111100000000000000000000001;
		printf( "float : 0 11111111 00000000 00000000 0000001 = %f\n", *((float*)&n) );

		wait_key( 13 );
	}
}