#include<fstream.h>
ifstream intrare("euclid2.in");
ofstream iesire("euclid2.out");
int t;
int main()
{
    intrare>>t;
    long long int a,b,r;
    for(int i=1;i<=t;i++)
    {
            intrare>>a>>b;
            while(b!=0)
            {
                       r=a%b;
                       a=b;
                       b=r;
            }
            iesire<<a<<"\n";    
    }
    return 0;
}
            
            
