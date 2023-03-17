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
// (j-1)/2 pour avoir l'indice du parent
int Heap::leftChild(int nodeIndex)
{
	int i=0;
	this->nodeIndex =i;
	this->left->nodeIndex = i*2+1;
	
    return 0;
}

int Heap::rightChildIndex(int nodeIndex)
{
	int i=0;
	this->nodeIndex =i;
	this->right->nodeIndex= i*2+2;
    return 0;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i

	int i = heapSize;
}

void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	if(this->)
	int i_max = nodeIndex;
}

void Heap::buildHeap(Array& numbers)
{

}

void Heap::heapSort()
{

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
