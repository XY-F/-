#include<cstdio>
#include<cmath> 
//计算根号2的近似值
//可以推广为给定一个定义在[L,R]上的单调函数f(x),求方程f(x)=0的根 
const double eps=1e-5;	//精度为10^-5
double f(double x){	//计算f(x) 
	return x*x;
} 
double calSqrt(){
	double left=1,right=2,mid;	//[left,right]=[1,2]
	while(right-left>eps){
		mid=left+(right-left)/2;	//取left与right的中点
		if(f(mid)>2){	//mid>sqrt(2)
			right=mid;	//往左子区间[left,mid]继续逼近 
		} else {		//mid<sqrt(2) 
			left=mid;	//往右子区间[mid,right]继续逼近 
		}
	}
	return mid;		//返回mid即为sqrt(2)的近似值 
}

int main(){
	double a=calSqrt();
	printf("%lf\n",a);
	printf("%lf\n",calSqrt());
	return 0;
}
