#include <iostream>
#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int t,a[100000],b[100000],c;
int main(){
cin >> t;



for(int i=0;i<t;i++){
	cin >>a[i];
	cin >>b[i];
	
}


for(int i=0;i<t;i++){
	while(b[i] !=0){
	c=a[i]%b[i];
	a[i]=b[i];
	b[i]=c;	
		
	}
	c=0;
}
   for(int i=0;i<t;i++)cout << a[i]<<"\n";

}

