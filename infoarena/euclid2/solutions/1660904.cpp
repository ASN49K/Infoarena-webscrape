#include <iostream>
#include <fstream>
using namespace std;
int n,c,v[100],a[100],b[100],t;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=1;i<=t;i++)
        {
            f>>a[i];
            f>>b[i];
        }
    for(int i=1;i<=t;i++)
        {
            while(b[i]!=0)
        {
            c=a[i]%b[i];
            a[i]=b[i];
            b[i]=c;
        }
        v[i]=a[i];
        }
    for(int i=1;i<=t;i++)
        g<<v[i]<<endl;
    return 0;
}
