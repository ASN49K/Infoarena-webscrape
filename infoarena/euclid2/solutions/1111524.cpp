#include<iostream>
#include<fstream>
using namespace std;
int main()
{
   long long int n,i,s,r;
   long long v[n*2+1];
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
    f>>n;
    for(i=0;i<=n*2-1;i++)
    {
        f>>v[i];
    }
    for(i=0;i<=n*2-1;i++)
    {
            {
                for(s=1;s<=v[i]*v[i+1];s++)
                {
                    if((v[i]%s==0)&&v[i+1]%s==0)
                        r=s;

                }
            }
            if(i%2==0)
            g<<r<<endl;
    }
    return 0;
}


