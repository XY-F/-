// scanf %c输入单个字符，可以识别空格跟换行并将其输出
// scanf %s输入字符串，通过空格或换行来识别一个字符串的结束
#include<stdio.h> 
int main(){
	char str[10];
	scanf("%s",str);	//不需要& 
	printf("%s",str);
	return 0;
}
