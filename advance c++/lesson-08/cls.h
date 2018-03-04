#ifndef _CLS_H_
#define _CLS_H_

class cls
{
private:
	std::string message;

public:
	cls() : message( "default str" )
	{
	}

	cls( const cls &rhs )
	{
		message = rhs.message;
	}

	cls& operator =( cls &rhs )
	{
		message = rhs.message;
		return *this;
	}

	cls( char *str )
		: message( str )
	{
	}

	cls( const char* str )
		: message( str )
	{
	}

	explicit cls( const std::string &str )
		: message( str )
	{
	}

	// C++ 11 右值构造
	// const 类型的右值引用会被退化为const 引用。
	explicit cls( std::string &&str )
		: message( std::forward< decltype(str) >(str) )
	{
	}

	// C++ 11 委托构造
	explicit cls( const std::stringstream & stream )
		: cls( stream.str() )
	{
	}

	~cls()
	{
	}
};

class A
{
public:
	void doing()
	{
		printf( "class A doing.\n" );
	}
};

class B1 : virtual public A
{

};

class B2 : virtual public A
{

};

class C : public B1, B2
{

};

#endif