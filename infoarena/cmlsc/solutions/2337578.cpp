#include <iostream>
#include <fstream>
using namespace std;


ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main()
{
    int n,m;
    int v1[1024],v2[1024];
    in>>n>>m;

    for(int i=1;i<=n;i++)
    in>>v1[i];
    for(int i=1;i<=m;i++)
    in>>v2[i];

    int v3[1024];
    int l=0;
    int poz=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=poz;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                l++;
                v3[l]=v2[j];
                poz=j+1;
                break;
            }

        }
    }
out<<l<<"\n";
    for(int i=1;i<=l;i++)
    out<<v3[l]<<" ";


    return 0;
}
