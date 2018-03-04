#include "csv_reader.h"
#include <iosfwd>
#include <fstream>
#include <algorithm>

using namespace std;

csv_reader::csv_reader()
{
}

csv_reader::~csv_reader()
{
}

bool csv_reader::load( const char* filename )
{
	fstream fs;
	fs.open( filename, ios_base::in );

	int row = 0;

	if( !fs.is_open() )
		return false;

	string line;
	while( !fs.eof() )
	{
		getline( fs, line );

		if( line.empty() )
			continue;

		while( line[0] == '\r' ) line.erase( 0, 1 );

		if( line.empty() || line[0] == '\n' )
			continue;

		table.push_back( vector< string >() );

		int col = 0;
		int pos = 0;
		int off = line.find_first_of( ',', pos );
		while( off != string::npos )
		{
			string val = line.substr( pos, off - pos );
			while( !val.empty() && val[0] == ' ' )
				val.erase( 0, 1 );

			table[row].push_back( val );
			++col;
			pos = off + 1;
			off = line.find_first_of( ',', pos );
		}

		++row;
	}

	return true;
}

bool csv_reader::get_value( int row, int col, bool default )
{
	string val = get_value( row, col, string() );
	if( val.empty() )
		return default;

	transform( val.begin(), val.end(), val.begin(), tolower );

	if( val == "true" )
		return true;

	if( stoul( val ) != 0 )
		return true;

	return false;
}

long csv_reader::get_value( int row, int col, long default )
{
	string val = get_value( row, col, string() );
	if( val.empty() )
		return default;

	return stol( val );
}

double csv_reader::get_value( int row, int col, double default )
{
	string val = get_value( row, col, string() );
	if( val.empty() )
		return default;

	return stof( val );
}

string csv_reader::get_value( int row, int col, const string& default )
{
	if( row >= table.size() )
		return default;

	auto &fields = table[row];
	
	if( col >= fields.size() )
		return default;

	return fields[col];
}