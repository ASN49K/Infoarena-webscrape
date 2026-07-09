#include <fstream>
#include <iostream>
using namespace std;

int gcm(int a, int b)
{
    if(!b) return a;
    else return gcm(b,a%b);
}
int main()
{
    ifstream f("a.in");
    ofstream g("a.out");
    int n;
    f>>n;
    int a,b;
    while(n--)
    {
        f>>a>>b;
        g<<gcm(a,b)<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
