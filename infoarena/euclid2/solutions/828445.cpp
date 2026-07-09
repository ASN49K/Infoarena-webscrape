# include <iostream>
using namespace std;
main () {
     int n,m;
     cin >> n >> m;
     while (n!=0 && m!=0){
           if (m>n){
                    m=m%n;
                    }
           else {
                n=n%m;
                }         
           }
     cout << m+n;
     cin.ignore(2);
     }
