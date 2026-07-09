#include <iostream>
#include <fstream>

using namespace std;


int  main()
{
    int i,j,k,l,m,n;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>l;
    for(i=0;i<l;i++){
        f>>n>>m;
        while(1){
            n=n%m;
            if(n==0)break;
            m=m%n;
        }
        g<<m<<" ";
    }

}
