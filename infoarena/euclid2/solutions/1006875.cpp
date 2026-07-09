#include<iostream>
#include<fstream>
using namespace std;
int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    else
        return cmmdc(b, a%b);

}
int main()
{
    int i,n,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    g.close();
    f.close();
    return 0;
}
