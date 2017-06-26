#ifndef _CLS_H_
#define _CLS_H_

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
	inherit()
	{
		addstr( "inherit call\n" );
	}

	~inherit()
	{
		addstr( "~inherit call\n" );
	}
};

#endif