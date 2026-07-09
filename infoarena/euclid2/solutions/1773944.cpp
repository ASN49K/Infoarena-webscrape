#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b,c;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
       {fin>>a>>b;
       if(a>b)
       {
           c=a;a=b;b=c;
       }
       while(b)
       {
           c=a%b;
           a=b;
           b=c;
       }
       fout<<a<<'\n';
       }
    fout.close();
    return 0;
}
