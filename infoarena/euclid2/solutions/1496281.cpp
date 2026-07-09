#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a,int b)
{
    if (b == 0) return a;
    return euclid(b, a%b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    
    int n,a,b;
    f>>n;
    for (int i=0;i<n;i++)
    {
        f >> a >> b;
        g << euclid(a,b) << endl;
    }
    
    f.close();
    g.close();
    
    return 0;
}
