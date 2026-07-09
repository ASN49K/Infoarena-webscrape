#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,i,a,b;
void eucl(int a, int b)
{
    int r;
    r=a%b;
    while(r>0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    fout<<b<<'\n';
}
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        eucl(a,b);
    }




    fin.close();
    fout.close();
    return 0;
}
