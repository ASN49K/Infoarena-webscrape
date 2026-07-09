#include <iostream>
#include <fstream>
using namespace std;
 int n,x,y;
int euclid(int a,int b)
{
    if (b==0) return a;
    else
        return euclid(b,a%b);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    while(n)
    {
        fin>>x>>y;
        fout<<euclid(x,y)<<'\n';
        n--;
    }
    return 0;
}
