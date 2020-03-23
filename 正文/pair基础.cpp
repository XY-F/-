#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	pair<string,int>p;
	p.first= "haha";
	p.second=5;
	cout<<p.first<<" "<<p.second<<endl;
	p=make_pair("xixi",55);
	cout<<p.first<<" "<<p.second<<endl;
	p=pair<string,int>("heihei",555);
	cout<<p.first<<" "<<p.second<<endl;
	pair<int,int> p1(10,6);
	pair<int,int> p2(11,15);
	pair<int,int> p3(10,5);
	if(p1<p3) printf("p1<p3\n");
	if(p1>p3) printf("p1>p3\n");
	if(p1<p2) printf("p1<p2\n"); 
	map<string,int>mp;
	mp.insert(make_pair("heihei",5));
	mp.insert(pair<string,int>("haha",10));
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
