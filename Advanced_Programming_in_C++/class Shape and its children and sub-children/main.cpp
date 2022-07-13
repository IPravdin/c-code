#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

//Class Shape and its children and sub-children
class Shape {
protected:
    string name_protected = "Placeholder";
public:
    virtual void area() {
        cout << "Your area could be here" << endl;
    }
    void displayName() {
        cout << name_protected << endl;
    }
};

class angleShape : public Shape {
protected:
    float width_protected, height_protected;

public:
    angleShape(float width = 0, float height = 0, string name = "") {
        width_protected = width;
        height_protected = height;
        name_protected = name;
    }
    virtual ~angleShape() {
        cout << "Object angleShape destroyed" << endl;
    }
};
class curvedShape : public Shape {
protected:
    float radius_protected;
    float pi = M_PI;

public:
    curvedShape(float radius = 0.0f, string name = "") {
        radius_protected = radius;
        name_protected = name;
    }
    virtual ~curvedShape() {
        cout << "Object curvedShape destroyed" << endl;
    }
};

class Rectangle : public angleShape {
public:
    Rectangle(float w = 0.0f, float h = 0.0f, string name = "") : angleShape(w,h,name) {}
    ~Rectangle() override {
        cout << "Object Rectangle destroyed" << endl;
    }

    void area() override {
        cout << "Class area: " << (width_protected * height_protected) << endl;
    }
};
class Triangle : public angleShape {
public:
    Triangle(float w = 0.0f, float h = 0.0f, string name = "") : angleShape(w, h, name) {}
    ~Triangle() override {
        cout << "Object Triangle destroyed" << endl;
    }

    void area() override {
        cout << "Class area: " << (width_protected * height_protected / 2) << endl;
    }
};
class Trapezoid : public angleShape {
public:
    Trapezoid(float w1 = 0.0f, float w2 = 0.0f, float h = 0.0f, string name = "") {
        width_protected = w1 + w2;
        height_protected = h;
        name_protected = name;
    }
    ~Trapezoid() override {
        cout << "Object Trapezoid destroyed" << endl;
    }

    void area() {
        cout << "Class area : " << (width_protected * height_protected / 2) << endl;
    }
};

class Circle : public curvedShape {
public:
    Circle(float radius = 0.0f, string name = "") : curvedShape(radius, name) {}
    ~Circle() override {
        cout << "Object Circle destroyed" << endl;
    }

    void area() override {
        cout << "Class area: " << (pi * radius_protected * radius_protected) << endl;
    }
};
class Ellipse : public curvedShape {
public:
    Ellipse(float radius1 = 0.0f, float radius2 = 0.0f, string name = "") {
        radius_protected = radius1 * radius2;
        name_protected = name;
    }
    ~Ellipse() override {
        cout << "Object Ellipse destroyed" << endl;
    }

    void area() override {
        cout << "Class area: " << (pi * radius_protected) << endl;
    }
};

int main()
{
    Shape* shape;
    Rectangle rec(10, 7, "Rectangle");
    Triangle tri(10, 5, "Triangle");
    Trapezoid trap(10, 7,5, "Trapezoid");
    Circle cir(5, "Circle");
    Ellipse ell(5, 3, "Ellipse");

    //Rectangle
    shape = &rec;
    shape->displayName();
    shape->area();
    cout << endl;

    //Triangle
    shape = &tri;
    shape->displayName();
    shape->area();
    cout << endl;

    //Trapezoid
    shape = &trap;
    shape->displayName();
    shape->area();
    cout << endl;

    //Circle
    shape = &cir;
    shape->displayName();
    shape->area();
    cout << endl;

    //Ellipse
    shape = &ell;
    shape->displayName();
    shape->area();

    return 0;
}

