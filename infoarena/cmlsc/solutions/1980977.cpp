#include<fstream>
#include<iostream>

using namespace std;

int find(int what, int where[],int n, int fromWhere){
	for(int i=fromWhere;i<n;i++)
	    if(what==where[i]) return i;
	return -1;
}


int main(){
	ifstream in; ofstream out;
	in.open("cmlsc.in"); out.open("cmlsc.out");
	out.clear();
	int m,n; 
	in>>m>>n;
	int a[m], b[n], length,maxLength=0,start=0,fromWhere, whereAux;
	for(int i=0;i<m;i++) in>>a[i];
	for(int i=0; i<n; i++) in>>b[i];
	
	for(int i=0; i<n;i++){
		length=0;
		if((whereAux=find(b[i],a,m,0))!=-1){
			length++; fromWhere=whereAux;
			for(int j=i+1;j<n;j++) {
			   if((whereAux=find(b[j],a,m,fromWhere+1))!=-1) {
			   	length++; fromWhere=whereAux;
			   }	   
		   }
		}
		if(length>maxLength){
			maxLength=length;
			start=i;
		}
	}
	
	out<<maxLength<<endl;
	fromWhere=-1;
	for(int j=start;j<n;j++) {
		if((whereAux=find(b[j],a,m,fromWhere+1))!=-1) {
		  out<<a[whereAux]<<" ";
		  fromWhere=whereAux;
		}
	}
	
	in.close(); out.close();
}
