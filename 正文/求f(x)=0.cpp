//һ������f(x)=0�ĸ���ģ��
#include<cstdio>
#include<cmath> 

const double eps=1e-5;	//����Ϊ10^5 
double f(double x){		//����f(x)
	return x*x-2; 
}
double solve(double L,double R){
	double left=L,right=R,mid;	//[left,right]=[1,2]
	while(right-left>eps){
		mid=left+(right-left)/2;
		if(f(mid)>0){
			right=mid;	//����������[left,mid]�����ƽ� 
		}else{
			left=mid;	//����������[mid,right]�����ƽ� 
		}
	} 
	return mid; 
}
int main(){
	printf("%lf",solve(1,2));
	return 0;
}
