#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.in");

/*int euclid(int a, int b){
    while (b!=0) {
        int nr=b;
        b=a%b;
        a=nr;}
    if(a==1) return 0;
   return a;
 }*/
int main() {
    int n;
    fin>>n;
    int a[99999],b[99999],i;
    for(i=1; i<n; i++)
        fin>>a[i]>>b[i];
    for(i=1; i<n; i++){
    while (b[i]!=0) {
        int nr=b[i];
        b[i]=a[i]%b[i];
        a[i]=nr;}
    if(a[i]==1) fout<<"0"<<endl;
        else fout<<a[i]<<endl;}
    
    return 0;
}
