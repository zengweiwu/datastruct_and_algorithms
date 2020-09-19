# include <stdio.h>

int FindPos(int * a, int low, int high);
void QuickSort(int * a, int low, int high);

int main(void)
{
	int a[7] = {5, 2, 4, 6, 8, 9,7};
	int i;

	QuickSort(a, 0, 6); //�ڶ���������ʾ��һ��Ԫ�ص��±�  ������������ʾ���һ��Ԫ�ص��±�
	
	for (i=0; i<7; ++i)
		printf("%d  ", a[i]);
	printf("\n");

	return 0;
}

void QuickSort(int * a, int low, int high)
{
	int pos;

	if (low < high)
	{
		pos = FindPos(a, low, high);
		QuickSort(a, low, pos-1);
		QuickSort(a, pos+1, high);
	}	
}

int FindPos(int * a, int low, int high)
{
	int val = a[low];

	while (low < high)
	{
		while (low<high  && a[high]>=val)
			--high;
		a[low] = a[high];

		while (low<high && a[low]<=val)
			++low;
		a[high] = a[low];
	}//��ֹwhileѭ��֮��low��highһ������ȵ�

	a[low] = val; 

	return high; //high���Ը�Ϊlow, �����ܸ�Ϊval Ҳ���ܸ�Ϊa[low]  Ҳ���ܸ�Ϊa[high]
}
