#include <iostream>
#define FIN "euclid2.in"
#define FOUT "euclid2.out"
using namespace std;
unsigned long a,b;


int main(void){
        freopen(FIN,"rt",stdin);
        freopen(FOUT,"wt",stdout);
        cin>>a>>b;
        unsigned long r;
        while (b){
                r=a%b;
                a=b;
                b=r;
        }
        cout<<a<<"\n";
        fclose(stdin);
        fclose(stdout);
}
