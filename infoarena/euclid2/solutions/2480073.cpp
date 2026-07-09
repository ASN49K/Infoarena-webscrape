#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int calculeazaCmmdc(int a , int b)
{
    while(b!=0)
    {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int nrPerechi = 0;
    int x = 0 , y = 0;

    f >> x;
    nrPerechi = x;
    for (int i = 0 ; i < nrPerechi ; i++)
    {
        f >> x >> y;
        int cmmdc = calculeazaCmmdc(x,y);
        g << cmmdc << '\n';
    }
}
