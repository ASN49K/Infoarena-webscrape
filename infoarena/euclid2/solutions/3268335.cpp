#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,t;

int euclid(int x, int y)
{
    int r;
    while(y!=0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{
    fin>>t;
    for(int i=1;i<=t;i++){
        fin>>a>>b;
        fout<<euclid(a,b)<<"\n";
    }
    return 0;
}
