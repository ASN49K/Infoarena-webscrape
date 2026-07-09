
#include <bits/stdc++.h>

using namespace std;


int main()
{
  ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");
   int a, b, r, n;
   fin >> n;
   
       while(fin >> a >> b){
       
cout << __gcd(a, b);
}
fin.close();
fout.close();
}