#include<fstream>
using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int  cmmdc(int x,int y)
{
    int c;
    while(x>1&&y>1)
    {
        c=x%y;
        if(c==0) 
			return y;
        x=y;
        y=c;
    }
    return 1;
}
int main()
{
    int n,x,y;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y);
    }
}