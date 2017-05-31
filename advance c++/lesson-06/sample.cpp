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

// 无法内嵌汇编，只能通过调试来看 RBP寄存器的值
void do_lesson( int rows, int cols )
{
	printw( "C++启动\n" );

	wait_key( 13 );
}
