#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid.out");
int T,x,y,a,b,i,r;
int main()
{
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>a>>b;
        x=a;
        y=b;
        while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<"\n";
    }
    fin.close();
    fout.close();
    return 0;

}
