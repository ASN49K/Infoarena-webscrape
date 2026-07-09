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
        minim=min(a,b);
        maxim=max(a,b);
        do{
            a=maxim;
            b=minim;
            a=a-b;
            minim=min(a,b);
            maxim=max(a,b);
            if(maxim%minim==0)
                x=minim;
        }while(maxim%minim!=0);
        g<<x<<endl;
    }
    f.close();
    g.close();
    return 0;
}
