#include<fstream>
using namespace std;

int cmmdc(int a, int b)
    { for (long r=a%b; r; a=b, b=r, r=a%b);
      if (a & b) return b;
      else return (a+b);};
      
int main() {
           ifstream f1("euclid2.in");
           ofstream f2("euclid2.out");
           int t,a,b;
           
           f1>>t;
           while (t--)
                 { f1>>a>>b;
                   f2<<cmmdc(a,b)<<endl; };
           f1.close();
           f2.close();
           return 0; }
