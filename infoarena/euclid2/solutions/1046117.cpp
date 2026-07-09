#include <fstream>

using namespace std;

fstream f("euclid2.in", ios::in);
fstream g("euclid2.out", ios::out);


int cmmdc(int a, int b)
{
    if( (!a) || (!b) ) return a+b;
    if(a>b) return cmmdc(a%b,b);
    else return cmmdc(b,b%a);
}

int main()
{
    int t,a,b;
    f>>t;
    for(int i=0;i<t;i++)
        {
            f>>a>>b;
            g<<cmmdc(a,b)<<'\n';
        }
    f.close();
    g.close();

}
