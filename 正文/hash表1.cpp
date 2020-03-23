#include<cstdio>
const int maxn=100010;
int hashTable[maxn]={0};
int main(){
	int n,m,x;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		hashTable[x]=-1;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		if(hashTable[x]==-1){
			hashTable[x]=1;
		}else if(hashTable[x]>0){
			hashTable[x]++; 
		}
		if(i!=m) printf("%d ",hashTable[x]);
		else	printf("%d",hashTable[x]);
	}

	return 0;
} 
