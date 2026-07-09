#include <iostream>
#include <fstream>
using namespace std;
int n,c,v[100],a[100],b[100];
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out")
    for(int i=1;i<=n;i++)
        {
            f>>a[i];
            f>>b[i];
        }
    for(int i=1;i<=n;i++)
        {
            while(b[i]!=0)
        {
            c=a[i]%b[i];
            a[i]=b[i];
            b[i]=c;
        }
        v[i]=a[i];
        }
    for(int i=1;i<=n;i++)
        g<<v[i]<<endl;
    return 0;
}
