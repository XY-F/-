#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main(){
	int a[10]={10,11,12,13,14,15};
	reverse(a,a+4);
	for(int i=0;i<6;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	string str="abcdefghi";
	reverse(str.begin()+2,str.begin()+6);
	cout<<str;
	return 0;
}
