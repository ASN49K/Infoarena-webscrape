#include <iostream>
#include <fstream>

using namespace std;

ofstream g("euclid2.out");

void cmmdc(int a, int b){
    int r;
    do{
        r=a%b;
        a=b;
        b=r;
    }while(r!=0);
    g<<a<<'\n';
}

int main()
{
    long T;
    int a,b,r;
    ifstream f("euclid2.in");
    f>>T;
    while(T>0){
        f>>a>>b;
        cmmdc(a,b);
        T--;
    }
    return 0;
}
