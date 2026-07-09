#include <fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int cmmdc(int x,int y)
{
    if(y==0) return x;
    else return cmmdc(y,x%y);
}
void query(int T)
{
    int x,y;
    for(int i=0;i<T;i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<'\n';
    }
}
int main ()
{
    int T;
    fin>>T;
    query(T);
    return 0;
}

