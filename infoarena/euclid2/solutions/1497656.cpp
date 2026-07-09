#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

class Group{
private:
    int a;
    int b;

public:
    Group(int newA, int newB);
    int getA(){
        return a;
    }

    int getB(){
        return b;
    }

    void setA(int newA){
        a = newA;
    }

    void setB(int newB){
        b = newB;
    }
};
Group::Group(int newA, int newB){
    a = newA;
    b = newB;
}

class Euclid{

private:
    int n;
    int x, y;

public:
    Euclid(int newN);
    void makeIt(){
        f>>n;
        for(int i=0; i<n; ++i){
            f>>x>>y;
            Group grup(x,y);

            while(grup.getA() != grup.getB()){

                if(grup.getA() < grup.getB())
                    grup.setB(grup.getB()-grup.getA());
                else grup.setA(grup.getA()-grup.getB());

            }

            g<<grup.getA()<<endl;

        }

    }

};
Euclid::Euclid(int newN){
    n = newN;
}
int main()
{


    Euclid euclid(3);
    euclid.makeIt();
}
