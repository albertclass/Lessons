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

class base
{
	base()
	{
		addstr( "base call\n" );
	}

	~base()
	{
		addstr( "~base call\n" );
	}
};

class vbase
{
	vbase()
	{
		addstr( "base call\n" );
	}

	virtual ~vbase()
	{
		addstr( "~base call\n" );
	}
};


template< class TBase >
class inherit : public TBase
{
private:
	std::string message;

public:
	inherit()
	{
		addstr( "inherit call\n" );
	}

	inherit( const inherit &rhs )
	{
		printw( "inherit call copy\n" );
		message = rhs.message;
	}

	inherit& operator =( inherit &rhs )
	{
		printw( "inherit call operator =\n" );
		message = rhs.message;
		return *this;
	}

	~inherit()
	{
		addstr( "~inherit call\n" );
	}
};

#endif