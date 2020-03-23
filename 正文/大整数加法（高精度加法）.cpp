#include<cstdio>
#include<cstring>
typedef long long LL;
struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len=0;
	}
};

bign change(char str[]){	//������ת��Ϊbign 
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-i-1]-'0';	//�渳ֵ 
	} 
	return a; 
}

int compare(bign a,bign b){
	//�Ƚ�a��b��С��a����ȡ�aС�ֱ𷵻�1,0,-1
	if(a.len>b.len)	return 1;
	else if(a.len<b.len) return -1;
	else{
		for(int i=a.len-1;i>=0;i--){
			if(a.d[i]>b.d[i]) return 1;
			else if(a.d[i]<b.d[i]) return -1;
		}
		return 0;
	} 
}

bign add(bign a,bign b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len||i<b.len;i++){
		int temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;	//��λ��Ϊ��λ�Ľ�� 
		carry=temp/10;	//ʮλ��Ϊ�µĽ�λ 
	}
	if(carry!=0){	//�������λ��Ϊ0����ֱ�Ӹ�����������λ 
		c.d[c.len++]=carry;
	}
	return c; 
}

bign sub(bign a,bign b){
	bign c;
	for(int i=0;i<a.len||i<b.len;i++){	//�Խϳ���Ϊ���� 
		if(a.d[i]<b.d[i]){
			a.d[i+1]--;	//���λ��λ 
			a.d[i]+=10;	//��ǰλ+10 
		} 
		c.d[c.len++]=a.d[i]-b.d[i];	//�������Ϊ��ǰλ��� 
	}
	while(c.len>1&&c.d[c.len-1]==0){
		c.len--;	//ȥ����λ��0��ͬʱ���ٱ���һλ���λ 
	} 
	return c; 
}

bign multi(bign a,LL b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len;i++){
		int temp=a.d[i]*b+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	} 
	while(carry!=0){
		//�ͼӷ���һ�����˷��Ľ�λ���ܲ�ֹһλ�������while
		c.d[c.len++]=carry%10;
		carry/=10; 
	}
	return c;
} 

bign divide(bign a,LL b,LL& r){
	bign c;
	c.len=a.len;	//��������ÿһλ���̵�ÿһλ��һһ��Ӧ�ģ������������
	for(int i=a.len-1;i>=0;i--){
		r=r*10+a.d[i];	//����һλ������������� 
		if(r<b) c.d[i]=0;	//����������λΪ0
		else{
			c.d[i]=r/b;
			r=r%b;
		}
	} 
	while(c.len>1&&c.d[c.len-1]==0){
		c.len--;
	}
	return c;
}
void print(bign a){
	for(int i=a.len-1;i>=0;i--){
		printf("%d",a.d[i]);
	}
}

int main(){
	char str1[1000],str2[1000];
	printf("�߾��ȼӷ�����\n�����������߾�������\n");
	scanf("%s%s",str1,str2);
	bign a=change(str1);
	bign b=change(str2);
	print(add(a,b));
	printf("\n");
	printf("�߾��ȼ�������\n�����������߾�������\n");
	printf("%d",compare(a,b));
	printf("\n");
	if(compare(a,b)==-1){
		bign temp=a;
		a=b;
		b=temp;
		printf("%c",'-');
	}
	print(sub(a,b));
	printf("\n");
	printf("�߾��ȳ˷�����\n������һ���߾���������һ��long long������\n");
	char str3[1000];
	LL n4;
	scanf("%s%lld",str3,&n4);
	bign c=change(str3);
	print(multi(c,n4));
	printf("�߾��ȳ˷�����\n������һ���߾���������һ��long long������\n");
	char str5[1000];
	LL n6;
	scanf("%s%lld",str5,&n6);
	bign d=change(str5);
	LL r=0;
	print(divide(d,n6,r));
	printf("����Ϊ%lld\n",r);
	return 0;
}
