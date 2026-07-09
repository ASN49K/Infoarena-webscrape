#include <fstream>

using namespace std;
int euclid(int a,int b)
{
    if(b==0)
        return a;
    return euclid(b,a%b);
}
ifstream    fin ("euclid2.in");
ofstream    fout("euclid2.out");
int main()
{
    int a,b,T;
    fin>>T;
    int pas=1;
    while(pas<=T)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
        pas++;
    }
    return 0;
}
