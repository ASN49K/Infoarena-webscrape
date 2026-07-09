#include <fstream>

using namespace std;

int max (int a, int b){
    if (a>b) return a;
      else return b;
}      

int a[1025],b[1025],c[1025][1025],m,n;
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

int afisare(int m,int n){
    int maxim;
     if((m!=0)&&(n!=0))       
        {
          maxim=max( max(c[m-1][n],c[m][n-1]),c[m-1][n-1]);   
          
          if (maxim==c[m-1][n-1])
                  {
                    afisare(m-1,n-1);
                    fout<<a[m]<<" ";
                  }   
                 else
                  if(maxim==c[m][n-1]) afisare(m,n-1);
                     else
                       afisare(m-1,n);    
          }                                                                       
}
     

int main(void){
    fin>>m>>n;
    for(int i=1;i<=m;++i)fin>>a[i];
    for(int i=1;i<=n;i++)fin>>b[i];
    fin.close();
    for (int i=1;i<=m;++i)c[i][0]=0;
    for (int i=1;i<=n;++i)c[0][i]=0;
    c[0][0]=-100000;
    for(int i=1;i<=m;++i)
      for(int j=1;j<=n;++j)
        if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
           else c[i][j]=max(c[i-1][j],c[i][j-1]);
    fout<<c[m][n]<<"\n";
    afisare(m,n);       
    fout.close();           
}
