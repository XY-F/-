#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
int main(){
	srand((unsigned)time(NULL));
	for(int i=0;i<10;i++){
		printf("%d ",rand()%2);	//[0,1] 
	} 
	printf("\n");
	for(int i=0;i<10;i++){
		printf("%d ",rand()%5+3);	//[3,7]
	}
	printf("\n");
	for(int i=0;i<10;i++){	//[10000,60000]
		printf("%lf ",((1.0*rand())/RAND_MAX)*50000+10000);
	}
	return 0;
}
