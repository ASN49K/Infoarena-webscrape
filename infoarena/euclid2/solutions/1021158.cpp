#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int n,i=1,a,b,d;
    fin>>n;
    while(i<=n)
    {
        fin>>a>>b;
        while(b) {d=a%b;a=b;b=d;}
        fout<<a<<"\n";
        i++;
    }
}
