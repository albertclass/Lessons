#pragma once
#include <string>
#include <vector>

class csv_reader
{
public:
	csv_reader();
	~csv_reader();

	bool load( const char* filename );

	long rows()const
	{
		return (long)table.size();
	}

	bool get_value( int row, int col, bool default );

	long get_value( int row, int col, long default );

	double get_value( int row, int col, double default );

	std::string get_value( int row, int col, const std::string& default );

private:
	std::vector< std::vector< std::string > > table;
};

