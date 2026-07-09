#include<bits/stdc++.h>
using namespace std;

int m, n;
string s1, s2;

int	solve(int m, int n, int l){
	if(m <= 0 || n <= 0){
		
	} else{
		
		if(s1[m-1] == s2[n-1]){
//			solve(m-1,n-1,l++);
			

//			for(int i = 0; i<n; i++)cout<<s1[i];
//			cout<<'\n';
//			for(int i = 0; i<m; i++)cout<<s2[i];
//			cout<<'\n';
		//	l = max(solve(m-2,n-1,l++), solve(m-1,n-2,l++));
			//l = solve(m-1,n-1,l++);
			l++;
			
			l = max(l, solve(m-1,n-1, l));
//						cout<<"l = "<<l<<'\n';
		} else{
			l = max(solve(m-1,n,l), solve(m,n-1,l));
			
//			cout<<"l = "<<l<<'\n';
		}	
	}	
	return l;
}

int main(){
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	
	cin>>m>>n;
	cin>>s1;
	cin>>s2;
	
//	m = s1.length();
//	n = s2.length();
	
	cout<<solve(m, n, 0);
//solve(m, n, l);
//cout<<l;
	
return 0;	
}
