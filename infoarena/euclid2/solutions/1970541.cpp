#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int  a, b, t;
int main()
{
    f>>t;
    while(t)
    {

        f>>a>>b;
        while(b)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        if(a==1)
            g<<0;
        else
            g<<a;
        g<<endl;
            t--;
    }
    f.close();
    g.close();
    return 0;
}
