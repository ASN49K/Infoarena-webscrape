#include <fstream>

using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,r,T,i;
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>a>>b;
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }

        fout<<b<<'\n';
    }
    fin.close();
    fout.close();
    return 0;

}
