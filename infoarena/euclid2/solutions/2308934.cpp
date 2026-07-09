#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a,int b){
      int r;
      while(a && b){
            if(a>b){
                  a=a%b;
            }
            else{ 
                  b=b%a;
            }
            
      }
      return  a ? a: b;
}

int main(){
      int n,a,b;
      f>>n;
      for(int i = 0;i<n;i++)
      {
            f>>a>>b;
            g<<euclid(a,b)<<"\n";
      }
      g.close();
      f.close();
}