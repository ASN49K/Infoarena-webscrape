#include<bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");

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
