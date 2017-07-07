#include "header.h"
#include <cstdlib>

#define ARRAY_LENGTH( arr ) sizeof(arr) / sizeof(arr[0])

// 无法内嵌汇编，只能通过调试来看 RBP寄存器的值
void do_lesson( int rows, int cols )
{
	printf( "C++多维数组\n" );

	int n[4][2] = 
	{
		{ 1, 2 }, 
		{ 3, 4 },
		{ 5, 6 },
		{ 7, 8 },
	};

	char * str = 
	"int n[4][2] = \n"
	"{\n"
	"	{ 1, 2 },\n"
	"	{ 3, 4 },\n"
	"	{ 5, 6 },\n"
	"	{ 7, 8 },\n"
	"};\n";

	puts( str );
	
	puts( "\n----------------------\n" );

	{
		// 计算数组所占字节数和数组长度
		
		printf( "array size = %d, array length = %d\n", sizeof(n), ARRAY_LENGTH(n) );

		wait_key( 13 );

	}

	puts( "\n----------------------\n" );
	{
		puts( "数组在内存中的样子。" );
		char buf[1024];
		bin2hex( (char*)n, sizeof(n), buf, sizeof(buf), 8 );
		printf( "%s\n", buf );

		putch( '\n' );
		wait_key( 13 );
	}
}
