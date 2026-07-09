#include <iostream>
#include <fstream>
using namespace std;

main(){
int a[1024], b[1024], j,k, c[1024],t;
t=0;
ifstream inr;
ofstream our;
inr.open("cmlsc.in");
our.open("cmlsc.out");
inr >> j; inr >> k;
for(int i=0; i<=j-1; i++){inr>>a[i];};
for(int i=0; i<=k-1; i++){inr>>b[i];};
for(int i=0; i<=j-1; i++){
 for(int r=0; r<=k-1; r++){
  if(a[i]==b[r] && a[i]!=0){
   c[t]=a[i];
   ++t;
   b[r]=0;
   };
 
   
   };};
 our<<t<<"\n";
for (int i=0; i<=t-1; i++){
 our<<c[i]<<" ";};      
inr.close();
our.close();
};
