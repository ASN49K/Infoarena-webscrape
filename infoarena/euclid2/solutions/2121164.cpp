#include <iostream>
#include <fstream>

using namespace std;

int t,a,b;
int gcd(int t1,int t2){
  int r;
  do{
    r=t1%t2;
    t1=t2;
    t2=r;
  }while(r);
  return t1;
}

int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    f>>t;
    for(int tst=1;tst<=t;tst++){
      f>>a>>b;
      g<<gcd(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
