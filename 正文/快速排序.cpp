#include<cstdio> 
#include<cstdlib>
#include<ctime>
#include<cmath>
const int maxn=100;

//选取随机主元，对区间[left,right]进行划分
int randPartition(int A[],int left,int right){
	//生成[left,right]内的随机数p
	int p=(round(1.0*rand()/RAND_MAX*(right-left)+left));
	int temp=A[left];	//将A[left]存放至临时变量temp
	while(left<right){	//只要left与right不相遇
		while(left<right&&A[right]>temp) right--;
		//反复左移right
		A[left]=A[right];	//将A[right]挪到A[left]
		while(left<right&&A[left]<=temp) left++;
		//反复右移left
		A[right]=A[left];	//将A[left]挪到A[right]	 
	} 
	A[left]=temp;	//把temp放到left与right相遇的地方
	return left;	//返回相遇的下标 
} 

//快速排序思路
//1. 调整序列中的元素，使当前序列最左端的元素在调整后满足
//左侧所有元素均不超过该元素、右侧所有元素均大于该元素
//2. 对该元素的左侧和右侧分别递归进行1.的调整，直到当前
//调整区间的长度不超过 1 

//快速排序，left与right初值为序列首尾下标（例如1与n）
void quickSort(int A[],int left,int right){
	if(left<right){	//当前区间的长度不超过1
		//将[left,right]按A[left]一分为二
		int pos=randPartition(A,left,right);
		quickSort(A,left,pos-1);	//对左子区间递归进行快速排序 
		quickSort(A,pos+1,right); 	//对右子区间递归进行快速排序 
	}
} 


int Read(int A[]){
	printf("请输入需要快速排序的数组，以9999结束：\n");
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
