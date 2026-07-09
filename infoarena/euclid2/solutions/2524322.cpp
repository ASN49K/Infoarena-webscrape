#include<iostream>
#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euc(int x, int y){
    while((x!=0)&&(y!=0)){
	
        if(x>y) x=x%y; 
		else y=y%x;}
    if (y==0) return x;
    else return y;
}

int t;  
int a[100000];
int b[100000];
main(){ 
in>>t;
    for(int i=0; i<t;i++){
        in>>a[i]>>b[i];
       
        out<<euc(a[i],b[i])<<'\n';
    }
    return 0;
}
