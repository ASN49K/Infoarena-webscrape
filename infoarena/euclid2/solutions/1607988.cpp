#include<fstream>
#include<iostream>
using namespace std;
int x,y,n,i;
int euclid(int a, int b)
{
    int r=0;
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
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
        {
            f>>x>>y;
            g<<euclid(x,y)<<"\n";
        }
}
