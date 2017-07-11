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

	//查找元素值大于10的元素的个数
	//也就是使得10 < elem成立的元素个数 

	auto res = count_if(coll.begin(), coll.end(), bind1st(less<int>(), 10));
	cout << res << endl;

	//查找元素值小于10的元素的个数
	//也就是使得elem < 10成立的元素个数 
	res = count_if(coll.begin(), coll.end(), bind2nd(less<int>(), 10));
	cout << res << endl;
	_getch();

	// 实用成员函数绑定
	vector< number< int > > vec;
	for( int i = 1; i < 10; ++i )
		vec.emplace_back( i );

	find_if( vec.begin(), vec.end(), bind2nd( mem_fun_ref(&number<int>::less_than), 5 ) );
}
        