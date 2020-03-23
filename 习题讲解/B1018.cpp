#include<cstdio>
int change(char c){
	if(c=='B') return 0;
	if(c=='C') return 1;
	if(c=='J') return 2;
}

int main(){
	char mp[3]={'B','C','J'};
	int n;
	scanf("%d",&n);
	int times_A[3]={0},time_B[3]={0};	//分别记录甲、乙的胜、平、负的次数 
	int hand_A[3]={0},hand_B[3]=0;
	char c1,c2;
	int k1,k2;
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c %c",&c1,&c2);
		k1=change(c1);
		k2=change(c2);
		if((k1+1)%3==k2){
			times_A[0]++;
			times_B[2]++;
			hand_A[k1]++;
		}else if(k1==k2);
		
	}
} 
