#include<iostream>

using namespace std;

class Rectangle 
{
    private:
    int length;
    int breadth;

    public:
    Rectangle(int l=1,int b=1)
    {
        cout<<"Constructor called"<<endl;
        length=l;
        breadth=b;
    }

    Rectangle(const Rectangle &r)
    {
        cout<<"Copy Constructor called"<<endl;
        length = r.length;
        breadth = r.breadth;
    }

    void setLength(int l)
    {
        length = l;
    }

    void setBreadth(int b)
    {
        breadth = b;
    }


    int getLength() {return length;}

    int getBreadth() {return breadth;}

    int area()
    {
        return length*breadth;
    }

    int perimeter()
    {
        return 2*(length+breadth);
    }

    bool isSquare();

    ~Rectangle()
    {
        cout<<"Destructor called"<<endl;
    }
    


};

bool Rectangle::isSquare()
{
    return length==breadth;
}

int main() {

    Rectangle r1(10,5); // Constructor called
    cout<<"Area of rectangle = " << r1.area() << endl;
    cout<<"Preimeter of rectangle = "<<r1.perimeter() << endl;
    cout<<"Is R1 square = "<<r1.isSquare()<<endl;
    Rectangle *r2 = new Rectangle(r1); // Copy constructor called
    cout<<"Area of rectangle = " << r2->area() << endl;
    cout<<"Preimeter of rectangle = "<<r2->perimeter() << endl;
    cout<<"Is R2 square = "<<r2->isSquare()<<endl;

    Rectangle r3 = r1; // Copy constructor called
    cout<<"Area of rectangle = " << r3.area() << endl;
    cout<<"Preimeter of rectangle = "<<r3.perimeter() << endl;
    cout<<"Is R3 square = "<<r3.isSquare()<<endl;


    Rectangle *r4 = new Rectangle(*r2); // Copy constructor called
    cout<<"Area of rectangle = " << r4->area() << endl;
    cout<<"Preimeter of rectangle = "<<r4->perimeter() << endl;
    cout<<"Is R4 square = "<<r4->isSquare()<<endl;



    //Rectangle r5 = r2; // This will cause a compilation error because r2 is a pointer, not an object
    // To fix this, we should dereference r2:
    Rectangle r5 = *r2; // This will work, but it will call the copy constructor    
    cout<<"Area of rectangle = " << r5.area() << endl;
    cout<<"Preimeter of rectangle = "<<r5.perimeter() << endl;
    cout<<"Is R5 square = "<<r5.isSquare()<<endl;   

    //delete r5; // Destructor called for r5
    // r5 is a local object, so we don't need to delete it, but if we had dynamically allocated it, we would need to delete it.
    // r1 and r3 are also local objects, so they will be destroyed automatically at the end of the main function scope.     

    delete r4; // Destructor called for r4
    // r2 is still valid, so we can use it after deleting r4
    delete r2; // Destructor called for r2
    // Destructor called for r1 and r3 at the end of main function scope
    return 0;

}