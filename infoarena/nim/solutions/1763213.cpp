#include<fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n,t,a,s,i,j;
int main(){
   fin>>t;
   for (i=1;i<=t;i++){
       fin>>n;
       fin>>s;
       for (j=2;j<=n;j++)
       {
           fin>>a;
           s=s^a;
       }
       if (s==0) fout<<"NU\n";
        else
            fout<<"DA\n";
   }
   fin.close();
   fout.close();
   return 0;
}
