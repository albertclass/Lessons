#pragma once
#include "human.h"

class Girl : public Human
{
private:
	struct box;
	box* mBox;

private:
	virtual bool Thinking() override
	{
		printf( "boy thinking" );
		return true;
	}

public:
	Girl();
	~Girl();

	const char* Girl::name()const;
};