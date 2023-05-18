#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>	//rand函数引
#include <time.h>	//time函数引

//2023.05.18
//p37 练习 猜数字游戏 ===================================================================
//1、自动产生一个1-100之间的随机数
//2、猜数字
//	a.猜对-恭喜游戏结束
//	b.猜错-猜大了还是猜小了-继续猜，直到猜对
//3、游戏一直玩，除非退出游戏

// 菜单函数 *****************************************************************************
void menu()
{
	printf("**********************\n");
	printf("******* 1.play *******\n");
	printf("******* 0.exit *******\n");
	printf("**********************\n");
}
//游戏实现 *******************************************************************************
void game()
{
	// 1.生成 1-100 随机数rand(需要包含头文件stdlib.h)*****************************
							//直接调用rand函数，会返回一个0-32767之间的数字，每次循环中都相同
							//调用rand之前，需要先调用srand函数设置rand起点
							//但是直接设置srand(确定的一个数)，后面rand一直生成同一个随机数
							//采用 “时间戳” 作为srand参数 --- time()函数返回时间戳
							//srand放到game函数里每次都重新被调用，会造成生成的数不够随机，所以放到main函数里，在循环之外只调用一次

	int ret = rand()%100 + 1;// %100的余数是0-99，然后加1，范围就是1-100
	//printf("%d\n", ret);
	
	// 2.猜数字 **************************************************************************
	int guess = 0;
	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了\n");
		}
		else if (guess > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}

// main *************************************************************************************
int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));//srand参数是unsigned int类型，把time进行强制类型转换
									//time函数需要引头文件time.h

	do
	{
		menu();//打印菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("猜数字\n");
			game();//游戏进行
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;						//break跳出的是switch语句
		}
	} while (input);//input = 0,直接退出不继续，其他值都继续
	return 0;
}