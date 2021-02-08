#pragma once

#include "Person.h"

class Phone
{
public:
	Phone(const Person& owner)
		: _owner { owner }
	{}

	virtual void ring() const { _owner.answer_phone(); }

	virtual ~Phone() {}

protected:
	const Person& _owner;
};
