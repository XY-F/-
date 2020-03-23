#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream> 
using namespace std;
bool cmp(int a,int b){
	return a>b;
}

bool cmp2(string str1,string str2){
	return str1.length()<str2.length();
}
int main(){
	vector<int> vi;
	vi.push_back(3);
	vi.push_back(1);
	vi.push_back(2);
	sort(vi.begin(),vi.end(),cmp);
	for(int i=0;i<3;i++){
		printf("%d ",vi[i]);
	}
	printf("\n");
	string str[3]={"bbbb","cc","aaa"};
	sort(str,str+3);
	for(int i=0;i<3;i++){
		cout<<str[i]<<endl;
	}
	printf("\n");
	sort(str,str+3,cmp2);
	for(int i=0;i<3;i++){
		cout<<str[i]<<endl;
	}
	return 0;
}
