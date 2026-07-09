#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ofstream g("cmlsc.out");
int i,j,k,nr,n1,n2,v1[257],v2[257],c[1025],cc=0;
void citire()
{
   ifstream f("cmlsc.in");
   f>>n1>>n2;
    for(i=0;i<n1;i++)
    {
        f>>nr;
        v1[nr]++;
    }
    for(j=0;j<n2;j++)
    {
        f>>nr;
        v2[nr]++;
    }
}
void scrie(){
    for(i=0;i<257;i++)
        if(v1[i]!=0&&v2[i]!=0)
        {
            if(v1[i]==v2[i])
            {
                k=v1[i];
                for(j=0;j<k;j++)
                {
                    c[cc]=i;
                    cc++;
                }//c[cc]=i;cc++;
            }
            else
            {  k=abs(v1[i]-v2[i]);
               for(j=0;j<k;j++)
               {
                   c[cc]=i;
                   cc++;
               }
            }
        }
    ofstream g("cmlsc.out");
    g<<cc<<'\n';
    for(i=0;i<cc;i++)
        g<<c[i]<<" ";

}

int main()
{
/*    f>>n1>>n2;
    for(i=0;i<n1;i++)
    {
        f>>nr;
        v1[nr]++;
    }
    for(j=0;j<n2;j++)
    {
        f>>nr;
        v2[nr]++;
    }
    for(i=0;i<257;i++)
        if(v1[i]!=0&&v2[i]!=0)
        {
            if(v1[i]==v2[i])
            {
                k=v1[i];
                for(j=0;j<k;j++)
                {
                    c[cc]=i;
                    cc++;
                }//c[cc]=i;cc++;
            }
            else
            {  k=abs(v1[i]-v2[i]);
               for(j=0;j<k;j++)
               {
                   c[cc]=i;
                   cc++;
               }
            }
        }
    g<<cc<<'\n';
    for(i=0;i<cc;i++)
        g<<c[i]<<" ";*/
        citire();
        scrie();
    return 0;
}
