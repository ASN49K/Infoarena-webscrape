#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n,a,b,x,maxim;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for (int i=0;i<n;i++){
        f>>a;
        f>>b;
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
    if (x!=-1){
        g<<x;
    }else
        g<<1;
    g<<endl;
    }
    g.close();
    f.close();
    return 0;
}
