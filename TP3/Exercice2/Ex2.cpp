#include <iostream>
#include <set>
#include <vector>
#include <string>

class PhoneNumber {
    std::vector<int> pn;
    
    public :

}

class NumAndName {
    const std::set<std::string, PhoneNumber> _list;
  
public:
  
};

bool operator<(NumAndName a, NumAndName b)
{
    if (a.getName() < b.getName())
    {
        return true;
    }
    return false;
}


int main() {
  
  return 0;
}