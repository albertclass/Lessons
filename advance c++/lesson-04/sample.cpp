#include "header.h"
#include <cstdlib>


void do_lesson( int rows, int cols )
{
	printw( "��λ����\n" );

	addstr( "\n----------------------\n" );
	{
		addstr( "�߼���λ\n" );
		// �߼���λ
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
		addstr( "������λ\n" );
		// ������λ
		int i = 0x80000001;

		int a = i >> 1;
		int b = i << 1; // SAL ��ͬ SHL �߼�����

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
	;SHL��SAL: ÿλ����, ��λ�� 0,  ��λ�� CF
	;SHR     : ÿλ����, ��λ�� CF, ��λ�� 0
	;SAR     : ÿλ����, ��λ�� CF, ��λ����
	*/
}
