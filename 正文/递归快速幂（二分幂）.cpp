//������
//���b����������ô��a^b=a*a^(b-1)
//���b��ż������ô��a^b=a^(b/2)*a^(b/2)
//��Ȼ��b������������ܿ�������һ��ת��Ϊb��ż�����������b��ż����
//����ܿ�������һ��ת��Ϊb/2���������������log(b)���������ת���󣬾Ϳ���
//��b��Ϊ0�����κ���������0�η�����1
//����Ȼ�ǵݹ��˼�룬���ǿ��Եõ������ݵĵݹ�д����ʱ�临�Ӷ�ΪO(logb) 

#include<cstdio>
typedef long long LL;
//��a^b%m���ݹ�д��
LL binaryPow(LL a,LL b,LL m){
	if(b==0) return 1;	//���bΪ0����ôa^0=1
	//bΪ������ת��Ϊb-1
	if(b&1) return a*binaryPow(a,b-1,m)%m;
	else{	//bΪż����ת��Ϊb/2
		LL mul=binaryPow(a,b/2,m);
		return mul*mul%m; 
	} 
} 

int main(){
	printf("ans=%lld",binaryPow(259321,287486,291543));
	return 0;
}
