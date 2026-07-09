#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,x,y,r;
    f>>n;
    for(int i=1;i<=n;i++){
        f>>x>>y;
        r=x%y;
    while(r!=0)
    {
        x=y;
        y=r;
        r=x%y;
    }
        g<<y<<endl;}
    return 0;
}
