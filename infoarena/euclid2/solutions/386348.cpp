#include <stdio.h>
//#include<fstream>
using namespace std;
int main()
{	 int a,b,c,d;
	 //ifstream fin("euclid2.in");
	 //ofstream fout("euclid2.out");
	FILE *fr = fopen("euclid2.in","r");
	FILE *fw = fopen("euclid2.out","w");
	fscanf(fr,"%d", &c);
	 //fin>>c;
	 for(int i=1;i<=c;i++){
//			 fin>>a>>b;
		fscanf(fr,"%d %d", &a,&b);
		 while(b){
			 d=a%b;
			 a=b;
			 b=d;
		 }
	//	 fout<<a<<endl;
		fprintf(fw,"%d \n",a);
	 }
return 0;
}
