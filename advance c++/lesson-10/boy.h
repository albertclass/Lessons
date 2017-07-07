#pragma once
#include "human.h"

class Boy : public Human
{
private:
	struct box;
	box * mBox;
private:
	virtual bool Thinking() override
	{
		printf( "boy thinking" );
		return true;
	}

public:
	Boy();
	~Boy();

	const char* GirlFriendName()const;
};