#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcdr(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcdr(b,a%b);
}
int main()
{
    int n;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        f>>x>>y;
        g<<gcdr(x,y)<<endl;
    }

}
