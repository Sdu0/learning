#include <stdio.h>

#define ERROR -1
#define OK 1

typedef int Status;

void swap(int list[], int i, int j){
	int temp;
	temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

int partition(int list[], int low, int high){
	int pointkey;
	pointkey = list[low]; // 

	while(low < high){
		while(low < high && list[high] >= pointkey){
			high--;
		}
		swap(list, low, high);
		while(low < high && list[low] <= pointkey){
			low++;
		}
		swap(list, low, high);
	}
	
	return low;
}

//优化1：基准点（三数取中法）
int partition_2(int list[], int low, int high){
	int pointkey, mid;
	mid = low + (high - low)/2;
	if(list[low] > list[high]) swap(list, low, high);
	if(list[mid] > list[high]) swap(list, mid, high);
	if(list[mid] > list[low]) swap(list, mid, low);
	
	pointkey = list[low];
	while(low < high){
		while(low < high && list[high] >= pointkey) high--;
		swap(list, low, high);

		while(low < high && list[low] <= pointkey) low++;
		swap(list, low, high);
	}

	return low;
}

//优化2：减少不必要的交换
int partition_3(int list[], int low, int high){
	int pointkey, mid;
	mid = low + (high-low)/2;
	if(list[low] > list[high]) swap(list, low, high);
	if(list[mid] > list[high]) swap(list, mid, high);
	if(list[mid] > list[low]) swap(list, mid, low);

	pointkey = list[low];
	while(low < high){
		while(low < high && list[high] >= pointkey) high--;
		list[low] = list[high];
		
		while(low < high && list[low] <= pointkey) low++;
		list[high] = list[low];
	}
	list[low] = pointkey;

	return low;
}

Status quick(int list[], int low, int high){
	if(low < high){
		int point;
		//point = partition(list, low, high);
		//point = partition_2(list, low, high);
		point = partition_3(list, low, high);

		//上述操作把list以point为中心分为两块
		//对比 point 小的一部分数据进行排序
		quick(list, low, point-1);
		//对         大
		quick(list, point+1, high);
	}

	return OK;
}

void print(int list[], int len){
	printf("=========== LIST: ===========\n");	
	for(int i=0; i<len; i++){
		printf("%d  ", list[i]);
	}
	printf("\n\n");
}

int main(){
	int len = 10;
	int list[10] = {12, 2, 43, 4, 45, 23, 5, 21, 14, 15};	

	print(list, len);
	quick(list, 0, len-1);
	print(list, len);

	return 0;
}
