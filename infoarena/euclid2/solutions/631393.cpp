#include <cstdlib>
#include <iostream>
#include<fstream>

using namespace std;
int cmmdc(int &a, int &b){
  int r;
  while(b!=0){
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}

int main(int argc, char *argv[])
{fstream f("euclid2.in",ios::in), g("euclid2.out",ios::out);
int a,b,t;
f>>t;
for(int i=1;i<=t;i++){
  f>>a>>b;
  g<<cmmdc(a,b)<<endl;
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
