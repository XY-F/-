//快速幂
//如果b是奇数，那么有a^b=a*a^(b-1)
//如果b是偶数，那么有a^b=a^(b/2)*a^(b/2)
//显然，b是奇数的情况总可以在下一步转换为b是偶数的情况，而b是偶数的
//情况总可以在下一步转换为b/2的情况。这样，在log(b)级别次数的转换后，就可以
//把b变为0，而任何正整数的0次方都是1
//这显然是递归的思想，于是可以得到快速幂的递归写法，时间复杂度为O(logb) 

#include<cstdio>
typedef long long LL;
//求a^b%m，递归写法
LL binaryPow(LL a,LL b,LL m){
	if(b==0) return 1;	//如果b为0，那么a^0=1
	//b为奇数，转换为b-1
	if(b&1) return a*binaryPow(a,b-1,m)%m;
	else{	//b为偶数，转换为b/2
		LL mul=binaryPow(a,b/2,m);
		return mul*mul%m; 
	} 
} 

int main(){
	printf("ans=%lld",binaryPow(259321,287486,291543));
	return 0;
}
