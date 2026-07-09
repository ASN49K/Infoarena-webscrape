#include <iostream>
#include<fstream>
using namespace std;
int algoritm(int x,int y){
while(x!=y)
{
if(x>y)
x=x-y;
else y=y-x;}
return x;}
int main()
{
    int a,b,i=0;
    long int n;
    ifstream f("euclid2.in");

    ofstream g("euclid2.out");
 f>>n;
  for(i=0;i<n;i++){
 f>>a>>b;  g<< algoritm(a,b)<<endl;}
    f.close();
    g.close();
    return 0;
}
