#include<cstdio>
#include<cmath>
typedef long long LL;
LL pow(LL a, LL b, LL m){
	LL ans=1;
	for(int i=0;i<b;i++){
		ans=ans*a%m;
	}
	return ans;
}
int main(){
	printf("ans=%lld\n",pow(103,235324,123225));
	return 0;
}
