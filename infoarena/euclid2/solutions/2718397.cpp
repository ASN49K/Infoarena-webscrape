#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{   long long n,a,b;
    int i;
    fin>>n;
    for (i=0;i<n;i++)
    {
        fin>>a>>b;
         while(a != b)
        if(a > b)
            a=a-b;
        else
            b=b-a;
        fout<<a<<'\n';
    }
    return 0;
}
