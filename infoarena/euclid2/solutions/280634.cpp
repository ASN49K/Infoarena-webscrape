#include<fstream>
using namespace std;
int euclid(int a,int b)
{ int r; 
  if(b>a) {r=a;a=b;b=r;}
  do {r=a%b; a=b;b=r;} while(b);
  return a;
}

int main()
{ ifstream fi("euclid2.in");
  ofstream fo("euclid2.out");
  int n;fi>>n;
  int i,a,b;
  for(i=0;i<n;i++){fi>>a>>b;fo<<euclid(a,b)<<'\n';}
  fi.close();
  fo.close();
return 0;
}

