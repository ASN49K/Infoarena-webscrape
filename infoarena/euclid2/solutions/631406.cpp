#include<fstream>

using namespace std;
long int cmmdc(long int a, long int b){
  long int r;
  while(b!=0){
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}

int main()
{fstream f("euclid2.in",ios::in), g("euclid2.out",ios::out);
long int a,b,t;
f>>t;
for(int i=1;i<=t;i++){
  f>>a>>b;
  g<<cmmdc(a,b)<<endl;
}
    return 0;
}
