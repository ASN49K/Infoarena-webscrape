#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,b,ax,ay,r;
    f>>n;
    for(int i=0;i<n;i++){
            f>>ax;
            f>>ay;
            if(ax>ay){
                a=ax;
            }else a=ay;
            r=1;
    for(int j=2;j<=a;j++){
        if(ax%j==0 && ay%j==0){
            r=j;
        }
    }
    g<<r<<endl;
    }
    g.close();
    f.close();
    return 0;
}
