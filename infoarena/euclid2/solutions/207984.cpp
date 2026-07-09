#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int a,b,t;
int cmmdc(int a,int b)
{if(b==0)
 return a;
 else cmmdc(b,a%b);
    
    }
void citire()
{in>>t;
for(int i=1;i<=t;i++)
     {in>>a>>b;out<<cmmdc(a,b)<<'\n';}
in.close();}

int main()
{citire();

return 0;
}    
