void mergeSort(int A[]){
	//stepΪ����Ԫ�ظ�����step/2Ϊ��������Ԫ�ظ�����ע��Ⱥſ��Բ�ȥ
	for(int step=2;step/2<=n;step*=2){
		//ÿstep��Ԫ��һ�飬����ǰstep/2�ͺ�step/2��Ԫ�ؽ��кϲ�
		for(int i=1;i<=n;i+=step){
			//��ÿһ�飬һ��ʼһ��Ϊ2����֮����ĳ���*2��2,4,8,16...
			int mid=i+step/2-1; //i��ÿ�������㣬��ÿ�����mid 
			//��������Ԫ�ظ���Ϊstep/2
			if(mid+1<=n){
				//�����������Ԫ����ϲ�
				//��������Ϊ[i,mid],��������Ϊ[mid+1,min(i+step-1,n)]
				merge(A,i,mid,mid+1,min(i+step-1,n)); 
			}
		} 
	} 
}
