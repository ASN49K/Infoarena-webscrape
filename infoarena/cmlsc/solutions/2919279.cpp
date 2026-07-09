#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

#define NMAX 1025

int n1,n2, x[NMAX], y[NMAX], xy[NMAX][NMAX];
stack<int> s;
//n1,n2 - how many numbers in each sequence of numbers from arrays x,y

int main(){
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

f>>n1>>n2;
for(int i=1; i<=n1; i++) f>>x[i];
for(int i=1; i<=n2; i++) f>>y[i];

for(int i=1; i<=n1; i++)
    for(int j=1; j<=n2; j++)
        if(x[i] == y[j])
            xy[i][j] = xy[i-1][j-1] +1;
        else 
            xy[i][j] = max(xy[i-1][j], xy[i][j-1]);

g<< xy[n1][n2] <<"\n"; // length of the biggest substream found

int i=n1, j=n2;
while(xy[i][j]){
    if(x[i] == y[j])
        s.push(x[i]), i--, j--;
    else if(xy[i-1][j] > xy[i][j-1])
        i--;
    else j--;
}

while(!s.empty()){
    g<<s.top()<<" ";
    s.pop();
}

return 0;
}