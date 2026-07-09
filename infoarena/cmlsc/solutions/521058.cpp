#include <fstream.h>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
#define MAX -1025

int a[1025];
int b[1025];
int best[1025][1025];
int fiu[1025][1025];

void read(int &n, int &m){
     in>>n >>m;
     for(int i = 1; i <= n; i++){
             in>> a[i];
     }
     
     for(int i = 1; i <= m; i++){
             in>> b[i];
     }                                                                                                              
}

void init(int n, int m){
     for(int i = 0; i <= n; i++){
             best[0][i] = MAX;             
     }          
     for(int i = 0; i <= m; i++){
             best[i][0] = MAX;
     }
}


int getMaxim(int val1, int val2){
    if(val1 == MAX && val2 == MAX){
            return 0;
    }    
    return val1 > val2 ? val1 : val2;        
}

void solve(int n, int m){
     
     for(int i = 1; i <= n; i++){
             for(int j = 1; j <= m; j++){
                     if(a[i] == b[j]){
                             if(best[i-1][j-1] == MAX){
                                  best[i][j] = 1;
                             }
                             else{
                                  best[i][j] = best[i-1][j-1] + 1;                                                           
                             }                             
                     }
                     else{
                          best[i][j] = getMaxim(best[i][j - 1], best[i-1][j]);      
                     }
             }
     }          
}

bool outOfBorder(int i, int j){
     if(i < 1){
          return true;
     }
     if(j < 1){
          return true;     
     }     
     return false;               
} 

void showWay(int i, int j){     
     if(outOfBorder(i,j)){
          return;
     }
     if(a[i] == b[j]){
                
             showWay(i-1, j-1);
             out<<a[i]<< " ";     
     }          
     else{
          if(best[i][j-1] > best[i-1][j]){
                          showWay(i,j-1);
          }     
          else{
               showWay(i-1, j);
          }              
     }
}
void show(int n, int m){
    
     out<<best[n][m]<< "\n";     
     
     showWay(n, m);
}




int main(){
    int n, m;
    read(n, m);
    solve(n, m);
    show(n, m);  
    return 0;    
}
