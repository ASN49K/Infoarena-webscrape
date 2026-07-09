#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b){
while(b){
    int r=a%b;
    a=b;
    b=r;
}
return a;
}
int main(){
    int n,a,b;
    fin>>n;
    for(int i=0; i<n; i++){
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
    }
    return 0;
}
