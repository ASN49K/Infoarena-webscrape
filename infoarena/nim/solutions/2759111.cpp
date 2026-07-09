#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

 
int main(){

ifstream cin("nim.in");
ofstream cout("nim.out");

int T, N;
cin >> T;

for(; T > 0; --T){
    cin >> N;
    int sxor = 0;
    for(int x; N > 0; --N){
        cin >> x;
        sxor ^= x;
    }
    if(sxor) cout << "DA\n";
        else cout << "NU\n";
}

cin.close();
cout.close();
return 0;
}

