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


void selectionSort(vector<int> & toSort){
	for (uint i=0; i<toSort.size(); i++)
    {
        int min = i;
        for (uint j=i; j<toSort.size(); j++)
        {
            if (toSort[j] < toSort[min] ){
                min=j;
            }
            if (min != i){
            swap(toSort[i], toSort[min]);
            }
        }
        
    }
}

int main(int argc, char *argv[])
{
	vector<int> tab({8,1,5,9,11,3});
    selectionSort(tab);

    for (int i=0; i<tab.size(); i++){
        cout << tab[i] << endl;

    }
}
