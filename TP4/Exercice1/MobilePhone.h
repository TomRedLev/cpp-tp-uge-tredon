#pragma once

#include "Phone.h"

class MobilePhone : public Phone
{
    public : 
        MobilePhone(const Person& person) 
            : Phone {person}
        {}

};