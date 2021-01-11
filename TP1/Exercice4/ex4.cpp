#include <iostream>
#include <vector>

std::vector<unsigned int> count_lower(std::string str)
{
    int array[26] {};
    for (auto elem : str)
    {
        if (elem >= 'a' && elem <= 'z')
        {
            array[elem - 'a'] += 1;
        }
    } 
    std::vector<unsigned int> final_array;
    for (auto elem : array)
    {
        final_array.emplace_back(elem);
    }
    return final_array;
}

void display_lower_occ(std::vector<unsigned int> tab)
{
    char var = 'a';
    for (auto elem : tab)
    {
        std::cout<<var<<" : "<<elem<<std::endl;
        var += 1;
    }
}

int main() {
    std::string concat;
    while (1)
    {
        std::string var;
        std::cin>>var;
        if (var == "")
        {
            break;
        }
        concat += var;
        std::cout<<concat<<std::endl;
        display_lower_occ(count_lower(concat));
    }
    return 0;
}