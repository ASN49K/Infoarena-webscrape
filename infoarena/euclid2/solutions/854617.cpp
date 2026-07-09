#include<fstream>
using namespace std;

int func(int a,int b)
{
    if(!b)return a;
    return func(b,a%b);
}
int main()
{   ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int n,a,b;
    f>>n;
    while(f>>a>>b)
    {
            g<<func(a,b)<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
