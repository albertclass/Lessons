#include "header.h"
#include <cstdlib>

static int item = 0;

struct sample
{
	sample()
	{
		item = 1;
	}
};

static sample s;

// �޷���Ƕ��ֻ࣬��ͨ���������� RBP�Ĵ�����ֵ
void do_lesson( int rows, int cols )
{
	printw( "C++����\n" );

	wait_key( 13 );
}
