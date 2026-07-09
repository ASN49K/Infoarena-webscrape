#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int n;
int cmmdc(int x, int y)
{
    if(x==0)
        return 0;
    if(y==0)
        return 0;
    if(x<y)
    {
        swap(x,y);
    }
    while(y)
    {
        int r=x%y;
        x=y;
        y=r;
    }
    return x;
}
void citire()
{
    fin>>n;
    while(n)
    {
        int x,y;
        fin>>x>>y;
       fout<<cmmdc(x,y)<<endl;
       n--;
    }
}

int main()
{
    citire();
    return 0;
}
