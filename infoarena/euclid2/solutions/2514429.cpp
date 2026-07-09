#include <iostream>
#include <fstream>
using namespace std;

ifstream ci("euclid2.in");
ofstream cou("euclid2.out");

int t,a[100000],b[100000],c;
int main(){
ci >> t;



for(int i=0;i<t;i++){
	ci >>a[i];
	ci >>b[i];
	
}


for(int i=0;i<t;i++){
	while(b[i] !=0){
	c=a[i]%b[i];
	a[i]=b[i];
	b[i]=c;	
		
	}
	c=0;
}
   for(int i=0;i<t;i++)cou << a[i]<<"\n";

}

