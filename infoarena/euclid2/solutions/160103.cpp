 
#include <iostream>
#define FIN "euclid2.in"
#define FOUT "euclid2.out"
using namespace std;
unsigned long a,b,t;


int main(void){
        freopen(FIN,"rt",stdin);
        freopen(FOUT,"wt",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
        scanf("%ld%ld",&a,&b);
        unsigned long r;
        while (b){
                r=a%b;
                a=b;
                b=r;
        }
        printf("%ld\n",a);}
        fclose(stdin);
        fclose(stdout);
}
