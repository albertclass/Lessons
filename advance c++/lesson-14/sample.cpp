#include "header.h"
#include <algorithm>
#include <functional>

using namespace std;

template< class T >
class number
{
	T val;
public:
	number( T v ) : val( v )
	{
	}

	bool less_than( int comp )
	{
		return val < comp;
	}
};

void do_lesson( int rows, int cols )
{
	vector<int> coll;
	for(int i = 1; i <= 10; ++i)
		coll.push_back(i);

	//����Ԫ��ֵ����10��Ԫ�صĸ���
	//Ҳ����ʹ��10 < elem������Ԫ�ظ��� 

	auto res = count_if(coll.begin(), coll.end(), bind1st(less<int>(), 10));
	cout << res << endl;

	//����Ԫ��ֵС��10��Ԫ�صĸ���
	//Ҳ����ʹ��elem < 10������Ԫ�ظ��� 
	res = count_if(coll.begin(), coll.end(), bind2nd(less<int>(), 10));
	cout << res << endl;
	_getch();

	// ʵ�ó�Ա������
	vector< number< int > > vec;
	for( int i = 1; i < 10; ++i )
		vec.emplace_back( i );

	find_if( vec.begin(), vec.end(), bind2nd( mem_fun_ref(&number<int>::less_than), 5 ) );
}
        