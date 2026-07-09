#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i,a,b,x;
int ae(int a, int b)
{
    if(!b)
        return a;
    else
        return ae(b,a%b);
}
int main()
{
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>a>>b;
        if(a<b)
        {
            x=a;
            a=b;
            b=x;
        }
        fout<<ae(a,b)<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
