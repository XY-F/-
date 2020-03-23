#include<cstdio>
//A[]为递增序列，x为欲查询的数，函数返回第一个大于等于x的元素的位置
//二分上下界为左闭右闭的[left,right]，传入的初值为[0,n]
int lower_bound(int A[],int left,int right,int x){
	int mid;	//mid为left和right的中点
	while(left<right){	//对[left,right]来说，left==right意味着找到唯一位置
	//想要返回第一个大于等于x的元素的位置，不需要判断元素x本身是否存在，
	//就算它不存在，返回的也是“假设它存在，它应该存在的位置”，于是当
	//left==right时，[left,right]刚好能夹出唯一的位置，就是需要的结果 
		mid=left+(right-left)/2;	//取中点 
		if(A[mid]>=x){	//中间的数大于等于x 
			right=mid;	//往左子区间[left,mid]查找 
		}else{	//中间的数小于x
			left=mid+1;	//往右子区间[mid+1,right]查找 
		}
	}
	if(A[left]<x)return left+1;
	else return left;
	//根据判断条件left<right,实际上left==right和left>right
	//都可以作为返回结果 
}

//A[]为递增序列，x为欲查询的数，函数返回第一个大于x的元素的位置
//二分上下界为左闭右闭的[left,right]，传入的初值为[0,n]
int upper_bound(int A[],int left,int right,int x){
	int mid;	//mid为left和right的中点
	while(left<right){	//对[left,right]来说，left==right意味着找到唯一位置
	//那样就不是区间了 
		mid=left+(right-left)/2;	//取中点 
		if(A[mid]>x){	//中间的数大于x 
			right=mid;	//往左子区间[left,mid]查找 
		}else{	//中间的数小于等于x，注意是小于等于 
			left=mid+1;	//往右子区间[mid+1,right]查找 
		} 
	}
	if(A[left]<=x)return left+1;
	else return left; 	//返回夹出来的位置 
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
