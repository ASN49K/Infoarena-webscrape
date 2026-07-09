#include<fstream>
#include<algorithm>
using namespace std;

int a,b,t;

int cmmdc(int a,int b) {
   if(!b) return a;
 return cmmdc(b,a%b);
}

int main()
{
  ifstream cin("euclid2.in");
  ofstream cout("euclid2.out");

  cin>>t;
  while(t--)
  {
    cin>>a>>b;
    cout<<cmmdc(a,b)<<'\n';
  }

 return 0;
}
