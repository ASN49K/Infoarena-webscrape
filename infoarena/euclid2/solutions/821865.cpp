#include<fstream>
using namespace std;
int main()
{
    long long T,i,a,b,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    if ((T>=1)&&(T<=2000000000))
    for (i=1;i<=T;i++)
    {f>>a>>b;
    if ((a>=2)&&(a<=2000000000)&&(b>=2)&&(b<2000000000))
    do { r=a%b;a=b;b=r;} while(r!=0);
    g<<a<<endl;}
    f.close();
    g.close();
    return 0;
}
