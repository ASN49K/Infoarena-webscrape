#include <iostream>
#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b){
    if(b==0){
        return a;
    }
return cmmdc(b,a%b);
}

int main(){
int n;
fin>>n;
int a , b;
for(int i=1;i<=n;i++){
fin>>a>>b;
    fout<<cmmdc(a,b);
    fout<<endl;
    
}



    
}
 