#include <fstream>

using namespace std;

 ifstream x ("euclid2.in");
 ofstream y ("euclid2.out");

 int T;

int main()
{
    int i;

    x>>T;

    int a,b,c;

    for(i=1;i<=T;i++)
    {
        x>>a>>b;

        while(a%b!=0)
           if(a>b)
           {
               a=a%b;
           }
           else
           {
               b=b%a;
           }

        y<<b<<'\n';
    }

    return 0;
}
