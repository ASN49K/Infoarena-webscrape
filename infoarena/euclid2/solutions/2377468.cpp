#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,ax,ay,c,t;
    f>>n;
    for(int i=0;i<n;i++){
            f>>ax;
            f>>ay;
            a=max(ax,ay);
            c=min(ax,ay);
            while(a%c!=0){
                t=a%c;
                a=c;
                c=t;
            }
            g<<t<<"\n";
    }
    g.close();
    f.close();
    return 0;
}
