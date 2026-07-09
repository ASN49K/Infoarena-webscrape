#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    long T;
    int a,b,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    while(T>0){
        f>>a>>b;
        do{
            r=a%b;
            a=b;
            b=r;
        }while(r!=0);
        g<<a<<'\n';
        T--;
    }
    return 0;
}
