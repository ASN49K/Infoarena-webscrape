#include <iostream>
#include <fstream>

using namespace std;
ifstream input("cmlsc.in");
ofstream output("cmlsc.out");
int v[1024],x[1024],sir[1024];
int main()
{
    int i,n,m,j,nr=0;
    bool sortat=false;
    input>>m>>n;
    for(i=0; i<m; i++)
    {
        input>>v[i];
    }
    for(i=0; i<n; i++)
    {
        input>>x[i];
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(v[i] == x[j])
            {
                sir[nr]=v[i];
                x[j]=699;
                nr++;
            }
        }
    }
    while(!sortat)
    {
        sortat=true;
        for(i=0; i<nr-1; i++)
        {
            if(sir[i]>sir[i+1])
            {
                swap(sir[i],sir[i+1]);
                sortat=false;
            }
        }
    }
    output << nr << '\n';
    for(i=0; i<nr; i++)
    {
        output << sir[i] << " ";
    }
}
