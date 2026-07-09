#include <fstream>
#include <math.h>
using namespace std;
  ifstream fin("cifra.in.c");
  ofstream fout("cifra.out");
void calcul(){

int n, i, x=0;
fin>>n;
for(i=1; i<=n; ++i)
    x=x+pow(i, i);
        fout<<x%10<<endl;

}

int main(){
int t;
fin>>t;
for( int i=1; i<=t&&fin>>n; ++i)
    calcul();
return 0;
}
