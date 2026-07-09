#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long n,i,a,b;
int main()
{
    fin >> n;
    for(i=1;i<=n;i++)
    {
        fin >> a >> b;
        while(b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        fout << a << endl;
    }
    return 0;
}
