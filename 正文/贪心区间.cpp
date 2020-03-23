#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Inteval{
	int x,y;	//开区间左右端点 
}I[maxn];
bool cmp(Inteval a,Inteval b){
	if(a.x!=b.x) return a.x>b.x;	//如果左端点不同，按左端点从大到小排列,即数轴上最远的 
	else return a.y<b.y;	//若左端点相同，按右端点从小到大排列，即区间长度小的在先	
} 
int main(){
	int n;
	while(scanf("%d",&n),n!=0){	//读取n个区间
		for(int i=0;i<n;i++){
			scanf("%d%d",&I[i].x,&I[i].y);	//读入区间端点 
		} 
		sort(I,I+n,cmp);	//把区间排序，距离数轴最远的，或者区间长度最小的在先 
		//ans记录不相交区间个数，lastX记录上一个被选中区间的左端点
		int ans=1,lastX=I[0].x;
		for(int i=1;i<n;i++){
			if(I[i].y<=lastX){	//如果该区间右端点在lastX左边 
				lastX=I[i].x;	//以I[i]作为新选中的区间 
				ans++; //不相交区间个数+1 
			}
		} 
		printf("%d\n",ans); 
	} 
	return 0;
}
