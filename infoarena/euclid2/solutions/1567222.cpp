#include <iostream>
#include<fstream>
using namespace std;
int algoritm(int x,int y){
if(y==0)
return x;
else
algoritm(x,x%y);}

int main()
{
    int a,b;
    long int n;
    ifstream f("euclid2.in");

    ofstream g("euclid2.out");
 f>>n;
while(n){
 f>>a>>b;  g<< algoritm(a,b)<<endl;
 n--;}
    f.close();
    g.close();
    return 0;
}
