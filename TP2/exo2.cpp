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


void insertionSort(vector<int> & toSort){
	//Array &sorted=w->newArray(toSort.size());
	vector<int> sorted[toSort.size()];
	sorted[0] = toSort[0];
	for(uint i=1; i<toSort.size(); i++){
		for(uint j=0; j<toSort.size(); j++){
			if(toSort[i]<toSort[j]){
				sorted.insert(j, toSort[i]);
			
		}
		else{
			sorted[j]=toSort[i];
		}
		}
		
	}

	// insertion sort from toSort to sorted
	
	toSort=sorted; // update the original array


}

int main(int argc, char *argv[])
{
	vector<int> tab({8,1,5,9,11,3});
    insertionSort(tab);

    for (int i=0; i<tab.size(); i++){
        cout << tab[i] << endl;

    }
}
