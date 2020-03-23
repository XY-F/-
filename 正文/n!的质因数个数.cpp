//计算n!中有多少个质因子p
//非递归版 
int cal(int n,int p){
	int ans=0;
	while(n){
		ans+=n/p;
		n/=p;
	}
	return ans;
} 
//递归版
int cal(int n,int p){
	if(n<p) return 0;
	return n/p+cal(n/p,p);
} 
