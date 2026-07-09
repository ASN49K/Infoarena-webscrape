#include <iostream>
#include <fstream>
using namespace std;


int main()
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,n;
fin>>n;
for(int i=1;i<=n;i++){
 fin>>a>>b;
  while(a!=b){
    if(a>b)a-=b;else b-=a;
 }
fout<<a<<endl;
}

}
