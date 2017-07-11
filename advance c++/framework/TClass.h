#pragma once
#ifndef _T_CLASS_H_
#define _T_CLASS_H_
#include "header.h"

class base
{
public:
	base()
	{
		puts( "base call\n" );
	}

	~base()
	{
		puts( "~base call\n" );
	}
};

class vbase
{
public:
	vbase()
	{
		puts( "base call\n" );
	}

	virtual ~vbase()
	{
		puts( "~base call\n" );
	}
};


template< class TBase >
class inherit : public TBase
{
protected:
	std::string message;

public:
	inherit()
	{
		puts( "inherit call\n" );
	}

	inherit( const inherit &rhs )
	{
		printf( "inherit call copy\n" );
		message = rhs.message;
	}

	inherit& operator =( inherit &rhs )
	{
		printf( "inherit call operator =\n" );
		message = rhs.message;
		return *this;
	}

	~inherit()
	{
		puts( "~inherit call\n" );
	}

	virtual void show_message()const
	{
		puts( message.c_str() );
	}

	virtual void post_message( const char* msg )
	{
		message = msg;
	}

};

#endif // _T_CLASS_H_