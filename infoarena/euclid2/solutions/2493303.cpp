#include<bits/stdc++.h>
using namespace std;

long long gcd(long a,long b){
		
if(a==0) return b;
else return gcd(b%a,a);
	
}

int main(){
	
 long int t,i;	
 long long a,b;	

  ifstream fin;
  fin.open("euclid2.txt");
  
   
  ofstream fout;
  fout.open("euclid2.out");
  
   fin>>t;
   for(i=0;i<t;i++){
   fin>>a>>b;
   fout<<gcd(a,b)<<"\n";	
   }
 	
return 0;	
}
