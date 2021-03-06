#include <stdio.h>

/*
	输入某年某月某日，判断这一天是这一年的第几天？
*/

void method1(){
	int year, month, day, days;

	printf("请输入年：\n");
	scanf("%d", &year);

	printf("请输入月：\n");
	scanf("%d", &month);


	printf("请输入日：\n");
	scanf("%d", &day);

	days = (month - 1) * 30 + day;

	switch(month){
		case 1: 
			days += 1;
			break;
		case 2:
			days = days + 1 - 2; 
			break;
		case 3:
			days = days + 1 - 2 + 1;
			break;
		case 4:
			days = days + 1 - 2 + 1 + 1;
			break;
		case 5:
			days = days + 1 - 2 + 1 + 1 + 0;
			break;
		case 6:
			days = days + 1 - 2 + 1 + 1 + 0 + 0;
			break;
		case 7:
			days = days + 1 - 2 + 1 + 1 + 0 + 0 + 1;
			break;
		case 8:
			days = days + 1 - 2 + 1 + 1 + 0 + 0 + 1 + 1;
			break;
		case 9:
			days = days + 1 - 2 + 1 + 1 + 0 + 0 + 1 + 1 + 0;
			break;
		case 10:
			days = days + 1 - 2 + 1 + 1 + 0 + 0 + 1 + 1 + 0 + 1;
			break;
		case 11:
			days = days + 1 - 2 + 1 + 1 + 0 + 0 + 1 + 1 + 0 + 1 + 0;
			break;
		case 12:
			days = days + 1 - 2 + 1 + 1 + 0 + 0 + 1 + 1 + 0 + 1 + 0 + 1;
			break;
	}

	if(month > 2){
		if(year % 400 == 0){
			days += 1;
		}else if(year % 4 == 0 && year % 100 != 0){
			days += 1;
		}
	}

	printf("%d年%d月%d日是这一年的第 %d 天!\n", year, month, day, days);
}

void method2(){
	int year, month, day, days;
	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	printf("请输入年：\n");
	scanf("%d", &year);

	printf("请输入月：\n");
	scanf("%d", &month);


	printf("请输入日：\n");
	scanf("%d", &day);
	
	days = day;
	for(int i = 0 ; i < month - 1; i ++){
		days += months[i];
	}

	if(month > 2){
		if(year % 400 == 0){
			days += 1;
		}else if(year % 4 == 0 && year % 100 != 0){
			days += 1;
		}
	}

	printf("%d年%d月%d日是这一年的第 %d 天!\n", year, month, day, days);
}

int main(){
	// method1();	

	method2();

	return 0;
}