#include "header.h"
#include "util.h"

void wait_key( int key )
{
	int ch = getch();
	while( ch != key )
		ch = getch();
}

size_t bin2hex( char* data, size_t size, char* out, size_t out_size, size_t flags )
{
	int32_t width = ( ( flags & 0x00000003 ) + 1 ) * 8;
	char* ascii = (char*) malloc( ( width + 1 )*sizeof( char ) );

	char* ptr = ascii;
	char* p = out;
	char* end = p + out_size;

	int32_t n = sprintf_s( p, (size_t) ( end - p ), "\n" );
	if( n < 0 )
		return 0;
	p += n;
	size_t i = 0;
	for( ; i < size && i < out_size - n; ++i )
	{
		if( p + 3 >= end ) break;
		unsigned char uch = *( data + i );
		n = sprintf_s( p, (size_t) ( end - p ), "%02x ", uch );
		if( n < 0 )
		{
			*( p - 1 ) = 0;
			break;
		}
		if( isprint( uch ) )
		{
			*ascii++ = uch;
		}
		else
		{
			*ascii++ = '.';
		}
		p += n;

		if( ( i + 1 ) % width == 0 )
		{
			*ascii++ = 0;
			ascii -= width + 1;
			if( strlen( ascii ) < size_t( end - p ) )
				n = sprintf_s( p, (size_t) ( end - p ), "%s\n", ascii );
			else
				n = -1;
			if( n < 0 )
			{
				*( p - 1 ) = 0;
				break;
			}
			p += n;
		}
	}

	n = sprintf_s( p, (size_t) ( end - p ), "%*s", __min( int( end - p ), ( width - int( i%width ) ) * 3 ), "" );
	if( n < 0 )
	{
		*( p - 1 ) = 0;
	}
	else
	{
		p += n;
		*ascii++ = 0;
		ascii -= ( i + 1 ) % width;
		if( strlen( ascii ) < size_t( end - p ) )
			n = sprintf_s( p, (size_t) ( end - p ), "%s\n", ascii );
		else
			n = -1;
		if( n < 0 )
		{
			*( p - 1 ) = 0;
		}
		else
		{
			p += n;
		}
	}

	free( ptr );
	return size_t( p - out );
}

void print_bit( void* data, int space[] )
{
	int i = 0;
	int n = 0;

	while( space[i] )
	{
		putch( BIT_CHK(data, n) ? '1' : '0' );

		if( space[i] == ++n )
		{
			putch( ' ' );
			++i;
		}
	}
}
