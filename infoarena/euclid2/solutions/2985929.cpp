
#include <bits/stdc++.h>

using namespace std;


int main()
{
  ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");
   int a, b, r, n;
   fin >> n;
   
       while(fin >> a >> b){
       
while(b != 0){
    r = a%b;
    a = b;
    b = r;
    
}
fout << a;
}
fin.close();
fout.close();
}