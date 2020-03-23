#include<cstdio>
#include<cmath>
const int maxn=100010;
bool is_prime(int n){
	if(n==1) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}

int prime[maxn],pNum=0;
void Find_Prime(){
	for(int i=1;i<maxn;i++){
		if(is_prime(i)==true){
			prime[pNum++]=i;
		}
	}
} 

struct factor{
	int x,cnt;	//x为质因子，cnt为其个数 
}fac[10];

int main(){
	Find_Prime();
	int n,num=0;	//num为n的不同质因子的个数 
	scanf("%d",&n);
	if(n==1)printf("1=1");
	else{
		printf("%d=",n);
		int sqr=(int)sqrt(1.0*n);
		//枚举根号n以内的质因子
		for(int i=0;i<pNum&&prime[i]<=sqr;i++){
			if(n%prime[i]==0){
				fac[num].x=prime[i]; 
				fac[num].cnt=0;
				while(n%prime[i]==0){
					fac[num].cnt++;
					n/=prime[i];
				}
				num++;
			}
			if(n==1) break;
		}
		if(n!=1){	//如果无法被根号n以内的质因子除尽 
		//此时n是被除剩下的数，它是一个大于根号n（原来的n）的质因子 
			fac[num].x=n;	//那么一定有一个大于根号n的质因子 
			fac[num++].cnt=1;
		}
		//按格式输出结果
		for(int i=0;i<num;i++){
			if(i>0) printf("*");
			printf("%d",fac[i].x);
			if(fac[i].cnt>1){
				printf("^%d",fac[i].cnt);
			}
		} 
	}  
	return 0;
}


