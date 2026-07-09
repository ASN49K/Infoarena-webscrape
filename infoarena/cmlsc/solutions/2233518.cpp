#include <iostream>
#include <fstream>
using namespace std;
int a,b,v[1026],s[1026],i,j,k,mx,sc[1026];
int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in>>a>>b;
    for(i=1;i<=a;i++)
    {
        in>>v[i];
    }
    for(i=1;i<=b;i++)
    {
        in>>s[i];
    }
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=b;j++)
        {
            if(v[i]==s[j])
            {
                mx++;
                sc[mx]=s[j];
                for(k=1;k<j;k++)
                {
                    s[k]=0;
                }
            }
        }
    }
    out<<mx<<"\n";
    for(i=1;i<=mx;i++)
    {
        out<<sc[i]<<" ";
    }
    return 0;
}
