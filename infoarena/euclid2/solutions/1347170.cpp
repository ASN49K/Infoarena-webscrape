#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void euclid(int x, int y)
{
    if(x-y==0)
         fout<<x<<"\n";
    else if (x>y)
        euclid(x-y,y);
    else
        euclid(y-x,x);
}
int main()
{
    int n,x,y;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>y;
        euclid(x,y);
    }
}
