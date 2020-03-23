#include<cstdio>
#include<algorithm>
using namespace std;
	bool cmp(char a,char b){
		return a>b;
	}
int main(){
	int a[6]={9,4,2,5,6,-1};
	sort(a,a+4);
	for(int i=0;i<6;i++) {
		printf("%d ",a[i]);
	}
	printf("\n"); 
	sort(a,a+6);
	for(int i=0;i<6;i++){
		printf("%d ",a[i]);
	}
	printf("\n"); 
	double b[]={1.4,-2.1,9};
	sort(b,b+3);
	for(int i=0;i<3;i++){
		printf("%.1f ",b[i]);
	}
	printf("\n");
	char c[]={'T','W','A','K'};
	sort(c,c+4,cmp);
	for(int i=0;i<4;i++){
		printf("%c ",c[i]);
	}
	return 0;
	
}
