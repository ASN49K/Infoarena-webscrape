#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v1,v2;
vector<int> x, vMax;
int n,m, maxLength=0;
bool valid(){
    int contor = 0;
    for(auto it : x){
        if(find(v2.begin()+contor, v2.end(), it)==v2.end()){
            return 0;
        }
    }
    return 1;
}
void changeMax(){
    if(x.size()>maxLength){
        vMax = x;
        maxLength = x.size(); 
    }
}
void back(int k){
    for(int i=k; i<n; i++){
        x.push_back(v1[i]);
        if(valid()){
            changeMax();
            back(i+1);
            x.pop_back();
        }
        else{
            x.pop_back();
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int local;
        cin>>local;
        v1.push_back(local);
    }
    for(int i=0;i<m;i++){
        int local;
        cin>>local;
        v2.push_back(local);
    }
    back(0);
    printf("%i\n", maxLength);
    for(auto it : vMax){
        cout<<it<<" ";
    }
    return 0;
}