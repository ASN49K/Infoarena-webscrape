#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,a,b;

int cmmdc(int x,int y)
{
    int r=0;
    while(y!=0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    fin>>T;
    while(T!=0){
        fin>>a>>b;
        fout<<cmmdc(a,b);
        fout<<"\n";
        T--;
    }
    return 0;
}
