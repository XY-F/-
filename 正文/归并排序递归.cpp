#include<cstdio>

const int maxn=100;
//将数组A的[L1,R1]与[L2,R2]区间合并为有序区间（此处L2即为R1+1）
void merge(int A[],int L1,int R1,int L2,int R2){
	int i=L1,j=L2;	//i指向A[L2],j指向A[L2]
	int temp[maxn],index=0;	//temp临时存放合并后的数组，index为其下表
	while(i<=R1&&j<=R2){
		if(A[i]<=A[j]){	//如果A[i]<=A[j]
			temp[index++]=A[i++];	//将A[i]加入序列temp 
		}else{	//如果A[i]>A[j] 
			temp[index++]=A[j++];
		} //总之把较小的加入temp[] 
	} 
	while(i<=R1)temp[index++]=A[i++];	
	//将[L1,R1]的剩余元素加入序列temp
	while(j<=R2)temp[index++]=A[j++];
	//不可能两个数列都有剩余的元素
	//而且因为合并是从两个序列都只有一个元素开始
	//所以当序列中元素个数大于2时，序列有序 
	for(i=0;i<index;i++){	//注意到index此时应该是等于R2 
		A[L1+i]=temp[i];	//将合并后的序列赋值回数组A 
	} 
} 
//将array数组当前区间[left,right]进行归并排序
void mergeSort(int A[],int left,int right){
	if(left<right){	//只要left小于right
		int mid=left+(right-left)/2;	//取[left,right]的中点
		mergeSort(A,left,mid);	//递归，将左子区间[left,mid]归并平排序
		mergeSort(A,mid+1,right);	//递归，将右子区间[mid+1,right]归并排序
		merge(A,left,mid,mid+1,right);	//将左子区间和右子区间合并 		 
	} 
}  

int Read(int A[]){
	printf("请输入需要归并排序的数组：\n");
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
