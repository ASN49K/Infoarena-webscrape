#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
if(!b)return a;
return cmmdc(b,a%b);    
}

int main()
{int a,b,i,t;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
in>>t;
for(i=1;i<=t;i++)
    {
     in>>a>>b;
     out<<cmmdc(a,b)<<'\n';   
    }

in.close();
out.close();    
return 0;
}
