#include<iostream>

using namespace std;


class Base
{
    private:
    int a,b;

    public:
    Base(int a=0,int b=0)
    {
        cout<<"Base Constructor Called"<<endl;
        this->a=a;
        this->b=b;
    }

    void setA(int a)
    {
        this->a=a;
    }

    void setB(int b)
    {
        this->b=b;
    }


    int getA() const
    {
        return a;
    }


    int getB() const
    {
        return b;
    }

    virtual void show() const
    {
        cout << "A = " << a << ", B = " << b << endl;
    }

    virtual ~Base()
    {
        cout<<"Base Destructor Called"<<endl;
    }   
};

class Derived:public Base
{
    private:
    int c,d;
    public:

    Derived(int a,int b,int c,int d):Base(a,b)
    {
        cout<<"Derived Constructor Called"<<endl;
        this->c=c;
        this->d=d;
    }

    void setC(int c)
    {
        this->c=c;
    }

    void setD(int d)
    {
        this->d=d;
    }

    int getC() {return c;}
    int getD() {return d;}

    void show() const
    {
        cout<<"C = "<<c<<endl;
        cout<<"D = "<<d<<endl;
    }

    ~Derived()
    {
        cout<<"Derived destructor called"<<endl;
    }

};



int main()
{

    Base* bs = new Derived(1,2,3,4);
    bs->show();
    bs->Base::show();

    bs->setA(100);
    bs->setB(200);

    bs->show();
    bs->Base::show();
    cout<<"Type Casting"<<endl;
    dynamic_cast<Derived*>(bs)->show();
    dynamic_cast<Derived*>(bs)->setA(2000);
    bs->Base::show();
    delete bs;
    return 0;
}