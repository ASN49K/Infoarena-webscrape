#include<fstream.h>

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long n,x,y;

void cmmdc(long a,long b){
    if(b==0){
       return a;
     return cmmdc(b,a%b)
     }
     fout<<a;
 }
void citire(){
     fin>>n;
     for(int i=0;i<n;i++){
	 fin>>x>>y;
	fout<<cmmdc(x,y);
	 fout<<'\n';
     }
 }

int main(){
     citire();
     fin.close();
     fout.close();
   return 0;
}