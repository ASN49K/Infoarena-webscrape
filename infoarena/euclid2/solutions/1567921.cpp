#include <iostream>
#include<fstream>
using namespace std;
int v[20001],a[20001],n;
    int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int i,r;
    in>>n;
    for(i=1;i<=n;i++)
    {in>>v[i];
    in>>a[i];}
    for(i=1;i<=n;i++)
    {
        while(a[i]!=0)
        {r=v[i]%a[i];
        v[i]=a[i];
        a[i]=r;}
        out<<v[i]<<"\n";
    }
    in.close();
    out.close();
}

