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

	// �鿴�����룬���ϵͳ�Ż�
	strcpy( bstr, astr );

	// �鿴�����룬���UVָ��
	memcpy( bstr, astr, 11 );

	memmove( bstr, astr, 11 );

	char abuf[32];
	int i = 19801001;
	sprintf( abuf, "%08x", i );

	char input[4];
	char tips[] = "���뺯���ᵼ�»�����������������������ڸ�ʽ�����ᵼ�²���Ԥ�ϵĽ����\n�����루input[4]):";

	printf( tips );
	scanf( "%s", &input );
	printf( tips );
	printf( input );

	// srand( (unsigned int) time(nullptr) );

	// ����ʲô��α��������Լ����ʹ������������������
	// �������α�����
	srand( 10478 );
	int r = rand();
	int r_max = RAND_MAX;

	printf( "random r = %d random max = %d\n", r, r_max );

	// ȡϵͳʱ��
	time_t t;
	t = time(&t);
	printf( "%u", t );

	struct tm *ptm = gmtime(&t);

	getch();
	
}
        