#include <iostream>
#include <fstream>

using namespace std;

int Euclid(int a, int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int n, a, b, c;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=0; i<n; i++)
    {
        f>>a>>b;
        if(a<b)
        {
            int aux=a;
            a=b;
            b=aux;
        }
        g<<Euclid(a, b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
