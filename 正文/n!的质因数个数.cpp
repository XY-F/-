//����n!���ж��ٸ�������p
//�ǵݹ�� 
int cal(int n,int p){
	int ans=0;
	while(n){
		ans+=n/p;
		n/=p;
	}
	return ans;
} 
//�ݹ��
int cal(int n,int p){
	if(n<p) return 0;
	return n/p+cal(n/p,p);
} 
