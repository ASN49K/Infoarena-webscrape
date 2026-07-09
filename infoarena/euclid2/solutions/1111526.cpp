#include<iostream>
#include<fstream>
using namespace std;
int main()
{
   long long int n,i,v[2005],d[2005],r[2005],s;
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
        f>>d[i];
    }

    for(i=1;i<=n;i++)
    {
            {
                for(s=1;s<=v[i]*d[i];s++)
                {
                    if((v[i]%s==0)&&d[i]%s==0)
                        r[i]=s;
                }
            }
    }
    for(i=1;i<=n;i++)
    {
        g<<r[i]<<endl;
    }
    return 0;
}


