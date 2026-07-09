#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{

int a,b,n,i;
    f>>n;
    for(i=1;i<=n;i++)
    {   f>>a>>b;
        while(a)
        {
            if(a>0 && b!=0)
                a=a%b;
            if(a!=0 && b>0)
                b=b%a;
            if(a==0)
                g<<b<<" ";
            if(b==0)
                g<<a<<" ";

        }
    }
    return 0;
}
