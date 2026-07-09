#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int algeu(int x1,int x2)
{
    if(x2!=0)
        return algeu(x2,x1%x2);
    return x1;

}
int main()
{
    int t,x1,x2;
    f>>t;
    while(t--)
    {
        f>>x1>>x2;
        g<<algeu(x1,x2);
    }
    return 0;
}
