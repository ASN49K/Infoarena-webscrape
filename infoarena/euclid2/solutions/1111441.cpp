#include<iostream>
#include<fstream>
using namespace std;
int main()
{
   long long int n,i,v[20000],d[20000],s,r;
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
                for(s=1;s<=v[i];s++)
                {
                    if((v[i]%s==0)&&d[i]%s==0)
                        r=s;

                }
            }
            g<<r<<endl;
    }
    return 0;
}
