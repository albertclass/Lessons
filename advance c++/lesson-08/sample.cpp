#include "header.h"
#include "cls.h"

void do_lesson( int rows, int cols )
{
	printf( "C++类\n" );

	printf( "下好断点准备调试。");

	wait_key( 13 );

	puts( "\n------------------------------------------\n" );
	puts( "构造" );

	cls c_1; // 此处调用默认构造函数

	cls c_2( "user message" ); // 字符串自动退化为 const char* 类型

	cls c_3( c_2 ); // 拷贝构造函数

	c_1 = c_3; // 赋值

	char *str = "user message too.";
	cls c_4( str ); // 非 const 参数

	cls c_5( std::string( "user message goon." ) ); // 右值构造

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
			printf( msg );
		}

		explicit A( float f )
			: A()
		{

		}

		A( int n )
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

	// 禁止隐式转换的构造函数
	A a_not_explicit = 'a';

	A a_explicit( 15.0f );

	C c;
	c.doing();
}
