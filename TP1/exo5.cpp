#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    // recursiv Mandelbrot
    /*
    z(0) = 0
    z(n+1) = z(n)^2 + c(point)
    */
    z.x = (z.x*z.x - z.y*z.y) + point.x;
    z.y = (2*z.y*z.x) + point.y;

    float norme = sqrt((z.x*z.x)+(z.y*z.y));

    // check n
    if (n == 0){
        return 0;
    }
    else if (norme > 2){
        return 1;
    }
    else {
        // otherwise, process the square of z and recall
        // isMandebrot
        return isMandelbrot(z, n-1, point);
    }
    
    

    // check length of z
    // if Mandelbrot, return 1 or n (check the difference)
    
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



