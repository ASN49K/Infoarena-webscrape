#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int div(int a, int b)
{
    int r=a%b;
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return div(b, r);
    }
}
int main()
{

    int n, v[100001];
    f>>n;
    for(int i=0; i<n*2; i++)
    {
        f>>v[i];
    }
    for(int i=0; i<n*2; i+=2)
    {
        g<<div(v[i], v[i+1])<<endl;
    }
    return 0;
}
