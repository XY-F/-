#include<cstdio> 
typedef long long LL;
//a^b%m, ����д�� 
LL binaryPow(LL a,LL b,LL m){
	LL ans=1;
 	while(b>0){
 		if(b&1){	//���b�Ķ�����ĩβΪ1(Ҳ����д��if(b%2))
		 	ans=ans*a%m;	//��ans�ۻ���a 
 		}
		 a=a*a%m;	//��aƽ��
		 b>>=1;	//��b�Ķ���������1λ����b=b>>1��b=b/2 
 	}
	return ans;
}

int main(){
	printf("ans=%lld\n",binaryPow(123422,548363,287345));
	return 0;
} 
