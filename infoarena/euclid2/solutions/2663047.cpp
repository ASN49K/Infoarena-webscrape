#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int a, b, n;

int cmmdc(int a, int b){
    int rest = 0;
  while(b!=0){
    rest = a%b;
    a=b;
    b=rest;
    }
    
    return a;
} 

int main(){
    
 fin>>n;
 for(int i=0;i<n;i++){
     fin>>a>>b;
     fout<<cmmdc(a,b)<<"\n";
 }
    
    
}