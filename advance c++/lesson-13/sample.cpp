#include "header.h"
#include <algorithm>

char *strings[] =
{
	"black",
	"red",
	"blue",
	"gray",
	"green",
	"orange",
	"white",
};

template< class T >
void init_container( T& c )
{
	auto back_insert_iter = std::back_inserter( c );
	// C++ 11 将数组和容器做了统一
	for( char *str : strings )
		*back_insert_iter = str;
}

template< class T >
void tour_container( const T& c )
{
	// 这里断点可以看下 iterator_category 是在哪儿定义的。
	for( auto it = c.begin(); it != c.end(); ++it )
		std::cout << *it << std::endl;
}

void do_lesson( int rows, int cols )
{
	typedef std::list< std::string > TList;
	typedef std::vector< std::string > TVector;

	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "TList" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	TList a;
	init_container( a );

	auto it_a = a.begin();
	// Alt + G 查看汇编代码，解释++it 和 it++的区别
	++it_a;
	it_a++;

	it_a = a.begin();
	// 删除容器元素的安全方法
	it_a = a.erase( it_a );
	std::cout << *it_a << std::endl;

	// 考虑下面删除容器元素的操作是否安全？
	a.erase( it_a++ );
	std::cout << *it_a << std::endl;

	tour_container( a );

	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "TVector" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	TVector b;
	init_container( b );

	auto it_b = b.begin();
	// 删除容器元素的安全方法
	it_b = b.erase( it_b );
	std::cout << *it_b << std::endl;

	// 考虑下面删除容器元素的操作是否安全？
	b.erase( it_b++ );
	std::cout << *it_b << std::endl;

	tour_container( a );

	_getch();
}
        