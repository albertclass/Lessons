#include "header.h"

#include "boy.h"
#include "girl.h"

struct Boy::box
{
	Girl mGirlFriend;
};

struct Girl::box
{
	std::string name;
};

Boy::Boy()
	: mBox( new box )
{

}

Boy::~Boy()
{
	delete mBox;
	mBox = nullptr;
}

Girl::Girl()
	: mBox( new box )
{

}

Girl::~Girl()
{
	delete mBox;
	mBox = nullptr;
}

const char* Girl::name()const
{
	return mBox->name.c_str();
}

const char* Boy::GirlFriendName()const
{
	return mBox->mGirlFriend.name();
}

void do_lesson( int rows, int cols )
{
	Boy boy;
	auto name = boy.GirlFriendName();

	printf( "girl friend name is %s\n", name );

	_getch();
}
