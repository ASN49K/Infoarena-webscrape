#include <iostream>
#include<fstream>
using namespace std;

int algoritm(int x,int y){int t;
while(y!=0){
t=y;
y=x%y;
x=t;}
return x;}
int main()
{
    int n,a,b;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
 f>>n;
for(int i=0;i<n;i++){
 f>>a>>b;  g<< algoritm(a,b)<<endl;
 n--;}
    f.close();
    g.close();
    return 0;
}
