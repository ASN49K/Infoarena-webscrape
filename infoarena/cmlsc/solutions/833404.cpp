#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

long N; vector<int> seq;

void solve(vector<int>&a, vector<int>&b){

vector<int>p(a.size());
int li, ls;
b.push_back(0);
for(size_t i = 1; i < a.size(); i++){

if(a[i] > a[b.back()]){
p[i] =  b.back();
b.push_back(i);
continue;
}

for(li=0, ls=b.size()-1; li<ls;){
int lm = (li+ls)/2;
if (a[b[lm]] < a[i]) li=lm+1; else ls=lm;
}


if(a[i]< a[b[li]]){
if(li>0) p[i] = b[li-1];
b[li] = i;
}

}
for(li = b.size(), ls = b.back(); li --; ls = p[ls]) b[li] = ls;
}

void read(){
ifstream fin("scmax.in");
fin >> N;
for(int i=1; i<=N; i++){
int number;
fin >> number, seq.push_back(number);
}
}

int main(){

read();
vector<int>list;
solve(seq, list);

ofstream fout("scmax.out");
fout << list.size() << '\n';
for(size_t i=0; i<list.size(); i++){
fout << seq[list[i]] << " ";
}

return 0;
}
