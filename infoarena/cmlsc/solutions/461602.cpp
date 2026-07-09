#include<fstream>
using namespace std;
int a[1025],b[1025];
int comun[1025][1024];
int sol[1025];
int main(){
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	int l1,l2;
	f>>l1>>l2;
	int i,j,ct=0;
	for(i=1;i<=l1;i++){
		f>>a[i];
	}
	for(i=1;i<=l2;i++){
		f>>b[i];
	}
	for(i=1;i<=l1;i++){
		ct=0;
		for(j=1;j<=l2;j++){
			
			if(a[i]==b[j]){
				
				ct++;
				comun[i][ct]=j;
				
			}
		}
	}
	
	int max=0;
	ct=0;
	for(i=1;i<=l1;i++){
		
		if(comun[i][1]!=0){
			int cr=0,crt=1;
			while(comun[i][crt]!=0){
				cr++;
				if(comun[i][cr]<=max){}
				else{
					max=comun[i][cr];
					comun[i][cr]=0;
					
					ct++;
					sol[ct]=a[i];
				}
				crt=cr;
			}
		}
	}
	g<<ct<<'\n';
	for(i=1;i<=ct;i++){
		g<<sol[i]<<" ";
	}
	return 0;
}
