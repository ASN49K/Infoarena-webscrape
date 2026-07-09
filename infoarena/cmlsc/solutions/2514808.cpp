#include <iostream>
#include <fstream>

using namespace std;


 unsigned short int a[1024],b[1024],c[1024],m,n,f=0,com;

ifstream ci("cmlsc.in");
ofstream cou("cmlsc.out"); 

int main(){
ci >> m;
ci >> n;
for(int i=0;i<m;i++){
	ci >> a[i];
}
for(int i=0;i<n;i++){
	ci >> b[i];
}



for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		if(a[i]==b[j]){
			com++;
			c[f]=b[j];
				for(int p=0;p<f;p++){
				if(c[p]==c[f]){
					com--;
				}
			}
			f++;
		
		}
	}
}
cou << com<<"\n";


for(int i=0;i<f;i++){
	cou<< c[i]<<" ";
}

}

