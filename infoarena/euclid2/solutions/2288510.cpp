#include<fstream>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int a,b,r;
    for(f>>a;f>>a>>b;)
    {
        for(;r=a%b;a=b,b=r);
        g<<b<<'\n';
    }
    return 0;
}
