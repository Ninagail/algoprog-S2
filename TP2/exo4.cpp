#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes
	int pivot = (size-1)/2;
	int valeurPivot = toSort[pivot];

	// split
	if (size>1){
		for (int i=0; i<size; i++){
			if(pivot != i){
				if (valeurPivot>toSort[i]){
					lowerArray[lowerSize]=toSort[i];	
					lowerSize++;
				}	
				else {
					greaterArray[greaterSize]=toSort[i];
					greaterSize++;
						
				}
			}	
		}
		

		// recursiv sort of lowerArray and greaterArray
		recursivQuickSort (lowerArray, lowerSize);
		recursivQuickSort (greaterArray, greaterSize);

		// merge

		for (int i=0; i < lowerSize; i++){
			toSort[i]=lowerArray[i];
		}
		toSort[lowerSize] = valeurPivot;
		for (int i=0; i < greaterSize; i++){
			toSort[i+(lowerSize+1)]=greaterArray[i];
		}

		return;
	}
	// else{
	// 	return;
	// }
	
	


}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}


