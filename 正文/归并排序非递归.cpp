void mergeSort(int A[]){
	//step为组内元素个数，step/2为左子区间元素个数，注意等号可以不去
	for(int step=2;step/2<=n;step*=2){
		//每step个元素一组，组内前step/2和后step/2个元素进行合并
		for(int i=1;i<=n;i+=step){
			//对每一组，一开始一组为2个，之后组的长度*2，2,4,8,16...
			int mid=i+step/2-1; //i是每个组的起点，求每个组的mid 
			//左子区间元素个数为step/2
			if(mid+1<=n){
				//右子区间存在元素则合并
				//左子区间为[i,mid],右子区间为[mid+1,min(i+step-1,n)]
				merge(A,i,mid,mid+1,min(i+step-1,n)); 
			}
		} 
	} 
}
