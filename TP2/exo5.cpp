#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)

	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
	//int pivot = origin.size()-1;
	//int valeurPivot = origin[pivot];
	
	// split
	for(int i=0; i< first.size(); i++){
		first[i]=origin[i];
	}
	for (int i=0; i<second.size(); i++){
		for(int j=first.size(); j<= origin.size(); j++){
			second[i] = origin[j];
		}
		
	}
	// recursiv splitAndMerge of lowerArray and greaterArray
	splitAndMerge(first);
	splitAndMerge(second);

	// merge
	merge(first, second, origin);

}

void merge(Array& first, Array& second, Array& result)
{
	for (int i =0; i<result.size()+1; i++){
		if (first[i]<second[i]){
			result[i]= first [i];
		}
		else {
			result[i]= second[i];
		}
	}
}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
