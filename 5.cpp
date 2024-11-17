#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Vector{
    private: int x,y;
    public:
    void input(int x1,int y1){
        x=x1;
        y=y1;
    }
    Vector add(Vector a){
        Vector b;
        b.x=this->x+a.x;
        b.y=this->y+b.y;
        return b;


    }
    void print(){
        cout<<x<<","<<y<<endl;
    }
    void dir(){
        double square = x*x+y*y;
        cout<<setprecision(4)<<sqrt(square)<<endl;

    }
};
int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    Vector a,b;
    a.input(x1,y1);
    b.input(x2,y2);
    Vector c =a.add(b);
    c.print();
    c.dir();

    return 0;
}