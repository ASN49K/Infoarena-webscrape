#include<iostream>
#include<fstream>
using namespace std;
int t,a,b;

  int cmmdc(int a, int b)
  {
       if(!b) return a;
       return cmmdc(b,a%b);
  }


  int main()
 {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
     fin>>t;
     for(t;t;--t)
      {fin>>a>>b;
      fout<<cmmdc(a,b)<<endl;
      }
      return (0);
      }

