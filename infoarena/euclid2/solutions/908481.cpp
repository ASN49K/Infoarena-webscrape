#include<fstream>
using namespace std;
int ec2(int a ,int b)
{if(!b)return a;
else return ec2(b,a%b);
    }
int main()
{ int n,i,a,b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
    fin>>n;
    for(i=1;i<=n;i++)
   {fin>>a>>b;fout<<ec2(a,b)<<"\n";}
   fin.close();
   fout.close();
    return 0;}
