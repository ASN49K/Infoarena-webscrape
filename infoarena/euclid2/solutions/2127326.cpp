#include <iostream>
using namespace std;

int main() {
  int a,b,T,i;
  cin>>T;
  for(i=1;i<=T;i++)
  {
      cin>>a>>b;
      while(a!=b)
      {
          if(a>b)
            a=a-b;
          else
            b=b-a;
      }
      cout<<a<<' ';
  }
return 0;
}
