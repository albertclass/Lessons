#include "header.h"
#include <cstdlib>
#include "cls.h"

void do_lesson( int rows, int cols )
{
	printw( "C++��\n" );

	printw( "�ºöϵ�׼�����ԡ�");

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

			// һ�����������Ż���
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

	const A a_const("ί�й���");

	a_const.do_something();

	// ��ʽת��
	A a_constructor = "ί�й���";

	// ��ֹ��ʿת���Ĺ��캯��
	// A a_explicit = 15;
	A a_explicit( 15 );
}
