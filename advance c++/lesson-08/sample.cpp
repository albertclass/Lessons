#include "header.h"
#include "cls.h"

void do_lesson( int rows, int cols )
{
	printf( "C++��\n" );

	printf( "�ºöϵ�׼�����ԡ�");

	wait_key( 13 );

	puts( "\n------------------------------------------\n" );
	puts( "����" );

	cls c_1; // �˴�����Ĭ�Ϲ��캯��

	cls c_2( "user message" ); // �ַ����Զ��˻�Ϊ const char* ����

	cls c_3( c_2 ); // �������캯��

	c_1 = c_3; // ��ֵ

	char *str = "user message too.";
	cls c_4( str ); // �� const ����

	cls c_5( std::string( "user message goon." ) ); // ��ֵ����

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

	// ��ֹ��ʽת���Ĺ��캯��
	A a_not_explicit = 'a';

	A a_explicit( 15.0f );

	C c;
	c.doing();
}
