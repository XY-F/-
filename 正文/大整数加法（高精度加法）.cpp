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

bign change(char str[]){	//将整数转换为bign 
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-i-1]-'0';	//逆赋值 
	} 
	return a; 
}

int compare(bign a,bign b){
	//比较a和b大小，a大、相等、a小分别返回1,0,-1
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
		c.d[c.len++]=temp%10;	//个位数为该位的结果 
		carry=temp/10;	//十位数为新的进位 
	}
	if(carry!=0){	//如果最后进位不为0，则直接赋给结果的最高位 
		c.d[c.len++]=carry;
	}
	return c; 
}

bign sub(bign a,bign b){
	bign c;
	for(int i=0;i<a.len||i<b.len;i++){	//以较长的为界限 
		if(a.d[i]<b.d[i]){
			a.d[i+1]--;	//向高位借位 
			a.d[i]+=10;	//当前位+10 
		} 
		c.d[c.len++]=a.d[i]-b.d[i];	//减法结果为当前位结果 
	}
	while(c.len>1&&c.d[c.len-1]==0){
		c.len--;	//去除高位的0，同时至少保留一位最低位 
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
		//和加法不一样，乘法的进位可能不止一位，因此用while
		c.d[c.len++]=carry%10;
		carry/=10; 
	}
	return c;
} 

bign divide(bign a,LL b,LL& r){
	bign c;
	c.len=a.len;	//被除数的每一位和商的每一位是一一对应的，因此先令长度相等
	for(int i=a.len-1;i>=0;i--){
		r=r*10+a.d[i];	//和上一位遗留的余数组合 
		if(r<b) c.d[i]=0;	//不够除，该位为0
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
	printf("高精度加法运算\n请输入两个高精度整数\n");
	scanf("%s%s",str1,str2);
	bign a=change(str1);
	bign b=change(str2);
	print(add(a,b));
	printf("\n");
	printf("高精度减法运算\n请输入两个高精度整数\n");
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
	printf("高精度乘法运算\n请输入一个高精度整数和一个long long型整数\n");
	char str3[1000];
	LL n4;
	scanf("%s%lld",str3,&n4);
	bign c=change(str3);
	print(multi(c,n4));
	printf("高精度乘法运算\n请输入一个高精度整数和一个long long型整数\n");
	char str5[1000];
	LL n6;
	scanf("%s%lld",str5,&n6);
	bign d=change(str5);
	LL r=0;
	print(divide(d,n6,r));
	printf("余数为%lld\n",r);
	return 0;
}
