#include<cstdio>
#include<queue>
#include<string> 
#include<iostream>
using namespace std;

struct fruit{
	string name;
	int price;
//	friend bool operator < (fruit f1,fruit f2){
//		return f1.price>f2.price;
//	}
}f1,f2,f3; 

struct cmp{
	bool operator ()(const fruit &f1,const fruit &f2){
		return f1.price>f2.price;
	}
};


int main(){
	priority_queue<fruit,vector<fruit>,cmp>q;
	f1.name="����";
	f1.price=3;
	f2.name="����";
	f2.price=4;
	f3.name="ƻ��";
	f3.price=1;
	q.push(f1);
	q.push(f2);
	q.push(f3);
	cout<<q.top().name<<" "<<q.top().price<<endl;
	return 0; 
}

