#include "header.h"
#include <cstdlib>


void do_lesson( int rows, int cols )
{
	printw( "移位操作\n" );

	addstr( "\n----------------------\n" );
	{
		addstr( "逻辑移位\n" );
		// 逻辑移位
		unsigned int i = 0x80000001;

		unsigned int a = i >> 1;
		unsigned int b = i << 1;

		printw( "i = %08X, i >> 1 = %08X [", i, a );

		int sep[] = { 8, 16, 24, 32, 0 };
		print_bit( &a, sep );

		addstr( "]\n" );

		printw( "i = %08X, i << 1 = %08X [", i, b );

		print_bit( &b, sep );

		addstr( "]\n" );

		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "算数移位\n" );
		// 算数移位
		int i = 0x80000001;

		int a = i >> 1;
		int b = i << 1; // SAL 等同 SHL 逻辑左移

		printw( "i = %08X, i >> 1 = %08X [", i, a );

		int sep[] = { 8, 16, 24, 32, 0 };
		print_bit( &a, sep );

		addstr( "]\n" );

		printw( "i = %08X, i << 1 = %08X [", i, b );

		print_bit( &b, sep );

		addstr( "]\n" );

		wait_key( 13 );
	}

	/*
	;SHL、SAL: 每位左移, 低位补 0,  高位进 CF
	;SHR     : 每位右移, 低位进 CF, 高位补 0
	;SAR     : 每位右移, 低位进 CF, 高位不变
	*/
}
