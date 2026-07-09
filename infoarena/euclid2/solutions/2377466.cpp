#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a,b,n,minim,maxim,x;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=0;i<n;i++){
        f>>a>>b;
        x=1;
        maxim=max(a,b);
        minim=min(a,b);
        while(maxim%minim!=0){
            a=maxim%minim;
            maxim=minim;
            minim=a;
        }
        g<<minim<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
