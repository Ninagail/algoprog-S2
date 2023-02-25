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


void bubbleSort(vector<int> & toSort){
	for (uint i=0; i<toSort.size()-1; i++){
		if (toSort[i]>toSort[i+1]){
			swap(toSort[i], toSort[i+1]);
		}
	}
	
}


int main(int argc, char *argv[])
{
	vector<int> tab({8,1,5,9,14,3});
    bubbleSort(tab);

    for (int i=0; i<tab.size(); i++){
        cout << tab[i] << endl;

    }
}
