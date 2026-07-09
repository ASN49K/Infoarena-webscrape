#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector <int> V1;
vector <int> V2;
vector <int> result;

void solve(){
    int M, N;
    fin >> M >> N;

    while(M--){
        int x;
        fin >> x;
        V1.push_back(x);
    }

    while(N--){
        int x;
        fin >> x;
        V2.push_back(x);
    }


    unsigned int starting_index = 0;
    unsigned int iterator_index;
    unsigned int i = 0;

    for(; i < V1.size(); i++){
        iterator_index = starting_index;
        while(iterator_index < V2.size()){
            if(V1[i] == V2[iterator_index]){
                result.push_back(V1[i]);
                starting_index = iterator_index+1;
                break;
            }
        iterator_index++;
        }
    }

    fout << result.size() << "\n";
    i = 0;
    for(; i < result.size(); i++)
        fout << result[i] << " ";

    return;
}



int main(){

solve();

return 0;
}
