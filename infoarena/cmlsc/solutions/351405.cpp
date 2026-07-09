#include<fstream>
#define Max 1025
#define max(a,b) ((a > b) ? a : b)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,a[Max],b[Max],c[Max][Max],max_val;
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
           }
     }
}
int afis(int max_val){
     int i,j;
     if(max_val > 0){
   for(i = 1; i <= m; i++)
   {
         for(j = 1; j <= n; j++)
         if(c[i][j] == max_val)
         {
                    afis(max_val-1);
                    fout<<b[j]<<" ";
                    return 0;
         }
   }
}
}
int main(){
    read();
    longest_string();
    fout<<max_val<<"\n";
   afis(max_val);                    
fin.close();
fout.close();
return 0;
}    
