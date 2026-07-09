#include<fstream>
using namespace std;
int a[10010];
int main(void){
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    int t,n,i,s;
    fin>>t;
    while(t--){
              fin>>n; s=0;
              for(i=1;i<=n;++i){ fin>>a[i]; s^=a[i]; }
              if(s)fout<<"DA\n";
              else fout<<"NU\n"; 
               }    
 return 0;   
}
