#include<fstream.h>

int t,a,b;

int div(int a,int b)
 { if(!b) return a;
     return div(b,a%b);
  }
int main(void)
{ifstream fin("euclid2.in");
 ofstream fout("euclid2.out");
  fin>>t;
  while(t)
     { fin>>a>>b;
      out<<div(a,b)<<endl;
      t--;
      }
 return 0;
}