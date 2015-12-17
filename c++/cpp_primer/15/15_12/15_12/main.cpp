//
//  main.cpp
//  15_12
//
//  Created by nichola on 15/11/30.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>

using namespace::std;

class Figure {
public:
    Figure(const double x, const double y):xSize(x),ySize(y) {
    }
protected:
    double xSize,ySize;
};

class Figure2D:public Figure {
public:
    Figure2D(const double x, const double y):Figure(x,y) {
    }
    virtual double area() = 0;
    virtual double permeler() = 0;
private:
};

class Figure3D:public Figure {
public:
    Figure3D(const double x, const double y,const double z):Figure(x,y),zSize(z) {
    }
    virtual double cubage() = 0;
protected:
    double zSize;
};

class Retangle:public Figure2D {
public:
    Retangle(const double x, const double y):Figure2D(x,y) {
    }
    double area() {
        return xSize * ySize;
    }
    double permeler() {
        return  2 * (xSize + ySize);
    }
};

class Sphere:public Figure3D {
public:
    Sphere(const double x, const double y, const double z):Figure3D(x, y, z) {
    }
    double cubage() {
        return 3.14 * (xSize / 2) * (xSize / 2);//pi * R * R
    }
};

int main(int argc, const char * argv[]) {
    Retangle rtg(10,20);
    cout << rtg.area() << endl;
    cout << rtg.permeler() << endl;
    Sphere sph(10,10,10);
    cout << sph.cubage() << endl;
    
    return 0;
}
