#include<cstdio>
 //A[]Ϊ�ϸ�������У�leftΪ�����½磬rightΪ�����Ͻ磬xΪ����ѯ����
 //��������Ϊ����ұյ�[left,right]������ĳ�ֵΪ[0,n-1]
 int binarySearch(int A[],int left,int right,int x){
 	int mid;	//midΪleft��right���е� 
 	while(left<=right){	//���left>right��û�취�γɱ������� 
		mid=(left+right)/2;	//ȡ�е�
		if(A[mid]==x) return mid;	//�ҵ�x�������±�
		else if(A[mid]>x){	//�м��������x 
			right=mid-1;	//����������[left,mid-1]���� 
		}else{
			left=mid+1;	//����������[mid+1,right]����	
		}
	}
	return -1;
 }
  
 
 int main(){
 const int n=10;
	int A[n]={1,3,4,6,7,8,10,11,12,15};
	printf("%d %d\n",binarySearch(A,0,n-1,6),binarySearch(A,0,n-1,9));
	return 0;	
 } 
