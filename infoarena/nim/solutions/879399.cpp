#include<fstream>
using namespace std;
ifstream eu("nim.in");
ofstream tu("nim.out");
int main ()
{
int T,sum,val,n;
eu>>T;
while (T--)
{
 eu>>n;
 sum=0;
 for(int i=1;i<=n;++i)
{
 eu>>val;
 sum = sum ^ val;
}
  if(sum)
   tu<<"DA"<<endl;
   else 
   tu<<"NU"<<endl;
}
 return 0;
}
