#include<bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in"); ofstream fout("euclid2.out");

int main(){
    int a,b,t;
    fin>>t;
    while(t){
fin>>a>>b;int d;
while(b){
    d=a%b;a=b;b=d;
}
fout<<a<<endl;
t--;}

return 0;}
