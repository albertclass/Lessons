#include "header.h"
#include "TClass.h"
#include <memory>
#include <functional>
#include <thread>
#include <mutex>
#include <future>

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

void do_lesson( int rows, int cols )
{
	std::unique_ptr< int, decltype(std::free) * > ptr( new int, free );

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
}
        