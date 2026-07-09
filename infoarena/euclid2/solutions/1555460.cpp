#include <fstream>
using namespace std;
int n;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{
    if(!b) return a;
    return euclid(b,a%b);
}
void citire ()
{
    fin>>n;
    for(int i=0;i<n;i++)
    {   int a,b,x;
        fin>>a>>b;
    fout<<euclid(a,b)<<endl;
    }
}
int main()
{
    citire();
    return 0;
}
