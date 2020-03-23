//解决"寻找有序序列第一个满足某条件的元素的位置"问题的固定模板
//二分区间为左闭右闭的[left,right]，初值必须能覆盖解的所有可能取值
int solve(int left,int right){
	int mid;	//mid为left和right的中点
	while(left<right){	//对[left,right]来说，left==right意味着找到唯一位置
		mid=left+(right-left)/2;
		if(条件成立){	//条件成立，第一个满足条件的元素的位置<=mid
			right=mid;	//往左子区间[left,mid]查找 
		}else{
			left=mid+1;	//往右子区间[mid+1,right]查找 
		}
	} 
	return left; 
} 

//解决"寻找有序序列第一个满足某条件的元素的位置"问题的固定模板
//二分区间为左开右闭的(left,right]
//初值必须能覆盖解的所有可能取值，并且left比最小值小1
int solve(int left,int right){
	int mid;	//mid为left和right的中点
	while(left+1<right)	//对(left,right],left+1==right意味着唯一位置
	if(条件成立){	//条件成立，则第一个满足条件的元素的位置<=mid
	}else{	//条件不成立，则第一个满足条件的元素的位置>mid
		left=mid; 
	} 
	return right;
} 
