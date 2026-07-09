#include<fstream>
using namespace std;
int euclid(int a, int b)
{
    int c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
       int a,b,T,r,i;
       ifstream f1("euclid2.in");
       ofstream f2("euclid2.out");
       f1>>T;
       for(i=0;i<=T;i++)
              f1>>a>>b;
              r=euclid(a,b);
             f2<<r;
        f1.close();
        f2.close();
}
