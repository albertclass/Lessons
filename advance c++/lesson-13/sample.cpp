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
	// C++ 11 ���������������ͳһ
	for( char *str : strings )
		*back_insert_iter = str;
}

template< class T >
void tour_container( const T& c )
{
	// ����ϵ���Կ��� iterator_category �����Ķ�����ġ�
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
	// Alt + G �鿴�����룬����++it �� it++������
	++it_a;
	it_a++;

	it_a = a.begin();
	// ɾ������Ԫ�صİ�ȫ����
	it_a = a.erase( it_a );
	std::cout << *it_a << std::endl;

	// ��������ɾ������Ԫ�صĲ����Ƿ�ȫ��
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
	// ɾ������Ԫ�صİ�ȫ����
	it_b = b.erase( it_b );
	std::cout << *it_b << std::endl;

	// ��������ɾ������Ԫ�صĲ����Ƿ�ȫ��
	b.erase( it_b++ );
	std::cout << *it_b << std::endl;

	tour_container( a );

	_getch();
}
        