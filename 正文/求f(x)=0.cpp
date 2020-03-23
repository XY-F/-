//一个计算f(x)=0的根的模板
#include<cstdio>
#include<cmath> 

const double eps=1e-5;	//精度为10^5 
double f(double x){		//计算f(x)
	return x*x-2; 
}
double solve(double L,double R){
	double left=L,right=R,mid;	//[left,right]=[1,2]
	while(right-left>eps){
		mid=left+(right-left)/2;
		if(f(mid)>0){
			right=mid;	//往左子区间[left,mid]继续逼近 
		}else{
			left=mid;	//往右子区间[mid,right]继续逼近 
		}
	} 
	return mid; 
}
int main(){
	printf("%lf",solve(1,2));
	return 0;
}
