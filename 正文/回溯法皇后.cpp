#include<cstdio>
#include<cmath>
const int maxn=11;
int count=0;
int n,hashTable[maxn]={false},P[maxn];
void generateP(int index){
	if(index==n+1){			//�ݹ�߽磬����ܵ���һ��˵��ǰ�涼�ɹ��� 
		count++;
		for(int i=0;i<index;i++){
			printf("%d",P[i]);
		}
		printf("\n");
		return;
	}
	for(int x=1;x<=n;x++){	//�ӵ�1����n�����б��� 
		if(hashTable[x]==false){	//�����x�л�û�лʺ�
			bool flag=true; 	//flagΪtrue��ʾ��ǰ�Ļʺ󲻻��֮ǰ�Ļʺ��ͻ
			for(int pre=1;pre<index;pre++){	//����֮ǰ�Ļʺ� 
			//��index�лʺ���к�Ϊx����pre�лʺ���к�ΪP[pre]
				if(abs(index-pre)==abs(x-P[pre])){
					flag=false;	//��֮ǰ�Ļʺ���һ���Խ��ߣ���ͻ
					break; 
				} 
			} 
		if(flag){	//������԰ѻʺ���ڵ�x�� 
			P[index]=x;	//���index�лʺ���к�Ϊx 
			hashTable[x]=true;	//��x���ѱ�ռ�� 
			generateP(index+1);	//�ݹ鴦���index+1�лʺ� 
			hashTable[x]=false; //�ݹ���ϣ���ԭ��x��Ϊδռ��		 
			}
		} 
	}
}

int main(){
	n=5;
	generateP(1);
	printf("count=%d",count);
	return 0;
}
