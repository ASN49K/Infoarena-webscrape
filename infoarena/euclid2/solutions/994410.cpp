#include<fstream>
using namespace std;
int t,a,b,i;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int euc(int a, int b)
{ if (b==0) return a;
  else return euc(b,a%b);
}

int main(){

    fi>>t;
    for(i=1;i<=t;i++){ fi>>a>>b;
                       fo<<euc(a,b)<<"\n";
                      }
    fi.close(); 
    fo.close();
    return 0;
}
