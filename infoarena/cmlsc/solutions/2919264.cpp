#include<iostream>
#include<fstream>
using namespace std;

#define NMAX 1024
#define maxim(a,b) ((a>b)?a:b);

int n1,n2, x[NMAX], y[NMAX], xy[NMAX][NMAX], result[NMAX], length;
//n1,n2 - how many numbers in each sequence of numbers from arrays x,y

int main(){

freopen("cmlsc.in", "r", stdin);
freopen("cmlsc.out", "w", stdout);

scanf("%d %d", &n1, &n2);
for(int i=1; i<=n1; i++) scanf("%d", &x[i]);
for(int i=1; i<=n2; i++) scanf("%d", &y[i]);

for(int i=1; i<=n1; i++)
    for(int j=1; j<=n2; j++)
        if(x[i] == y[j])
            xy[i][j] = xy[i-1][j-1] +1, length++;
        else 
            xy[i][j] = maxim(xy[i-1][j], xy[i][j-1]);
printf("%d\n", length); // length of the biggest substream found


int i=n1, j=n2, res_index = 0;
while(i>0 && j>0){
    if(x[i] == y[j])
        result[res_index++] = x[i], i--, j--;
    else if(xy[i-1][j] > xy[i][j-1])
        i--;
    else j--;
}

for(int i=length-1; i>0; i--)
    printf("%d ", result[i]);
printf("%d", result[0]);
return 0;
}