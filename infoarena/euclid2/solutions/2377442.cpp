#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a,b,x,maxim;
    ifstream f("euclid2.in");
    f>>a;
    f>>b;
    f.close();
    x=-1;
    if (a>b){
        maxim=b;
    }else
        maxim=a;
    for (int i=2;i<=maxim;i++){
        if (a%i==0 && b%i==0){
            x=i;
        }
    }
    ofstream g("euclid2.out");
    if (x!=-1){
        g<<x;
    }else
        g<<1;
    g.close();
    return 0;
}
