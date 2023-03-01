
/* Sans QT creator*/

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

typedef unsigned int uint ;
typedef int int32 ;
typedef unsigned short int uint8 ;
typedef unsigned long int uint64 ;


void slow_sort(std::vector<int> & toSort){
    for (uint i=0; i<toSort.size(); i++)
    {
        for (uint j=0; j<toSort.size(); j++)
        {
            if (toSort[j] > toSort[i])
                std::swap(toSort[i], toSort[j]);
        }
    }
}

int main(int argc, char *argv[])
{
	std::vector<int> tab({8,1,5,9,11,3});
    slow_sort(tab);

    for (int i=0; i<tab.size(); i++){
        std::cout << tab[i] << endl;

    }
}

