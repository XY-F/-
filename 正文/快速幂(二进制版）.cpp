#include<cstdio> 
typedef long long LL;
//a^b%m, 迭代写法 
LL binaryPow(LL a,LL b,LL m){
	LL ans=1;
 	while(b>0){
 		if(b&1){	//如果b的二进制末尾为1(也可以写成if(b%2))
		 	ans=ans*a%m;	//令ans累积上a 
 		}
		 a=a*a%m;	//令a平方
		 b>>=1;	//将b的二进制右移1位，即b=b>>1或b=b/2 
 	}
	return ans;
}

int main(){
	printf("ans=%lld\n",binaryPow(123422,548363,287345));
	return 0;
} 
