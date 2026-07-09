#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,i,v[100],a[100],u,j;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i]>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        u=0;
            for(j=v[i];j>=1;j--)
          {
            if(u==0)
            {
                if(v[i]%j==0)
              {
                if(a[i]%j==0)
                {
                    g<<j<<endl;
                    u=1;
                }
              }
            }

        }
    }
    return 0;
}
