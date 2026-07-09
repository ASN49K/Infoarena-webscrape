#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > solutions;

int size_first, size_second;
int* first, *second;

int index_in(int value, int *arr, int start, int end) {
    for (int i = start; i < end; i++) {
        if (arr[i] == value){
            return i;
        }
    }
    return -1;
}

int longest_commom_substr(int i_first, int i_second, vector<int>& current_sol) {
    if (i_second == size_second) {
        vector<int> sol_clone = current_sol;
        solutions.push_back(sol_clone);
        current_sol.pop_back();
        return 0;
    }  
    int pos;
    int max = -1, current = 0;
    for (int i = i_second; i < size_second; i++) {
        pos = index_in(second[i], first, i_first, size_first);
        if (pos != -1) {
            current_sol.push_back(first[pos]);
            current = longest_commom_substr(pos + 1, i + 1, current_sol);
            if (current > max) {
                max = current;
            }
        }        
    }
    return max + 1;
}

int main() {
    ifstream in("./cmlsc.in");
    ofstream out("./cmlsc.out");

    in >> size_first >> size_second;
    first = new int[size_first];
    second = new int[size_second];
    for (int i = 0; i < size_first; i++) {
        in >> first[i];
    } 
    for (int i = 0; i < size_second; i++) {
        in >> second[i];
    }
    vector<int> v;
    unsigned int size = longest_commom_substr(0, 0, v);
    out << size << endl;
    for (vector<vector<int> >::iterator it = solutions.begin(); it != solutions.end() ; ++it) {
        if ( size == (*it).size()) {
            unsigned int i = 0;
            vector<int> sol = *it;
            out << sol[0];
            for ( i = 1; i < size; i++) {
                out << " " << sol[i];
            }
            return 0;
        }   
    }
    return 0;
}
