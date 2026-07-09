#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n,a,b,q,maxim,r,x,aux;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for (int i=0;i<n;i++){
        f>>a;
        f>>b;
        x=1;
        q=0;
        maxim=max(a,b);
        r=min(a,b);
    while (q==0){
        if (maxim%r==0){
            x=r;
            q=1;
            break;
        }
        aux=r;
        r=maxim%r;
        maxim=aux;
    }
        g<<x<<endl;
    }
    f.close();
    g.close();
    return 0;
}
