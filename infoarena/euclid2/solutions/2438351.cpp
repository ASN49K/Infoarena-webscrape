# include <fstream>
using namespace std;
ifstream fin ("cmmdc.in");
ofstream fout ("cmmdc.out");
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
    while(n)
    {
        fin>>a>>b;
        if(cmmdc(a,b)!=1)
            fout<<cmmdc(a,b)<<endl;
        else
            fout<<0<<endl;
        n--;
    }
    return 0;
}
