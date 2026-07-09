#include <iostream>
#include <fstream>

using namespace std;


int a[1024],b[1024],c[1024],m,n,f=0,com;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out"); 

int main(){
cin >> m;
cin >> n;
for(int i=0;i<m;i++){
	cin >> a[i];
}
for(int i=0;i<n;i++){
	cin>> b[i];
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
cout << com<<"\n";


for(int i=0;i<f;i++){
	cout << c[i]<<" ";
}

}

