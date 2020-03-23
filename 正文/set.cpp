#include<cstdio>
#include<set>
using namespace std;

int main(){
	set<int> st;
	st.insert(3);
	st.insert(5);
	st.insert(2);
	st.insert(3);
	for(set<int>::iterator it=st.begin();it!=st.end();it++){
		printf("%d ",*it);
	}
	printf("\n");
	set<int>::iterator it=st.find(2);
	printf("%d\n",*it); 
	printf("%d\n",*(st.find(2)));
	st.insert(100);
	st.insert(200);
	st.insert(100);
	st.insert(300);
	for(set<int>::iterator it=st.begin();it!=st.end();it++){
		printf("%d ",*it);
	}
	printf("\n");
	st.erase(st.find(100));
	st.erase(st.find(200));
	for(set<int>::iterator it=st.begin();it!=st.end();it++){
		printf("%d ",*it);
	}
	printf("\n");
	st.insert(100);
	st.insert(200);
	for(set<int>::iterator it=st.begin();it!=st.end();it++){
		printf("%d ",*it);
	}
	printf("\n");
	st.erase(100);
	for(set<int>::iterator it=st.begin();it!=st.end();it++){
		printf("%d ",*it);
	}
	printf("\n");
	st.clear();
	st.insert(10);
	st.insert(20);
	st.insert(30);
	st.insert(40);
	it=st.find(30);
	st.erase(it,st.end());
	for(set<int>::iterator it=st.begin();it!=st.end();it++){
		printf("%d ",*it);
	}
	return 0;
}

