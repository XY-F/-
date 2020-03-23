#include<cstdio>
#include<cmath> 

const int maxn=11;
int n,P[maxn]={0},hashTable[maxn]={false};	//P[]记录了n个行的皇后所在的列 
int count=0;
void generateP(int index){		 
	if(index==n+1){		//递归边界，如果处理的是n+1号位 
		bool flag=true;	//记录是否符合n皇后条件 
		for(int i=1;i<=n;i++){	
			for(int j=1;j<=n;j++){
				if(abs(i-j)==abs(P[i]-P[j])){	//遍历整个棋盘，看是皇后是否在对角线上 
					flag=false; 
				}
			}
		}
		if(flag) count++; //如果所有王后都不在对角线上，计数+1 
		return;
	}
	for(int x=1;x<=n;x++){
		if(hashTable[x]==false){
			P[index]=x;
			hashTable[x]=true;
			generateP(index+1);
			hashTable[x]=false;	//还原状态。例如 1,处理完1，还原1的状态；12,21，处理完2，还原2的状态 
		}
	}
}
int main(){
	n=9;
	generateP(1);
	printf("count=%d",count);
	return 0;
}
