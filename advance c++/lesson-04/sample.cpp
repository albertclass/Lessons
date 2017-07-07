#include "header.h"
#include <cstdlib>


void do_lesson( int rows, int cols )
{
	printf( "��λ����\n" );

	puts( "\n----------------------\n" );
	{
		puts( "�߼���λ\n" );
		// �߼���λ
		unsigned int i = 0x80000001;

		unsigned int a = i >> 1;
		unsigned int b = i << 1;

		printf( "i = %08X, i >> 1 = %08X [", i, a );

		int sep[] = { 8, 16, 24, 32, 0 };
		print_bit( &a, sep );

		puts( "]\n" );

		printf( "i = %08X, i << 1 = %08X [", i, b );

		print_bit( &b, sep );

		puts( "]\n" );

		wait_key( 13 );
	}

	puts( "\n----------------------\n" );
	{
		puts( "������λ\n" );
		// ������λ
		int i = 0x80000001;

		int a = i >> 1;
		int b = i << 1; // SAL ��ͬ SHL �߼�����

		printf( "i = %08X, i >> 1 = %08X [", i, a );

		int sep[] = { 8, 16, 24, 32, 0 };
		print_bit( &a, sep );

		puts( "]\n" );

		printf( "i = %08X, i << 1 = %08X [", i, b );

		print_bit( &b, sep );

		puts( "]\n" );

		wait_key( 13 );
	}

	/*
	;SHL��SAL: ÿλ����, ��λ�� 0,  ��λ�� CF
	;SHR     : ÿλ����, ��λ�� CF, ��λ�� 0
	;SAR     : ÿλ����, ��λ�� CF, ��λ����
	*/
}
