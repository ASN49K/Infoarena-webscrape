#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a,int b)
{
    if (a / b == 0) return b;
    if (a < b) return a;
    return (a/b,a%b);
}

void main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    
    int n,a,b;
    f>>n;
    for (int i=0;i<n;i++)
    {
        f >> a >> b;
        if (a>b) g<<euclid(a,b);
        else g << euclid(b,a);
    }
    
    f.close();
    g.close();
    
    retrun 0;
}
