#include <fstream>
using namespace std;
int n;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{   int t;
        while (b != 0)
       {t = b;
       b = a % b;
       a = t;
       }
       return a;
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
