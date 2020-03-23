#include<cstdio>
#include<cmath>


typedef long long LL; 

LL gcd(LL a,LL b){
	if(b==0) return a;
	else return gcd(b,a%b);
} 

struct Fraction{
	LL up,down;
};

Fraction reduction(Fraction result){
	if(result.down<0){
		result.up=-result.up;
		result.down=-result.down;
	}
	if(result.up==0){
		result.down=1;
	}else{
		LL d=gcd(abs(result.up),abs(result.down));
		result.up/=d;
		result.down/=d;
	}
	return result;
}

Fraction add(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down+f2.up*f1.down;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction minus(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down-f2.up*f1.down;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction multi(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction divide(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down;
	result.down=f1.down*f2.up;
	return reduction(result);
}

void showResult(Fraction r){
	r=reduction(r);
	if(r.down==1)printf("%lld",r.up);
	else if(abs(r.up)>r.down){
		printf("%d %d/%d",r.up/r.down,abs(r.up)%r.down,r.down);
	} else{
		printf("%d/%d",r.up,r.down);
	}
}

int main(){
	Fraction f1,f2;
	printf("请输入第一个分数的分子和分母：\n");
	scanf("%lld %lld",&f1.up,&f1.down);
	printf("请输入第二个分数的分子和分母：\n"); 
	scanf("%lld %lld",&f2.up,&f2.down);
 	printf("请问做加法、减法、乘法还是除法？请分别用+-*/表示：\n"); 
	char a;
	a=getchar();
//	a=getchar();
	scanf("%c",&a);
	Fraction r;
	if(a=='+') r=add(f1,f2);
	else if(a=='-') r=minus(f1,f2);
	else if(a=='*') r=multi(f1,f2);
	else if(a=='/') r=divide(f1,f2);
	else printf("出错了\n");
	printf("结果是：\n");
	showResult(r);
	return 0;
}



