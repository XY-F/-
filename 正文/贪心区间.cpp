#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Inteval{
	int x,y;	//���������Ҷ˵� 
}I[maxn];
bool cmp(Inteval a,Inteval b){
	if(a.x!=b.x) return a.x>b.x;	//�����˵㲻ͬ������˵�Ӵ�С����,����������Զ�� 
	else return a.y<b.y;	//����˵���ͬ�����Ҷ˵��С�������У������䳤��С������	
} 
int main(){
	int n;
	while(scanf("%d",&n),n!=0){	//��ȡn������
		for(int i=0;i<n;i++){
			scanf("%d%d",&I[i].x,&I[i].y);	//��������˵� 
		} 
		sort(I,I+n,cmp);	//���������򣬾���������Զ�ģ��������䳤����С������ 
		//ans��¼���ཻ���������lastX��¼��һ����ѡ���������˵�
		int ans=1,lastX=I[0].x;
		for(int i=1;i<n;i++){
			if(I[i].y<=lastX){	//����������Ҷ˵���lastX��� 
				lastX=I[i].x;	//��I[i]��Ϊ��ѡ�е����� 
				ans++; //���ཻ�������+1 
			}
		} 
		printf("%d\n",ans); 
	} 
	return 0;
}
