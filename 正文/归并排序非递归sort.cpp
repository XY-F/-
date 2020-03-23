void mergeSort(int A[]){
	//step为组内元素个数，step/2为左子区间元素个数，注意等号可不取
	for(int step=2;step/2<=m;step*=2){
		//每step个元素一组，组内[i,min(i+step,n+1)]进行排序
		for(int i=1;i<=n;i+=step){
			sort(A+i,A+min(i+step,n+1));
		} 
//		此处可以输出冰柜排序的某一趟结束的序列
	} 
	
} 
