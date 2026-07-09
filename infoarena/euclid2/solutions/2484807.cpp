#include<bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in"); ofstream fout("euclid2.out");
int eucl(int a,int b){
int d;
while(b){
    d=a%b;a=b;b=d;
}
return a;

}


int main(){
    int a,b,t;
    fin>>t;
    while(t){
fin>>a>>b;

fout<<eucl(a,b)<<endl;
t--;}

return 0;}
