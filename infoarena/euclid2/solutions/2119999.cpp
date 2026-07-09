#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b;
int cmmdc(int a,int b){return (b) ? cmmdc(b,a%b):a;}
int main()
{
    int i,n;
    fin >> n;
    for(i=0;i<n;i++)
    {
        fin >> a>> b;
        fout <<cmmdc(a,b)<<'\n';
    }
}
