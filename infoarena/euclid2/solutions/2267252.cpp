#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,T,a,b;
int main()
{f>>T;
for(i=1;i<=T;i++){f>>a>>b;
                  while(a!=b){
                  if(a>b)a=a-b;
                  else if(b>a)b=b-a;}
                 g<<a<<endl;}
    return 0;
}
