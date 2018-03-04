#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "csv_reader.h"

using namespace std;
struct rec
{
	long col_0;
	double col_1;
	string col_2;
	bool col_3;

	long col_4;
	double col_5;
	string col_6;
	bool col_7;
};


void read_csv()
{
	csv_reader csv;
	if( false == csv.load( "../2000X8.csv" ) )
	{
		printf( "read csv file error.\n" );
		return;
	}

	long rows = csv.rows();
	for( long i = 0; i < rows; ++i )
	{
		rec r;
		r.col_0 = csv.get_value( i, 0, 0L );
		r.col_1 = csv.get_value( i, 1, 0.0 );
		r.col_2 = csv.get_value( i, 2, ""s );
		r.col_3 = csv.get_value( i, 3, false );

		r.col_4 = csv.get_value( i, 4, 1L );
		r.col_5 = csv.get_value( i, 5, -1.0 );
		r.col_6 = csv.get_value( i, 6, "test"s );
		r.col_7 = csv.get_value( i, 7, true );
	}
}

int main( int argc, char** argv )
{
	clock_t c1 = clock();
	printf( "start at %.3f\n", c1 * 1.0 / CLOCKS_PER_SEC );
	int run = 100;
	for( int i = 0; i < run; ++i )
	{
		clock_t c2 = clock();
		read_csv();
		clock_t c3 = clock();
		printf( "using %.3f seconds\n", ( c3 - c2 ) * 1.0 / CLOCKS_PER_SEC );
	}

	clock_t c4 = clock();
	printf( "stop at %.3f, total using %.3f seconds, avrage using %.3f\n", 
		c4 * 1.0 / CLOCKS_PER_SEC, 
		( c4 - c1 ) * 1.0 / CLOCKS_PER_SEC, 
		( c4 - c1 ) * 1.0 / CLOCKS_PER_SEC / run );

	getchar();
}
