#include <fstream>

using namespace std;

int euclid(int A, int B){
    if(B == 0)
        return A;
    else return euclid(B, A % B);
}

int main(){    
    
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");

   int T, A, B;
   cin >> T;
   for(; T >= 1; T--){

       cin >> A >> B;
       cout << euclid(A, B) << "\n";

   }

   cin.close();
   cout.close();
  
  return 0;
	
}