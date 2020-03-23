#include<cstdio>

typedef long long LL;
//���������
//��򵥵��ǲ��Ƽ���д�� 
LL C1(LL n,LL m){
	LL ans=1;
	for(LL i=1;i<=n;i++){
		ans*i;
	}
	for(LL i=1;i<=m;i++){
		ans/=i;
	}
	for(LL i=1;i<=n-m;i++){
		ans/=i;
	}
	return ans;
}

//ͨ�����ƹ�ʽ����
//option 1 
LL C2(LL n,LL m){
	if(m==0||m==n) return 1;
	return C2(n-1,m)+C2(n-1,m-1);
}

//option 2



int C3(int n,int m){
	int res1[60][60]={0};
	for(int i=0;i<=n;i++){
		res1[i][0]=1;
		res1[i][i]=1;	//��ʼ���߽� 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			res1[i][j]=res1[i-1][j]+res1[i-1][j-1];	//���Ƽ��� C(i,j) 
			res1[i][i-j]=res1[i][j];	//C(i,i-j)=C(i,j)
		}
	} 
	return res1[n][m];
}

//����ʽ����
LL C4(LL n,LL m){
	LL ans=1;
	for(LL i=1;i<=m;i++){
		ans=ans*(n-m+i)/i;	//ע��һ��Ҫ�ȳ��ٳ� 
	}
	return ans;
} 

//����C(n,m)%p
//�ݹ�� 
int res[1010][1010]={0};
int Cp(int n,int m,int p){

	if(m==0||m==n) return 1%p;	//C(n,0)=C(n,n)=1 
	if(res[n][m]!=0) return res[n][m];	//�Ѿ���ֵ
	return res[n][m]=(C2(n-1,m)+C2(n-1,m-1))%p; 

} 
 
//���ư� 

int Cp2(int n,int m,int p){
	int res2[100][100]={0};
	for(int i=0;i<=n;i++){
		res2[i][0]=1%p;
		res2[i][i]=1%p;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			res2[i][j]=(res2[i-1][j]+res2[i-1][j-1])%p;
			res2[i][i-j]=res2[i][j];
		}
	}
	return res2[n][m];
}

int main(){
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	printf("C(%d,%d)=%d\n",n,m,C2(n,m));
	printf("C(%d,%d)%%%d=%d\n",n,m,p,Cp(n,m,p));
	printf("C(%d,%d)=%d\n",n,m,C3(n,m));
	printf("C(%d,%d)%%%d=%d\n",n,m,p,Cp2(n,m,p));
	return 0;
} 
 
