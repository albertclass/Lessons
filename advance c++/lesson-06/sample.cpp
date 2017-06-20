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
		printw( "value = %d\n", value );
	}

	~A()
	{
		printw( "value = %d\n", value );
	}
};

void do_lesson( int rows, int cols )
{
	printw( "堆\n" );

	printw( "开始调试，请准备好断点。\n“ " );

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
	00007FF688402B77  jmp         do_lesson+94h (07FF688402B84h)  
	00007FF688402B79  mov         qword ptr [rbp+138h],0  
	00007FF688402B84  mov         rax,qword ptr [rbp+138h]  
	00007FF688402B8B  mov         qword ptr [rbp+0E8h],rax  
	00007FF688402B92  mov         rax,qword ptr [rbp+0E8h]  
	00007FF688402B99  mov         qword ptr [pA],rax  
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

	delete [] parrA;

	// 定位 new
	void *pmA = malloc( sizeof(A) );

	new( pmA ) A();

	((A*)pmA)->~A();

	// free 空指针不会崩溃
	free( pmA );
}