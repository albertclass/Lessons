#include "header.h"

static int sequence = 0;

class A
{
private:
	int value;

public:
	A() : value( sequence )
	{
		++sequence;
		printf( "value = %d\n", value );
	}

	~A()
	{
		printf( "value = %d\n", value );
	}
};

void do_lesson( int rows, int cols )
{
	printf( "堆\n" );

	printf( "堆内存分配开始调试，请准备好断点。\n“ " );

	wait_key( 13 );

	// 跟进去看看
	A* pA = new A();

	/*
	A* pA = new A();
	00007FF688402B49  mov         ecx,4  
	00007FF688402B4E  call        operator new (07FF68840123Fh)  
	00007FF688402B53  mov         qword ptr [rbp+108h],rax  
	00007FF688402B5A  cmp         qword ptr [rbp+108h],0  
	00007FF688402B62  je          do_lesson+89h (07FF688402B79h)  
	00007FF688402B64  mov         rcx,qword ptr [rbp+108h]  
	00007FF688402B6B  call        A::A (07FF6884011E5h)  
	00007FF688402B70  mov         qword ptr [rbp+138h],rax  
	*/

	/*
	void* __CRTDECL operator new(size_t const size)
	{
		for (;;)
		{
			if (void* const block = malloc(size))
			{
				return block;
			}

			if (_callnewh(size) == 0)
			{
				if (size == SIZE_MAX)
				{
					__scrt_throw_std_bad_array_new_length();
				}
				else
				{
					__scrt_throw_std_bad_alloc();
				}
			}

			// The new handler was successful; try to allocate again...
		}
	}
	*/

	// delete 空指针不会崩溃
	delete pA;

	A* parrA = new A[32];

	getch();

	delete [] parrA;
	getch();

	// 定位 new
	void *pmA = malloc( sizeof(A) );

	new( pmA ) A();

	((A*)pmA)->~A();
	// 定位new一般会用于内存管理的一些类中

	// free 空指针不会崩溃
	free( pmA );

	getch();
	// 也可以 delete ((A*))pmA;
}