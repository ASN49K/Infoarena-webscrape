
#include <bits/stdc++.h>
using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");


int main ()
{

 int n , m , r = 0;
 f >> n >> m;
 int a[1030],b[1030], c[1030][1030] = {0};
 for(int i = 0; i < n; i++)f >> a[i];
 for(int i = 0; i < m; i++)f >> b[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
         if(a[i] == b[j]){
             c[i][j] = 1;
             continue;
            
         }
        }
     }
for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(c[i][j] == 1){
                r++;
            }
        }
}
cout << r;
for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(c[i][j] == 1){
                g << a[i] << " ";
            }
        }
}

  return 0;
}
