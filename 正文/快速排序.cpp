#include<cstdio> 
#include<cstdlib>
#include<ctime>
#include<cmath>
const int maxn=100;

//ѡȡ�����Ԫ��������[left,right]���л���
int randPartition(int A[],int left,int right){
	//����[left,right]�ڵ������p
	int p=(round(1.0*rand()/RAND_MAX*(right-left)+left));
	int temp=A[left];	//��A[left]�������ʱ����temp
	while(left<right){	//ֻҪleft��right������
		while(left<right&&A[right]>temp) right--;
		//��������right
		A[left]=A[right];	//��A[right]Ų��A[left]
		while(left<right&&A[left]<=temp) left++;
		//��������left
		A[right]=A[left];	//��A[left]Ų��A[right]	 
	} 
	A[left]=temp;	//��temp�ŵ�left��right�����ĵط�
	return left;	//�����������±� 
} 

//��������˼·
//1. ���������е�Ԫ�أ�ʹ��ǰ��������˵�Ԫ���ڵ���������
//�������Ԫ�ؾ���������Ԫ�ء��Ҳ�����Ԫ�ؾ����ڸ�Ԫ��
//2. �Ը�Ԫ�ص������Ҳ�ֱ�ݹ����1.�ĵ�����ֱ����ǰ
//��������ĳ��Ȳ����� 1 

//��������left��right��ֵΪ������β�±꣨����1��n��
void quickSort(int A[],int left,int right){
	if(left<right){	//��ǰ����ĳ��Ȳ�����1
		//��[left,right]��A[left]һ��Ϊ��
		int pos=randPartition(A,left,right);
		quickSort(A,left,pos-1);	//����������ݹ���п������� 
		quickSort(A,pos+1,right); 	//����������ݹ���п������� 
	}
} 


int Read(int A[]){
	printf("��������Ҫ������������飬��9999������\n");
	int x=0,i=0;
	while(x!=9999){
		scanf("%d",&x);
		A[i++]=x;
	}
	return i-1;
}
int main(){
	srand((unsigned)time(NULL));
	int A[maxn];
	int len=Read(A);
	quickSort(A,0,len-1);
	int i=0;
	for(i=0;i<len-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[i]);
	return 0;
}
