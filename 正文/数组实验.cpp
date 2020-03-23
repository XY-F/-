#include<stdio.h>
int a[1000000];
int main(){
	for(int i=0;i<1000000;i++){
		a[i]=i;
	}
	for(int i=0;i<1000000;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
