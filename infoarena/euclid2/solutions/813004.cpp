#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int a,b,n,i;
    ifstream fi;
    fi.open("euclid.in");
    ofstream fo;
    fo.open("euclid.out");
    fi>>n;
    for (i=1;i<=n;i++){
          fi>>a>>b;
          while(a!=b)if (a>b)a=a-b;else b=b-a;
          fo<<a<<endl;            
          }
    
    
    
    fo.close();
    fi.close();
    
    }
