#include	<iostream>
#include	<cstdio>
using namespace std;


int s1[1025];
int s2[1025];
int lenS1,lenS2;
void read(){

	scanf("%d %d",&lenS1,&lenS2);
	for(int i =1; i <= lenS1; i++){
		scanf("%d",&s1[i]);
	}
	for(int i =1 ; i <= lenS2; i++){
		scanf("%d",&s2[i]);
	}

}

int getMax(int a,int b){
	return (a>b)?a:b;
}
int memo[1025][1025];
int solve(int indexS1,int indexS2){
	

	if(memo[indexS1][indexS2] != -1){
		return memo[indexS1][indexS2];
	}
	if(indexS1 == 0 || indexS2 == 0){
		return memo[indexS1][indexS2] = 0;
	}

	if(s1[indexS1] == s2[indexS2]){
		return memo[indexS1][indexS2] = solve(indexS1-1, indexS2-1) + 1;
	}

	return memo[indexS1][indexS2] = getMax(solve(indexS1-1,indexS2),solve(indexS1,indexS2-1));
	
}

void debug(){
	for(int i= 1 ; i <= lenS1; i++){
		for(int j = 1; j <= lenS2 ; j++){
			cout << memo[i][j] << " ";
		}
		cout << endl;
	}
}
void printSequence(int i,int j){
	
	if(i == 0 || j == 0)
		return ;
	if(s1[i] == s2[j])
	{
		printSequence(i-1,j-1);
		printf("%d ",s1[i]);
		return;
	}
	if(memo[i][j-1] >= memo[i-1][j])
		printSequence(i,j-1);
	else
		printSequence(i-1,j);
	return;

}
int main(){

	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	read();	
	for(int i =0 ; i <=lenS1;i ++){
		for(int j= 0; j <=lenS2; j++){
			memo[i][j] = -1;
		}
	}
	cout << solve(lenS1,lenS2) << endl;
	printSequence(lenS1,lenS2);
	cout << endl;
	return 0;
}