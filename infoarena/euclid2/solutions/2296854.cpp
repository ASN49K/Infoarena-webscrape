
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;

}


int main()
{
    int T,i,x,y;
    fin>>T;
    for(i=1; i<=T; i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<endl;
    }
    return 0;
}
