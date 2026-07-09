#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r;
int main()
{
    f>>a>>b;
    if(a==0&&b==0)
        g<<-1;
    else
        if(b==0)
            g<<a;
        else
        {
            r=a%b;
            while(r!=0)
            {
                a=b;
                b=r;
                r=a%b;
            }
            g<<b;
        }
return 0;
}
