#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b, c;
int main()
{
    int i;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        if(a<b)swap(a,b);
        while(b)
        {
            c=b;
            b=a%b;
            a=c;
        }
        g<<a<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
