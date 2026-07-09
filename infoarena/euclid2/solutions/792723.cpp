#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b;
int div(int a,int b)
{
    if (b==0)
    return a;
    div(b,a%b);
}
int main()
{
    fin>>t;
    for (int i=0;i<t;i++)
    {
        fin>>a>>b;
        fout<<div(a,b)<<endl;
    }
    return 0;
}
