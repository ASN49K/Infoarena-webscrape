#include<fstream>
using namespace std;
ifstream in;
ofstream out;
int a[100000],b[100000];
int cmmdc(int a,int b){
	int rest=0;
	int aux=0;
	if(a<b)
	{
		aux=a;
		a=b;
		b=aux;
	}
	do{
		rest=a%b;
		a=b;
		b=rest;
	}while(rest!=0);
	
	return a;
}
int main(){
	int player_unu=0,n;
	in.open("cmmdc.in");
	out.open("cmmdc.out");
	in>>n;
	for(int i=0;i<n;i++)
	{
		in>>a[i];
		in>>b[i];
		out<<cmmdc(a[i],b[i])<<endl;
	}
	in.close();
	out.close();
	return player_unu;
}