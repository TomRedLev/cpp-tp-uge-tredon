#include "Person.h"
#include "Phone.h"
#include "HomePhone.h"
#include "MobilePhone.h"

int main()
{
    Person paul { "Paul", 3 };
    HomePhone  far_phone { paul, -10 };
    MobilePhone mobile_phone { paul };

    const Phone& normal_phone = mobile_phone;
    normal_phone.ring();

    return 0;
}
