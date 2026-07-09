#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

main(){
 string str;     
 int a,b,c;
 ifstream euc;
 ofstream ec;
 euc.open("euclid2.in");
 ec.open("euclid2.out");
 euc >> c;
 for (int i=1; i<=c; i++){
    euc >> a;
    euc >> b; 
    while (1){
       a=a%b;
       if(a==0 || b==0){break;};
       b=b%a;
       if(a==0 || b==0){break;};};
 ec << a+b;
};
 euc.close();
 ec.close();

};
