#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int n,i,x,y,r;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
     while(y)
     {r=x%y;
     x=y;
     y=r;
     }
     fout<<x<<"\n";
    }
    return 0;
}
