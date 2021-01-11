#include <iostream>

int main()
{
    /*
    int v;
    int w = 2;
    int x {};
    int y { 2 };
    int z(2);
    std::cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<" "<<std::endl;
    */
    short s0;
    int   i1 = 2;
    bool  b2{false};
    bool  b3{(bool) i1};
    bool* b4;
    unsigned       u5{0x10};
    unsigned short us6 = -10;
    unsigned long  ul7{b3 + u5 + us6};
    char c8{'a'};
    char c9 = -10;
    double  d10{static_cast<double>(i1)};
    double* d11{&d10};
    double& d12 = *d11;
    const double d13{.0f};
    const int    i14 = i1;
    int* i15 = &i1;
    int* i16 = (int *) &b2;
    int  i17 = *i15;
    int& i18{(int&) i14};
    const int* i19{nullptr};
    const bool b20 = false;
    std::cout<<s0<<" "<<*i15<<" "<<ul7<<std::endl;
}