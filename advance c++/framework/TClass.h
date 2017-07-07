#pragma once
#ifndef _T_CLASS_H_
#define _T_CLASS_H_
#include "header.h"

class base
{
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
private:
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
};

#endif // _T_CLASS_H_