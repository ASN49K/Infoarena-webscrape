#include <fstream>
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
long n,i,sol,t,aux;
int main()
{
cin>>t;
while (t--){
            cin>>n;
            for (i=1,sol=0;i<=n;++i){
                                     cin>>aux;
                                     sol^=aux;
                                     }
            if (sol) cout<<"DA \n";
                else cout<<"NU \n";
           }     
return 0;
}
