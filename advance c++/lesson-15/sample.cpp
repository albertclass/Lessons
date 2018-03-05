#include "header.h"
#include "TClass.h"
#include <memory>
#include <functional>
#include <thread>
#include <mutex>
#include <future>

using namespace std;
using namespace std::placeholders;
class ClassA : public inherit< base >
{
public:
	ClassA() 
		: inherit< base >()
	{
		// 此处调用，访问子类的虚函数还是父类的虚函数？
		post_message( "1234567890" );
		show_message();
	}

	~ClassA()
	{
		show_message();
	}
};

class ClassB : public ClassA
{
public:
	ClassB()
		: ClassA()
	{

	}

	~ClassB()
	{
		show_message();
	}

	virtual void show_message()
	{
		puts( "ClassB invoke show_message" );
	}

	virtual void post_message( const char* msg )
	{
		puts( "ClassB call" );
		message = msg;
	}
};

class ClassC : public inherit< vbase >
{
public:
	~ClassC()
	{
		show_message();
	}

	virtual void show_message()
	{
		puts( "ClassC invoke show_message" );
	}
};

class ClassD : public ClassC
{
public:
	~ClassD()
	{
		show_message();
	}

	virtual void show_message()
	{
		puts( "ClassD invoke show_message" );
	}
};

typedef function< void(int, int, int) > f;

void f0( int p1, int p2, int p3 )
{
	printf( "p1 = %d, p2 = %d, p3 = %d\n", p1, p2, p3 );
}

template<typename T, typename... U>
size_t getAddress(std::function<T(U...)> f) {
	typedef T(fnType)(U...);
	fnType ** fnPointer = f.template target<fnType*>();
	return (size_t) *fnPointer;
}

void do_lesson( int rows, int cols )
{
	std::unique_ptr< int, decltype(std::free) * > ptr( new int, free );

	auto f1 = bind( f0, 1, 2, 3 );
	auto f2 = bind( f0, 3, 2, 1 );

	//printf( "f1 = %llu\n", getAddress(f1) );
	//printf( "f2 = %llu\n", getAddress(f2) );
	{
		ClassA a;

		ClassB b;

		ClassC c;

		ClassD d;
	}

	{
		ClassA *a = new ClassA;

		ClassA *b = new ClassB;

		ClassC *c = new ClassC;

		ClassC *d = new ClassD;

		delete a;
		delete b;
		delete c;
		delete d;
	}

	char str1[] = "12345678901234567890";
	char str2[20];
	char str3[20];

	strncpy( str2, str1, sizeof( str2 ) );
}
        