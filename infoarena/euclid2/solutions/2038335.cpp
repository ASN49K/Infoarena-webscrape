#include <iostream>
#include <fstream>

using namespace std;

int lnko(int a,int b)
{
    if(b==0)return a;
    else lnko(b,a%b);
}


int  main()
{
    int i,j,k,l,m,n;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>l;
    for(i=0;i<l;i++){
        f>>n>>m;
        if(n>m)g<<lnko(n,m)<<endl;
        else g<<lnko(m,n)<<endl;
    }

}
