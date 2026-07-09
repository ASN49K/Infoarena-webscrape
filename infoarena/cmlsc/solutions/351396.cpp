#include<fstream>
#define Max 1025
#define max(a,b) ((a > b) ? a : b)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,a[Max],b[Max],c[Max][Max],max_val,imax,jmax;
void read(){
     int i;
     fin>>m>>n;
     for(i = 1; i <= m; i++)
     fin>>a[i];
     for(i = 1; i <= n; i++)
     fin>>b[i];
fin.close();
}
int find_max(int a,int b){
    int i,j,flag=0;
    if(a < 1 || b < 1)return 0;
    else{
         for(i = 1; i <= a; i++)
         {
               for(j = 1;j <= b; j++)
               flag = max(c[i][j],flag);
         }
    }
return flag;
}         
void longest_string(){
     int i,j;
     for(i = 1; i <= m; i++)
     {
           for(j = 1; j <= n; j++)
           if(a[i] == b[j])
           {
                   c[i][j] = find_max(i-1,j-1)+1;
                   max_val = max(c[i][j],max_val);
                   imax = i;
                   jmax = j;
           }
     }
}
int afis(int v1,int v2,int max_val){
     int i,j;
     if(v1 && v2 >= 1){
     for(i = v1; i >= 1; i--)
     {
           for(j = v2; j >= 1; j--)
           if(c[i][j] == max_val)
           {
               afis(i-1,j-1,max_val-1);
                fout<<b[j]<<" ";
           }
     }       
    }
}
int main(){
    read();
    longest_string();
    fout<<max_val<<"\n";
     afis(imax,jmax,max_val);
fin.close();
fout.close();
return 0;
}    
