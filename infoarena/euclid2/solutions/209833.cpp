#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
ifstream iFile("euclid2.in");
ofstream oFile("euclid2.out"); 
long a[100001], b[100001];
int T=0;

int cmmdc (long a, long b)
{ if(!b) return a;
  return cmmdc(b, a%b); }

void writeFile(long cmmdc1) {oFile<<cmmdc1<<endl; cout<<cmmdc1<<endl;}
void readFile() {
 iFile>>T;
 for (int i=0; i<T; i++){
  iFile>>a[i]; iFile>>b[i];}
 }

main(){
 if(iFile.fail()) return false;
 int c;
 readFile();
 for(int i=0; i<T;i++) // { if(a[i]<b[i]) {
                       //    c=a[i]; a[i]=b[i]; b[i]=c;} 
                          writeFile(cmmdc(a[i],b[i]));//}
 iFile.close(); oFile.close();
 return 0;
}