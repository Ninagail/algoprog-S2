#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;
// i*2+1 pour l'indice de l'enfant gauche
// i*2+2 pour l'indice de l'enfant droit
// (i-1)/2 pour avoir l'indice du parent
int Heap::leftChildIndex(int nodeIndex)
{
    return nodeIndex*2+1;
}

int Heap::rightChildIndex(int nodeIndex)
{
    return nodeIndex*2+2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i = heapSize;
	this->get(i)=value;
	while(i>0 && this->get(i)>this->get((i-1)/2)){
		swap(i,(i-1)/2);
		i=(i-1)/2;
	}

}

void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i_max = nodeIndex;

	if(this->leftChildIndex(nodeIndex)<heapSize && this->get(leftChildIndex(nodeIndex))>this->get(i_max)){
		i_max = this->leftChildIndex(nodeIndex);
	}
	if(this->rightChildIndex(nodeIndex)<heapSize && this->get(rightChildIndex(nodeIndex))>this->get(i_max)){
		i_max = this->rightChildIndex(nodeIndex);
	}
	if(nodeIndex!=i_max){
		swap(nodeIndex, i_max);
		heapify(heapSize, i_max);
	}
	
}

void Heap::buildHeap(Array& numbers)
{
	for(int i=0; i<numbers.size(); i++){
		insertHeapNode(i, numbers[i]);
	}
}

void Heap::heapSort()
{
	for(int i = this->size()-1; i>0; i--){
		swap(0,i);
		heapify(i,0);
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
