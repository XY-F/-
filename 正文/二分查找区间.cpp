#include<cstdio>
//A[]Ϊ�������У�xΪ����ѯ�������������ص�һ�����ڵ���x��Ԫ�ص�λ��
//�������½�Ϊ����ұյ�[left,right]������ĳ�ֵΪ[0,n]
int lower_bound(int A[],int left,int right,int x){
	int mid;	//midΪleft��right���е�
	while(left<right){	//��[left,right]��˵��left==right��ζ���ҵ�Ψһλ��
	//��Ҫ���ص�һ�����ڵ���x��Ԫ�ص�λ�ã�����Ҫ�ж�Ԫ��x�����Ƿ���ڣ�
	//�����������ڣ����ص�Ҳ�ǡ����������ڣ���Ӧ�ô��ڵ�λ�á������ǵ�
	//left==rightʱ��[left,right]�պ��ܼг�Ψһ��λ�ã�������Ҫ�Ľ�� 
		mid=left+(right-left)/2;	//ȡ�е� 
		if(A[mid]>=x){	//�м�������ڵ���x 
			right=mid;	//����������[left,mid]���� 
		}else{	//�м����С��x
			left=mid+1;	//����������[mid+1,right]���� 
		}
	}
	if(A[left]<x)return left+1;
	else return left;
	//�����ж�����left<right,ʵ����left==right��left>right
	//��������Ϊ���ؽ�� 
}

//A[]Ϊ�������У�xΪ����ѯ�������������ص�һ������x��Ԫ�ص�λ��
//�������½�Ϊ����ұյ�[left,right]������ĳ�ֵΪ[0,n]
int upper_bound(int A[],int left,int right,int x){
	int mid;	//midΪleft��right���е�
	while(left<right){	//��[left,right]��˵��left==right��ζ���ҵ�Ψһλ��
	//�����Ͳ��������� 
		mid=left+(right-left)/2;	//ȡ�е� 
		if(A[mid]>x){	//�м��������x 
			right=mid;	//����������[left,mid]���� 
		}else{	//�м����С�ڵ���x��ע����С�ڵ��� 
			left=mid+1;	//����������[mid+1,right]���� 
		} 
	}
	if(A[left]<=x)return left+1;
	else return left; 	//���ؼг�����λ�� 
} 

int main(){
const int n=5;
int A[n]={1,3,3,3,6};
printf("%d %d\n",lower_bound(A,0,4,3),upper_bound(A,0,4,3));
printf("%d %d\n",lower_bound(A,0,4,5),upper_bound(A,0,4,5));
printf("%d %d\n",lower_bound(A,0,4,6),upper_bound(A,0,4,6));
printf("%d %d\n",lower_bound(A,0,4,8),upper_bound(A,0,4,8));
return 0;	
} 
