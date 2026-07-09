#include<fstream>
using namespace std;
 
int a,b,r,nr;
 
int main()
{
    int i;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>nr;
    for(i=1;i<=nr;i++)
    {
        fin>>a>>b;
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<'\n';
    }
    return 0;
}