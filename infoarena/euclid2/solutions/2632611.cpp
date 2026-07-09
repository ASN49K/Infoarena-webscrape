#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{int a,b,T,c,i;
fin>>T;
    for(i=1;i<=T;i++)
    {
fin>>a>>b;
  while(b)
{
    c=a%b;
    a=b;
    b=c;
}
    fout<<a<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
