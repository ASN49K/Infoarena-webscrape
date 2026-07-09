# include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc(int a, int b)
{
    if(!a)
        return b;
    return cmmdc(b%a,a);
}
int main()
{
    int n;
    int a,b;
    fin>>n;
    for(int i=0;i<n;i++)
    {
        fin>>a>>b;
        if(cmmdc(a,b)!=1)
            fout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
