#include "header.h"
#include <cstdlib>

#define ARRAY_LENGTH( arr ) sizeof(arr) / sizeof(arr[0])

// �޷���Ƕ��ֻ࣬��ͨ���������� RBP�Ĵ�����ֵ
void do_lesson( int rows, int cols )
{
	printw( "C++��ά����\n" );

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

	addstr( str );
	
	addstr( "\n----------------------\n" );

	{
		// ����������ռ�ֽ��������鳤��
		
		printw( "array size = %d, array length = %d\n", sizeof(n), ARRAY_LENGTH(n) );

		wait_key( 13 );

	}

	addstr( "\n----------------------\n" );
	{
		addstr( "�������ڴ��е����ӡ�" );
		char buf[1024];
		bin2hex( (char*)n, sizeof(n), buf, sizeof(buf), 8 );
		printw( "%s\n", buf );

		addch( '\n' );
		wait_key( 13 );
	}
}
