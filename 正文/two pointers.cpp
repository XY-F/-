#include<cstdio>
const int maxn=50;
int main(){
	int n,m,a[maxn];
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int i=0,j=n-1;
	while(i<j){
		if(a[i]+a[j]==m){
			printf("%d %d\n",a[i],a[j]);
			i++;
			j--;
		}else if(a[i]+a[j]<m){
			i++;
		}else{
			j--;
		}
	}
	return 0;
} 

