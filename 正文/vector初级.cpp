#include<cstdio> 
#include<vector>
using namespace std;

int main(){
	vector<int> vi;
	for(int i=1;i<=5;i++){
		vi.push_back(i);
	}
	printf("\n");
	vector<int>::iterator it=vi.begin();
	for(int i=0;i<5;i++){
		printf("%d ",*(it+i));
	}
	printf("\n");
	//vetor的迭代器不支持it<vi.end()写法，因此
	//循环条件只能用it!=vi.end()
	for(vector<int>::iterator it=vi.begin();it!=vi.end();it++) {
		printf("%d ",*it);
	}
	printf("\n");
	for(int i=0;i<vi.size();i++){
		printf("%d ",vi[i]);
	}
	printf("\n");
	vi.pop_back();
	for(int i=0;i<vi.size();i++){
		printf("%d ",vi[i]);
	}
	printf("\n");
	vi.clear();
	printf("%d\n",vi.size());
	for(int i=1;i<=5;i++){
		vi.push_back(i);
	}
	vi.insert(vi.begin()+2,-1);
	for(int i=0;i<vi.size();i++){
		printf("%d ",vi[i]);
	}
	printf("\n");
	vi.clear();
	for(int i=5;i<=9;i++){
		vi.push_back(i);
	}
	vi.erase(vi.begin()+1,vi.begin()+4);
	for(int i=0;i<vi.size();i++){
		printf("%d ",vi[i]);
	}
	printf("\n");
	
	return 0;
}
