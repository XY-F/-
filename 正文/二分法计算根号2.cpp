#include<cstdio>
#include<cmath> 
//�������2�Ľ���ֵ
//�����ƹ�Ϊ����һ��������[L,R]�ϵĵ�������f(x),�󷽳�f(x)=0�ĸ� 
const double eps=1e-5;	//����Ϊ10^-5
double f(double x){	//����f(x) 
	return x*x;
} 
double calSqrt(){
	double left=1,right=2,mid;	//[left,right]=[1,2]
	while(right-left>eps){
		mid=left+(right-left)/2;	//ȡleft��right���е�
		if(f(mid)>2){	//mid>sqrt(2)
			right=mid;	//����������[left,mid]�����ƽ� 
		} else {		//mid<sqrt(2) 
			left=mid;	//����������[mid,right]�����ƽ� 
		}
	}
	return mid;		//����mid��Ϊsqrt(2)�Ľ���ֵ 
}

int main(){
	double a=calSqrt();
	printf("%lf\n",a);
	printf("%lf\n",calSqrt());
	return 0;
}
