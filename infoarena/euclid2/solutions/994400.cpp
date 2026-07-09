#include<fstream>
using namespace std;
int t,a,b,i;

inline int euclid(int a, int b)
{ if (b==0) return a;
  else return euclid(b,a%b);
}

int main(){
    ifstream fi("euclid2.in");
    ofstream fo("euclid2.out");
    
    fi>>t;
    for(i=1;i<=t;i++){ fi>>a>>b;
                       fo<<euclid(a,b)<<endl; 
                      }
    fi.close(); 
    fo.close();
    return 0;
}
