#include<fstream>
using namespace std;
int t,x,y,m,i;
int cmmdc(int a, int b )
{
    int r;
    while(b)
            {
                 r=a%b;
                 a=b;
                 b=r;
            }
            return a;
}
int main()
{
    ifstream f("euclid.in");
    ofstream g("euclid.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
                     f>>x>>y;
                    m=cmmdc(x,y);
                     g<<m<<endl;
                     
                     
    }
    f.close();
    g.close();
return 0;
}
