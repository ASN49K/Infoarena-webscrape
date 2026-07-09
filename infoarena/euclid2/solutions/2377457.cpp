#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,b,ax,ay,r,c,t;
    f>>n;
    for(int i=0;i<n;i++){
            f>>ax;
            f>>ay;
            if(ax>ay){
                a=ax;
                c=ay;
            }else {
                a=ay;
                c=ax;
            }
            b=0;
            while(b==0){
      while(a>c){
        a=a-c;
      }
      if(c%a==0){
        r=a;
        b=1;
      }else{
      t=a;
      a=c;
      c=a;
      }
    }
    g<<r<<endl;
    }
    g.close();
    f.close();
    return 0;
}
