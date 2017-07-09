#include "header.h"
#include <unordered_map>

void do_lesson( int rows, int cols )
{
	typedef std::unordered_map< std::string, long > U_MAP;
	
	U_MAP umap;
	
	umap.insert( U_MAP::value_type( "string_0", 0 ) );
	umap.insert( U_MAP::value_type( "string_1", 1 ) );
	umap.insert( U_MAP::value_type( "string_2", 2 ) );
	umap.insert( U_MAP::value_type( "string_3", 3 ) );

	umap.insert( U_MAP::value_type( "string_4", 4 ) );
	umap.insert( U_MAP::value_type( "string_5", 5 ) );
	umap.insert( U_MAP::value_type( "string_6", 6 ) );
	umap.insert( U_MAP::value_type( "string_7", 7 ) );

	umap.insert( U_MAP::value_type( "string_10", 0 ) );
	umap.insert( U_MAP::value_type( "string_11", 1 ) );
	umap.insert( U_MAP::value_type( "string_12", 2 ) );
	umap.insert( U_MAP::value_type( "string_13", 3 ) );

	umap.insert( U_MAP::value_type( "string_14", 4 ) );
	umap.insert( U_MAP::value_type( "string_15", 5 ) );
	umap.insert( U_MAP::value_type( "string_16", 6 ) );
	umap.insert( U_MAP::value_type( "string_17", 7 ) );

}
        