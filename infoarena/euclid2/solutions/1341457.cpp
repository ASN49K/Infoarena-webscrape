#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,T;

int main()
{
fin>>T;
for(int i=0;i<T;++i)
{
    fin>>a>>b;
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b-=a;
    }
    fout<<a<<'\n';
}

fin.close();
fout.close();
return 0;
}
