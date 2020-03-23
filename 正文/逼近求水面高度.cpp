#include<cstdio>
#include<cmath>
const double PI=acos(-1.0);	//PI
const double eps=1e-5;	//精度为10-5
double f(double R,double h){	//计算r=f(h),由实际含义可知r关于h递增
	double alpha=2*acos((R-h)/R);
	double L=2*sqrt(R*R-(R-h)*(R-h));
	double S1=alpha*R*R/2-L*(R-h)/2;
	double S2=PI*R*R/2;
	return S1/S2; 
}
double solve(double R,double r){
	double left=0,right=R,mid;	//[left,right]=[0,R]
	while(right-left>eps){
		mid=left+(right-left)/2;	//取left与right的中点
		if(f(R,mid)>r){
			right=mid;	//往左子区间[left,mid]继续逼近 
		}else{
			left=mid;	//往右子区间[mid,right]继续逼近 
		}
	} 
	return mid;	//返回mid即为所求的水面高度 h 
}
int main(){
	double R,r;
	scanf("%lf%lf",&R,&r);
	printf("%.4f\n",solve(R,r));
	return 0; 
}
