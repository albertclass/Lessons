#include "header.h"
#include <cstdlib>
#include "cls.h"

void do_lesson( int rows, int cols )
{
	printw( "C++类\n" );

	printw( "下好断点准备调试。");

	wait_key( 13 );

	class A
	{
	private:
		int mSource;
		volatile int mSection;
		mutable int mConst;

	public:
		A()
			: mSource(0)
			, mSection(0)
			, mConst(0)
		{
		}

		A( const char* msg )
			: A()
		{
			printw( msg );
		}

		explicit A( int n )
			: A()
		{
			mSource = n;
		}

		~A()
		{

		}

		void do_something()
		{
			int t = 0;
			int m = 0;

			m = mSection;
			// mov         rax,qword ptr [this]  
			// mov         eax,dword ptr [rax+4]  
			// mov         dword ptr [m],eax  
			t = mSection;
			// mov         rax,qword ptr [this]  
			// mov         eax,dword ptr [rax+4]  
			// mov         dword ptr [t],eax  

			// 一般变量会进行优化。
			m = mSource;
			// mov         rax,qword ptr [this]  
			// mov         eax,dword ptr [rax]  
			// mov         dword ptr [m],eax  
			t = mSource;
			// mov         rax,qword ptr [this]  
			// mov         eax,dword ptr [rax]  
			t = mSource;
			// mov         dword ptr [t],eax  
		}

		void do_something()const
		{
			mConst = 10;
		}
	};

	A a_normal;

	a_normal.do_something();

	const A a_const("委托构造");

	a_const.do_something();

	// 隐式转换
	A a_constructor = "委托构造";

	// 禁止隐士转换的构造函数
	// A a_explicit = 15;
	A a_explicit( 15 );
}
