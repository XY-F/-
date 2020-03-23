int hashFunc(char S[],int len){
	int id=0;
	for(int i=0;i<len;i++){
		if(S[i]>='A'&&S[i]<='Z'){
			id=id*52+(S[i]-'A');
		}else if(S[i]>='a'&&S[i]<='z'){
			id=id*52+(S[i]-'a')+26;
		}
	}
	id=id*10+(S[len-1]-'0');
	return id;
}
