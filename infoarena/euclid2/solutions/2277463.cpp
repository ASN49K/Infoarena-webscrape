#include<fstream>
using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
int main()
{int a ,b, r;
fin>>a>>b;
while(a%b!=0)
{r=a%b;
a=b; b=r;
}
if(b==1)fout<<"0";
else
fout<<b;
fin.close();
fout.close();
return 0;
}
