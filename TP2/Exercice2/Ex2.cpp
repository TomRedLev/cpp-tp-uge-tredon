#include "Ex2.h"

Histogram::Histogram() 
    : _count { new unsigned[26] {} } 
{
    std::cout<<" new Histogram without parameters : "<<this<<std::endl;
}

/*
Histogram::Histogram(const Histogram& hg)
    : _count { new unsigned[26] {} }
{ 
    for (auto i = 0; i < 26; i++){
        _count[i] = hg._count[i];
    }
    std::cout<<" new Histogram with parameters : "<<this<<std::endl;
}
*/

Histogram::~Histogram(){
    delete[] _count;
    std::cout<<" Destructed Histogram "<<this<<std::endl;
}

void Histogram::analyze(const std::string& str) {
    int array[26] {};
    for (auto elem : str)
    {
        if (elem >= 'a' && elem <= 'z')
        {
            array[elem - 'a'] += 1;
        }
    } 
    std::vector<unsigned int> final_array;
    auto i = 0;
    for (auto elem : array)
    {
        _count[i] = elem;
        i += 1;
    }
}

Histogram& Histogram::operator=(const Histogram& other)
{
    if (this != &other)
    {
        _count = other._count;
        for (auto i = 0; i < 26; i++){
            _count[i] = other._count[i];
        }
    }
    return *this;
}

void Histogram::print() const {
    char var = 'a';
    auto i = 0;
    while (i < 26)
    {
        std::cout<<var<<" : "<<_count[i]<<std::endl;
        var += 1;
        i += 1;
    }
}

int main() {
    // std::string concat;
    // Histogram hg;
    // while (1)
    // {
    //     std::string var;
    //     std::cin>>var;
    //     if (var == "")
    //     {
    //         break;
    //     }
    //     concat += var;
    //     std::cout<<concat<<std::endl;
    //     hg.analyze(concat);
    //     hg.print();
    // }
    Histogram h1, h2;
    Histogram h3 {Histogram{h1}};
    std::cout<<"h1 : "<<&h1<<"\nh2 : "<<&h2<<"\nh3 : "<<&h3<<std::endl;
    return 0;
}