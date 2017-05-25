#include "header.h"
#include <cstdlib>

#define BIT_CHK( V, N ) (((unsigned char*)V)[N>>3] & (1 << (7-(N&7))))
#define BIT_SET( V, N ) (((unsigned char*)V)[N>>3] |= (1 << (7-(N&7))))
#define BIT_CLR( V, N ) (((unsigned char*)V)[N>>3] &= (~(1 << (7-(N&7)))))

void print_bit( void* data, int space[] )
{
	int i = 0;
	int n = 0;

	while( space[i] )
	{
		addch( BIT_CHK(data, n) ? '1' : '0' );

		if( space[i] == ++n )
		{
			addch( ' ' );
			++i;
		}
	}
}

void printm( void* data, int s, int n )
{
	addstr( "M : " );
	for( int i = s, c = 1; i < n; ++i, ++c )
	{
		if( BIT_CHK( data, i ) )
		{
			printw( "1/%u ", (1 << c) );
		}
	}
}

void do_lesson( int rows, int cols )
{
	printw( "FP Number\n" );

	{
		float i = 32.5;
		int space[] = {1, 9, 32, 0};
		// int space[] = {8, 16, 24, 32, 0};

		unsigned char *p = (unsigned char*)&i;
		unsigned char v[4] = { p[3], p[2], p[1], p[0] };

		printw( "FLOAT : %f, %x\n", i, *(unsigned int*)&i );
		printw( "BINARY : " );
		print_bit( v, space );
		addch('\n');

		int exp = (((*(unsigned int*)&i) & 0x4fc00000) >> 23) - 127;
		printw( "E : %d\n", exp );
		printm( v, 9, 23 );
		addch( '\n' );
		printw( "N = M * 2 ^ %d\n", exp );
		wait_key( 10 );
	}


	{
		float i = 3.14169265354;
		int space[] = {1, 9, 32, 0};

		unsigned char *p = (unsigned char*)&i;
		unsigned char v[4] = { p[3], p[2], p[1], p[0] };

		printw( "FLOAT : %f, %x\n", i, *(unsigned int*)&i );
		printw( "BINARY : " );
		print_bit( v, space );
		addch('\n');
		int exp = (((*(unsigned int*)&i) & 0x4fc00000) >> 23) - 127;
		printw( "E : %d\n", exp );
		printm( v, 9, 23 );
		addch( '\n' );
		printw( "N = M * 2 ^ %d\n", exp );
		wait_key( 10 );
	}

	addch( '\n' );
	addstr( "---------\n" );
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
