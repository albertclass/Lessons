#include "header.h"
#include <cstdlib>

void stack_mem_sample()
{
	char astr[] = "1234567890";
	char bstr[] = "1234567890";

	printw( "astr = %s\n", astr );
	printw( "bstr = %s\n", bstr );

	strcpy( astr, "----------+----------+" );

	printw( "\nstrcpy( astr, \"----------+----------+\" );\n\n" );
	printw( "astr = %s\n", astr );
	printw( "bstr = %s\n", bstr );

	wait_key( 13 );
}

uintptr_t ret = 0;

void stack_attack_ret( int i )
{
	addstr( "call stack_attack_ret()" );

	memcpy( (char*)&i - sizeof(ret), &ret, sizeof(ret) );
}

void stack_attack()
{
	addstr( "call stack_attack()\n" );
	wait_key( 13 );

	stack_attack_ret( 0 );
}

void stack_overflow()
{
	char astr[11] = "1234567890";
	printw( "astr = %s\n", astr );

	uintptr_t addr = (uintptr_t)stack_attack;

	memcpy( &ret, astr + 0x78, sizeof(addr) );

	memcpy( astr + 0x78, &addr, sizeof(addr) );

	addstr( "now begin stack overflow attack\n" );
	wait_key( 13 );
}

// 无法内嵌汇编，只能通过调试来看 RBP寄存器的值
void do_lesson( int rows, int cols )
{
	printw( "使用内存\n" );

	stack_mem_sample();

	// 进行一次缓冲区溢出的攻击
	stack_overflow();
}
