#include<fstream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int T,a,b,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<gcd(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
