#include<cstdio>
#include<cmath>
const double PI=acos(-1.0);	//PI
const double eps=1e-5;	//����Ϊ10-5
double f(double R,double h){	//����r=f(h),��ʵ�ʺ����֪r����h����
	double alpha=2*acos((R-h)/R);
	double L=2*sqrt(R*R-(R-h)*(R-h));
	double S1=alpha*R*R/2-L*(R-h)/2;
	double S2=PI*R*R/2;
	return S1/S2; 
}
double solve(double R,double r){
	double left=0,right=R,mid;	//[left,right]=[0,R]
	while(right-left>eps){
		mid=left+(right-left)/2;	//ȡleft��right���е�
		if(f(R,mid)>r){
			right=mid;	//����������[left,mid]�����ƽ� 
		}else{
			left=mid;	//����������[mid,right]�����ƽ� 
		}
	} 
	return mid;	//����mid��Ϊ�����ˮ��߶� h 
}
int main(){
	double R,r;
	scanf("%lf%lf",&R,&r);
	printf("%.4f\n",solve(R,r));
	return 0; 
}
