#include "header.h"
#include <cstdlib>

void do_lesson( int rows, int cols )
{
	addstr( "��ֵת��\n" );

	addstr( "\n----------------------\n" );
	{
		addstr( "�������� 1\n" );
		 int32_t n = 65538;
		 int16_t s = ( int16_t)n;
		uint16_t u = (uint16_t)n;
		// movzx       eax,word ptr [rbp+4]  
		// mov         word ptr [rbp+24h],ax  

		printw( "  int32_t n = %11d, hex(%08x)\n", n, n );
		printw( "( int16_t)n = %11d, hex(%08x)\n", s, s );
		printw( "(uint16_t)n = %11u, hex(%08x)\n", u, u );

		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�������� 2\n" );
		 int32_t n = -32769;
		 int16_t s = ( int16_t)n;
		uint16_t u = (uint16_t)n;
		// movzx       eax,word ptr [rbp+4]  
		// mov         word ptr [rbp+24h],ax  

		printw( "  int32_t n = %11d, hex(%08x)\n", n, n );
		printw( "( int16_t)n = %11d, hex(%08x)\n", s, s );
		printw( "(uint16_t)n = %11u, hex(%08x)\n", u, u );

		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�������� 1\n" );
		 int32_t n = -65537;
		 int16_t s = (int16_t)n;
		uint16_t u = (uint16_t)n;
		// movzx       eax,word ptr [rbp+44h]  
		// mov         word ptr [rbp+64h],ax  

		printw( "  int32_t n = %11d, hex(%08x)\n", n, n );
		printw( "( int16_t)n = %11d, hex(%08x)\n", s, s );
		printw( "(uint16_t)n = %11u, hex(%08x)\n", u, u );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�������� 2\n" );
		 int32_t n = 0x80007fff;
		 int16_t s = (int16_t)n;
		uint16_t u = (uint16_t)n;

		printw( "  int32_t n = %11d, hex(%08x)\n", n, n );
		printw( "( int16_t)s = %11d, hex(%08x)\n", s, s );
		printw( "(uint16_t)s = %11u, hex(%08x)\n", u, u );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "������� - �޷���ת�з���\n" );
		uint32_t n = 0x80000000;
		 int32_t s = n;

		printw( "uint32_t n = %11u, hex(%08x)\n", n, n );
		printw( "(int32_t)s = %11d, hex(%08x)\n", s, s );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "������� - ������ת����\n" );
		float f = 4294967295 - 128;
		uint32_t u = f;
		 int32_t n = f;

		printw( "float f = %f, hex(%08x)\n", f, *(uint32_t*)&f );
		printw( "(uint32_t)u = %11u, hex(%08x)\n", u, u );
		printw( "( int32_t)n = %11d, hex(%08x)\n", n, n );
		wait_key( 13 );
	}

}
