//���"Ѱ���������е�һ������ĳ������Ԫ�ص�λ��"����Ĺ̶�ģ��
//��������Ϊ����ұյ�[left,right]����ֵ�����ܸ��ǽ�����п���ȡֵ
int solve(int left,int right){
	int mid;	//midΪleft��right���е�
	while(left<right){	//��[left,right]��˵��left==right��ζ���ҵ�Ψһλ��
		mid=left+(right-left)/2;
		if(��������){	//������������һ������������Ԫ�ص�λ��<=mid
			right=mid;	//����������[left,mid]���� 
		}else{
			left=mid+1;	//����������[mid+1,right]���� 
		}
	} 
	return left; 
} 

//���"Ѱ���������е�һ������ĳ������Ԫ�ص�λ��"����Ĺ̶�ģ��
//��������Ϊ���ұյ�(left,right]
//��ֵ�����ܸ��ǽ�����п���ȡֵ������left����СֵС1
int solve(int left,int right){
	int mid;	//midΪleft��right���е�
	while(left+1<right)	//��(left,right],left+1==right��ζ��Ψһλ��
	if(��������){	//�������������һ������������Ԫ�ص�λ��<=mid
	}else{	//���������������һ������������Ԫ�ص�λ��>mid
		left=mid; 
	} 
	return right;
} 
