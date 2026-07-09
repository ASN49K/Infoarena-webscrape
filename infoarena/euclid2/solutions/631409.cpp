#include<fstream>

using namespace std;
long int cmmdc(long int a, long int b){
  long int r;
  while(b!=0){
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}

int main()
{int T;
   long int a,b;
   FILE *fin=fopen("euclid2.in","r");
   FILE *fout=fopen("euclid2.out","w");
   
   fscanf(fin,"%d",&T);
   for(int i=0;i<T;i++){
       fscanf(fin,"%ld %ld",&a,&b);
	   fprintf(fout,"%ld\n",cmmdc(a,b));
   
}
    return 0;
}
