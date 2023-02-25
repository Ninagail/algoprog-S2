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

void recursivQuickSort(vector<int> & toSort)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	
	vector<int> lowerArray = w->newArray(size);
	vector<int> greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

	// split
	
	// recursiv sort of lowerArray and greaterArray

	// merge
}

void quickSort(vector <int> & toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	vector<int> tab({8,1,5,9,11,3});
    insertionSort(tab);

    for (int i=0; i<tab.size(); i++){
        cout << tab[i] << endl;

    }
}
