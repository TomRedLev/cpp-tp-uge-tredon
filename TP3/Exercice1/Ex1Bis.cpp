#include <iostream>
#include <algorithm>
#include <deque>
#include <set>
#include <unordered_set>
#include <vector>

int main(int argc, char const *argv[])
{
    // Vector : 
    // std::vector<unsigned long> tab;
    // for (auto i = 2; i <= 100000; i++)
    // {
    //     tab.emplace_back(i);
    // }
    
    // for (auto x = 2; (x*x) <= 100000; x++)
    // {
        
    //     for (auto it = tab.begin(); it != tab.end();)
    //     {
    //         if (*it % x == 0 && *it != x)
    //         {
    //             it = tab.erase(it);
    //         } else {
    //             it++;
    //         } 
    //     }
    // }
    // std::cout << "Number of elements : " << tab.size() << std::endl;

    // Deque : 
    // std::deque<unsigned long> tab;
    // for (auto i = 2; i <= 100000; i++)
    // {
    //     tab.emplace_back(i);
    // }
    
    // for (auto x = 2; (x*x) <= 100000; x++)
    // {
        
    //     for (auto it = tab.begin(); it != tab.end();)
    //     {
    //         if (*it % x == 0 && *it != x)
    //         {
    //             it = tab.erase(it);
    //         } else {
    //             it++;
    //         } 
    //     }
    // }
    // std::cout << "Number of elements : " << tab.size() << std::endl;
    // return 0;

    // Set : 
    // std::set<unsigned long> tab;
    // for (auto i = 2; i <= 100000; i++)
    // {
    //     tab.emplace(i);
    // }
    
    // for (auto x = 2; (x*x) <= 100000; x++)
    // {
        
    //     for (auto it = tab.begin(); it != tab.end();)
    //     {
    //         if (*it % x == 0 && *it != x)
    //         {
    //             it = tab.erase(it);
    //         } else {
    //             it++;
    //         } 
    //     }
    // }
    // std::cout << "Number of elements : " << tab.size() << std::endl;
    // return 0;

    // Unordered set : 
    std::unordered_set<unsigned long> tab;
    for (auto i = 2; i <= 100000; i++)
    {
        tab.emplace(i);
    }
    
    for (auto x = 2; (x*x) <= 100000; x++)
    {
        
        for (auto it = tab.begin(); it != tab.end();)
        {
            if (*it % x == 0 && *it != x)
            {
                it = tab.erase(it);
            } else {
                it++;
            } 
        }
    }
    std::cout << "Number of elements : " << tab.size() << std::endl;
    return 0;
}
