# include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc (int a, int b)
{
    if(!b)
    return a;
    else
    return cmmdc(b,a%b);
}
int main()
{
    int a,b,i,t;
    fin>>t;
    for(i=0;i<t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
return 0;
}
