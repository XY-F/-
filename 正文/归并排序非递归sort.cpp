void mergeSort(int A[]){
	//stepΪ����Ԫ�ظ�����step/2Ϊ��������Ԫ�ظ�����ע��Ⱥſɲ�ȡ
	for(int step=2;step/2<=m;step*=2){
		//ÿstep��Ԫ��һ�飬����[i,min(i+step,n+1)]��������
		for(int i=1;i<=n;i+=step){
			sort(A+i,A+min(i+step,n+1));
		} 
//		�˴�����������������ĳһ�˽���������
	} 
	
} 
