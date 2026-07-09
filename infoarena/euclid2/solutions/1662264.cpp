#include <iostream>
#include <fstream>
using namespace std;
int n,i,j,nr=0;
bool v[2000005];
int main()
{
    ifstream f("ciur.in");
    ofstream g("ciur.out");
    f >> n;
    for(i=1;i<=n;i++)
        v[i]=true;
    for(i=2;i<=n;i++)
        if(v[i]==true)
            for(j=2;j*i<=n;j++)
                v[i*j]=false;
    for(i=2;i<=n;i++)
        if(v[i]==true) nr++;
    g << nr;
    f.close();g.close();
    return 0;
}
