#include <fstream>
#include <queue>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int main(int argc, char *argv[]) {
    int ar=1024,br=1024;
	int a[ar],b[br];
	int l=0,x,y;
	cin>>x>>y;
	for(int i=1;i<=x;i++){
        cin>>a[i];
	}
	for(int i=1;i<=y;i++){
        cin>>b[i];
	}
	queue<int>q;
	for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(a[i]==b[j]){
                l++;
                q.push(a[i]);
            }
        }
	}
	cout<<l<<"\n";
	while(q.empty()!=true){
        cout<<q.front()<<" ";
        q.pop(q.front());
	}
}
