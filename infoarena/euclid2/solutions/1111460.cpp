#include<iostream>
#include<fstream>
using namespace std;
int main()
{
   long long int n,i,s,r;
   long long v[n*2+2];
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n*2;i++)
    {
        f>>v[i];
    }
    if(n%2==0)
    for(i=1;i<=n*n;i=i+2)
    {
            {
                for(s=1;s<=v[i];s++)
                {
                    if((v[i]%s==0)&&v[i+1]%s==0)
                        r=s;

                }
            }
            g<<r<<endl;
    }
    if(n%2==1)
    for(i=1;i<=n*2;i=i+2)
    {
            {
                for(s=1;s<=v[i];s++)
                {
                    if((v[i]%s==0)&&v[i+1]%s==0)
                        r=s;

                }
            }
            g<<r<<endl;
    }

    return 0;
}
