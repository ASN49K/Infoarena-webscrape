#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{int a,b,c,i,x;
fin>>x;
for(i=1;i<=x;i++)
{
    fin>>a>>b;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    fout<<a;
}

    return 0;
}
