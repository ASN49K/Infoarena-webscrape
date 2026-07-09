# include <iostream>
#include <fstream>
using namespace std;
main () {
     int a,b,t;
     ifstream d("euclid2.in");
     ofstream asd("euclid2.out");
     d >>t;
     for (int i=0;i<=t-1;i++ ){
         d  >> a >> b;
     while (a!=0 && b!=0){
           if (b>a){
                    b=b%a;
                    }
           else {
                a=a%b;
                }         
           }
      asd<< a+b;
      asd << endl;
      }
     d.close();
     asd.close();
     }
