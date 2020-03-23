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
	//1.0* 为了得到浮点数
	//rand() 为了得到随机数
	// /RAND_MAX 为了得到0~1之间的随机数
	//*(right-left) 乘以区间长度，相当于投影拉伸
	//+left 修正起点 
	swap(A[p],A[left]);	//交换A[p]和A[left] 
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

//随机选择算法，从A[left,right]中返回第K大的数
int randSelect(int A[],int left,int right,int K){
	if(left==right) return A[left];	//边界
	int p=randPartition(A,left,right);	//划分后主元的位置为 p
	int M=p-left+1;	//A[p]是A[left,right]中的第M大
	if(K==M) return A[p];	//找到第 K大的数
	if(K<M){	//第K大的数在主元左侧
		return randSelect(A,left,p-1,K);	
		//往主元左侧找第K大 
	} else {	//第K大的数在主元右侧
		return randSelect(A,p+1,right,K-M); 
		//往主元右侧找第K-M大 
		} 
} 

int Read(int A[]){
	printf("请输入待查找的数组，以9999结束：\n");
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
	printf("请问要查找第几大的数？\n");
	scanf("%d",&k);
	int m=randSelect(A,0,len-1,k);
	printf("第%d大的数是%d\n",k,m);
	return 0;
}

