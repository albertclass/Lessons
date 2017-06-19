#include "header.h"
#include <cstdlib>


void do_lesson( int rows, int cols )
{
	printw( "��ֵ�Ƚ�\n" );
	wait_key( 13 );

	addstr( "\n----------------------\n" );
	{
		addstr( "�з������Ƚ��з�����, n = -1, m = 32768\n" );
		int32_t n = -1;
		int16_t m = 32768;
		
		{
			// ERROR ���������
		}

		printw( "int32_t n = %11d, hex(%08x)\n", n, n );
		printw( "int16_t m = %11d, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );

		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�з������Ƚ��޷�����\n" );
		 int32_t n = -1;
		uint32_t m = -1;

		{
			// ERROR ��������
		}
		printw( " int32_t n = %11d, hex(%08x)\n", n, n );
		printw( "uint32_t m = %11d, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�޷������Ƚ�����ֵ\n" );
		uint32_t n = 0;

		printw( "uint32_t n = %11u, hex(%08x)\n", n, n );

		{
			// ERROR ������ת��Ϊ�޷��������ٱȽ�
		}

		printw( "n %c -1\n", n > -1 ? '>' : ( n < -1 ? '<' : '=' ) );
		printw( "-1 %c n\n", -1 > n ? '>' : ( -1 < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�������Ƚϸ�����\n" );
		float n = 1024.000025f;
		float m = 1024.000024f;

		{
			// ��������
		}
		printw( "n = %11f, hex(%08x)\n", n, n );
		printw( "m = %11f, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�������Ƚϸ�����\n" );
		float n = 0.000012f;
		float m = 1.0f / 80000.0f;
		
		{
			/// ��������������
		}
		printw( "n = %11f, hex(%08x)\n", n, n );
		printw( "m = %11f, hex(%08x)\n", m, m );

		printw( "n %c m\n", n > m ? '>' : ( n < m ? '<' : '=' ) );
		printw( "m %c n\n", m > n ? '>' : ( m < n ? '<' : '=' ) );
		wait_key( 13 );
	}
}
