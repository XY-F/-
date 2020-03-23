#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cmath> 
using namespace std; 

void swap(int& a,int& b){
	int temp=a;
	a=b;
	b=temp;
}
const int MAXN=100;
int randPartition(int A[],int left,int right){
	int p=round(1.0*rand()/RAND_MAX*(right-left)+left); 
	//1.0* Ϊ�˵õ�������
	//rand() Ϊ�˵õ������
	// /RAND_MAX Ϊ�˵õ�0~1֮��������
	//*(right-left) �������䳤�ȣ��൱��ͶӰ����
	//+left ������� 
	swap(A[p],A[left]);	//����A[p]��A[left] 
	int temp=A[left];
	while(left<right){
		while(left<right&&A[right]>temp) right--;
		A[left]=A[right];
		while(left<right&&A[left]<temp) left++;
		A[right]=A[left];
	}
	A[left]=temp;
	return left;
} 

//���ѡ���㷨����A[left,right]�з��ص�K�����
int randSelect(int A[],int left,int right,int K){
	if(left==right) return A[left];	//�߽�
	int p=randPartition(A,left,right);	//���ֺ���Ԫ��λ��Ϊ p
	int M=p-left+1;	//A[p]��A[left,right]�еĵ�M��
	if(K==M) return A[p];	//�ҵ��� K�����
	if(K<M){	//��K���������Ԫ���
		return randSelect(A,left,p-1,K);	
		//����Ԫ����ҵ�K�� 
	} else {	//��K���������Ԫ�Ҳ�
		return randSelect(A,p+1,right,K-M); 
		//����Ԫ�Ҳ��ҵ�K-M�� 
		} 
} 

int Read(int A[]){
	printf("����������ҵ����飬��9999������\n");
	int x=0,i=0;
	while(x!=9999){
		scanf("%d",&x);
		A[i++]=x;
	}
	return i-1;
}

int main(){
	int A[MAXN],len,k;
	len=Read(A);
	printf("����Ҫ���ҵڼ��������\n");
	scanf("%d",&k);
	int m=randSelect(A,0,len-1,k);
	printf("��%d�������%d\n",k,m);
	return 0;
}

