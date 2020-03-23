#include<cstdio>

const int maxn=100;
//������A��[L1,R1]��[L2,R2]����ϲ�Ϊ�������䣨�˴�L2��ΪR1+1��
void merge(int A[],int L1,int R1,int L2,int R2){
	int i=L1,j=L2;	//iָ��A[L2],jָ��A[L2]
	int temp[maxn],index=0;	//temp��ʱ��źϲ�������飬indexΪ���±�
	while(i<=R1&&j<=R2){
		if(A[i]<=A[j]){	//���A[i]<=A[j]
			temp[index++]=A[i++];	//��A[i]��������temp 
		}else{	//���A[i]>A[j] 
			temp[index++]=A[j++];
		} //��֮�ѽ�С�ļ���temp[] 
	} 
	while(i<=R1)temp[index++]=A[i++];	
	//��[L1,R1]��ʣ��Ԫ�ؼ�������temp
	while(j<=R2)temp[index++]=A[j++];
	//�������������ж���ʣ���Ԫ��
	//������Ϊ�ϲ��Ǵ��������ж�ֻ��һ��Ԫ�ؿ�ʼ
	//���Ե�������Ԫ�ظ�������2ʱ���������� 
	for(i=0;i<index;i++){	//ע�⵽index��ʱӦ���ǵ���R2 
		A[L1+i]=temp[i];	//���ϲ�������и�ֵ������A 
	} 
} 
//��array���鵱ǰ����[left,right]���й鲢����
void mergeSort(int A[],int left,int right){
	if(left<right){	//ֻҪleftС��right
		int mid=left+(right-left)/2;	//ȡ[left,right]���е�
		mergeSort(A,left,mid);	//�ݹ飬����������[left,mid]�鲢ƽ����
		mergeSort(A,mid+1,right);	//�ݹ飬����������[mid+1,right]�鲢����
		merge(A,left,mid,mid+1,right);	//�������������������ϲ� 		 
	} 
}  

int Read(int A[]){
	printf("��������Ҫ�鲢��������飺\n");
	int x=0,i=0;
	while(x!=9999){
		scanf("%d",&x);
		A[i++]=x;
	}
	return i-1;
}
int main(){
	int A[maxn];
	int len=Read(A);
	mergeSort(A,0,len-1);
	int i=0;
	for(i=0;i<len-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[i]);
	return 0;
}
