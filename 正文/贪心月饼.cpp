#include<cstdio>
#include<algorithm>
using namespace std;
struct mooncake{
	double store;	//库存量 
	double sell;	//总售价 
	double price;	//单价 
}cake[1010];
bool cmp(mooncake a,mooncake b){
	return a.price>b.price;
}
int main(){
	int n;		//月饼种类 
	double D;	//市场需求量 
	scanf("%d%lf",&n,&D);	//lf双精度浮点型
	for(int i=0;i<n;i++){	//读入n种月饼的存量 
		scanf("%lf",&cake[i].store);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&cake[i].sell);	//读入n种月饼的总售价 
		cake[i].price=cake[i].sell/cake[i].store;	//计算单价	
	}
	sort(cake,cake+n,cmp);	//按单价从高到低排列
	//sort函数(起始地址，结束地址，排序方法)
	double ans=0;	//收益
	for(int i=0;i<n;i++){
		if(cake[i].store<=D){	//如果需求量高于月饼库存量
			D-=cake[i].store;	//第i种月饼全部卖出 
			ans+=cake[i].sell; 
		}else{	//如果月饼库存量高于需求量 
			ans+=cake[i].price*D;
			break;
		} 
	} 
	printf("%.2f\n",ans);
	return 0; 
}
