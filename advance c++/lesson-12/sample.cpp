#include "header.h"
           
void do_lesson( int rows, int cols )
{
	class exception
	{
	public:
		exception()
		{
			puts( "exception ctor" );
		}

		exception( const exception& rhs )
		{
			puts( "exception copy" );
		}

		~exception()
		{
			puts( "exception reduce" );
		}
	};

	try
	{
		throw( exception() );
	}
	catch( exception &e )
	{
		puts( "catch exception object" );
	}

	try
	{
		throw( exception() );
	}
	catch( exception e )
	{
		puts( "catch exception object" );
	}

	int *pint = nullptr;
	try
	{
		pint = new int[std::numeric_limits<uint64_t>::max()];
		printf( "pint = %p\n", pint );
	}
	catch( std::bad_alloc &e )
	{
		printf( "catch '%s'\n", e.what() );
	}

	try
	{
		pint = new (std::nothrow) int[std::numeric_limits<uint64_t>::max()/2];
		printf( "pint = %p\n", pint );
	}
	catch( std::bad_alloc &e )
	{
		printf( "catch '%s'", e.what() );
	}

	getch();
}
        