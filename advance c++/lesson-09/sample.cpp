#include "header.h"
       
#define JOIN(x, y)	x##y
#define STRING(s) #s

#define Printf( FMT, ... )\
	printf( FMT, __VA_ARGS__ )

#define UNPAR(...) __VA_ARGS__

#define REPEAT_0(X) 
#define REPEAT_1(X) X(1)
#define REPEAT_2(X) REPEAT_1(X) X(2) 
#define REPEAT_3(X) REPEAT_2(X) X(3) 
#define REPEAT_4(X) REPEAT_3(X) X(4) 
#define REPEAT_5(X) REPEAT_4(X) X(5) 
#define REPEAT_6(X) REPEAT_5(X) X(6) 
#define REPEAT_7(X) REPEAT_6(X) X(7) 
#define REPEAT_8(X) REPEAT_7(X) X(8) 
#define REPEAT_9(X) REPEAT_8(X) X(9) 
#define REPEAT_10(X) REPEAT_9(X) X(10) 
#define REPEAT_11(X) REPEAT_10(X) X(11) 
#define REPEAT_12(X) REPEAT_11(X) X(12) 
#define REPEAT_13(X) REPEAT_12(X) X(13) 
#define REPEAT_14(X) REPEAT_13(X) X(14) 
#define REPEAT_15(X) REPEAT_14(X) X(15) 
#define REPEAT_16(X) REPEAT_15(X) X(16) 
#define REPEAT_17(X) REPEAT_16(X) X(17) 
#define REPEAT_18(X) REPEAT_17(X) X(18) 
#define REPEAT_19(X) REPEAT_18(X) X(19) 
#define REPEAT_20(X) REPEAT_19(X) X(20) 
#define REPEAT_21(X) REPEAT_20(X) X(21) 
#define REPEAT_22(X) REPEAT_21(X) X(22) 
#define REPEAT_23(X) REPEAT_22(X) X(23) 
#define REPEAT_24(X) REPEAT_23(X) X(24) 
#define REPEAT_25(X) REPEAT_24(X) X(25) 
#define REPEAT_26(X) REPEAT_25(X) X(26) 
#define REPEAT_27(X) REPEAT_26(X) X(27) 
#define REPEAT_28(X) REPEAT_27(X) X(28) 
#define REPEAT_29(X) REPEAT_28(X) X(29) 
#define REPEAT_30(X) REPEAT_29(X) X(30) 
#define REPEAT_31(X) REPEAT_30(X) X(31) 
#define REPEAT_32(X) REPEAT_31(X) X(32) 
#define REPEAT_MAX(X) REPEAT_10(X)  /* Change this up to 32 */

#define REPEAT(num, X) X(0) REPEAT_ ## num (UNPAR(X))

#define IF_0(X) 
#define IF_1(X) X
#define IF_2(X) X
#define IF_3(X) X
#define IF_4(X) X
#define IF_5(X) X
#define IF_6(X) X
#define IF_7(X) X
#define IF_8(X) X
#define IF_9(X) X
#define IF_10(X) X
#define IF_11(X) X
#define IF_12(X) X
#define IF_13(X) X
#define IF_14(X) X
#define IF_15(X) X
#define IF_16(X) X
#define IF_17(X) X
#define IF_18(X) X
#define IF_19(X) X
#define IF_20(X) X
#define IF_21(X) X
#define IF_22(X) X
#define IF_23(X) X
#define IF_24(X) X
#define IF_25(X) X
#define IF_26(X) X
#define IF_27(X) X
#define IF_28(X) X
#define IF_29(X) X
#define IF_30(X) X
#define IF_31(X) X
#define IF_32(X) X
#define IF_MAX(X) IF_10(X) /* Change this up to 32 */

#define SHOW_NUM(NUM) IF_ ## NUM(",") STRING(NUM)

#define MUL( x, y ) x * y

#define SHOW_TGL( X )\
	printf( "%s\n", #X );\
	printf( "%10s\n", #X );\
	printf( "%20s\n", #X );

void do_lesson( int rows, int cols )
{
	printf( "%s!\n", JOIN("Hello ", "world") );
	getch();

	int i = 1000;
	printf( "%s = %d\n", STRING(i), i );
	getch();

	printf( "%s(%d)\n", __FILE__, __LINE__ );
	getch();

	Printf( "%s(%d)\n", __FILE__, __LINE__ );
	getch();

	printf( REPEAT(10, SHOW_NUM ) "\n" );
	getch();

	printf( "%d\n", MUL( 8 + 7, 10 ) );
	getch();

	if( false )
		SHOW_TGL( M )

	getch();
}
