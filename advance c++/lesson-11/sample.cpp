#include "header.h"
#include <time.h>

void print_log( const char* fmt, ... )
{
	char log[256];
	va_list args;
	va_start( args, fmt );
	vsprintf( log, fmt, args );
	va_end( args );
}

void do_lesson( int rows, int cols )
{
	char astr[] = "1234567890";
	char bstr[11] = { 0 };

	// 查看汇编代码，理解系统优化
	strcpy( bstr, astr );

	// 查看汇编代码，理解UV指令
	memcpy( bstr, astr, 11 );

	memmove( bstr, astr, 11 );

	char abuf[32];
	int i = 19801001;
	sprintf( abuf, "%08x", i );

	char input[4];
	char tips[] = "输入函数会导致缓冲区溢出，将输入数据用于格式化串会导致不可预料的结果。\n请输入（input[4]):";

	printf( tips );
	scanf( "%s", &input );
	printf( tips );
	printf( input );

	// srand( (unsigned int) time(nullptr) );

	// 讲解什么是伪随机数，以及如何使随机数看起来更随机。
	// 如何利用伪随机数
	srand( 10478 );
	int r = rand();
	int r_max = RAND_MAX;

	printf( "random r = %d random max = %d\n", r, r_max );

	// 取系统时间
	time_t t;
	t = time(&t);
	printf( "%u", t );

	struct tm *ptm = gmtime(&t);

	getch();
	
}
        