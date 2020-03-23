#include<cstdio>
#include<cmath>
const int maxn=11;
int n,P[maxn],hashTable[maxn]={false};

int generateP(int index,int count){
	if(index==n+1){
		bool flag=true;
		for(int i=1;i<=n;i++){	
			for(int j=1;j<=n;j++){
				if(abs(i-j)==abs(P[i]-P[j])){	//遍历整个棋盘，看是皇后是否在对角线上 
					flag=false; 
				}
			}
		}
		if(flag) count++;
		for(int i=1;i<=n;i++){
			printf("%d",P[i]);
		}
		printf("\n");
		return count;
	}
	for(int x=1;x<=n;x++){
		if(hashTable[x]==false){
			P[index]=x;
			hashTable[x]=true;
			generateP(index+1,count);
			hashTable[x]=false;
		}
	}
} 
int main(){
	n=8;
	int count=generateP(1,0);
	printf("count=%d",count);
	return 0;
}
