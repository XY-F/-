#include<cstdio>
#include<cmath> 

const int maxn=11;
int n,P[maxn]={0},hashTable[maxn]={false};	//P[]��¼��n���еĻʺ����ڵ��� 
int count=0;
void generateP(int index){		 
	if(index==n+1){		//�ݹ�߽磬����������n+1��λ 
		bool flag=true;	//��¼�Ƿ����n�ʺ����� 
		for(int i=1;i<=n;i++){	
			for(int j=1;j<=n;j++){
				if(abs(i-j)==abs(P[i]-P[j])){	//�����������̣����ǻʺ��Ƿ��ڶԽ����� 
					flag=false; 
				}
			}
		}
		if(flag) count++; //����������󶼲��ڶԽ����ϣ�����+1 
		return;
	}
	for(int x=1;x<=n;x++){
		if(hashTable[x]==false){
			P[index]=x;
			hashTable[x]=true;
			generateP(index+1);
			hashTable[x]=false;	//��ԭ״̬������ 1,������1����ԭ1��״̬��12,21��������2����ԭ2��״̬ 
		}
	}
}
int main(){
	n=9;
	generateP(1);
	printf("count=%d",count);
	return 0;
}
