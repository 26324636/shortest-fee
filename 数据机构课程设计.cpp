#include<iostream>
#include<string>
#include<windows.h>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define digit 9999999  
using namespace std;
void displayIndex(); //显示台
void changtongShow(); //畅通工程问题描述
void inforSolve(); //畅通工程问题解决
int prime(int n);  //prime算法

int v[105];
int a[105][105];
int p[105];
int main()
{
	int fun;
	char returnFlag[5];
	while(1)
	{
		displayIndex();
		cout << "请输入选项：";
		cin >> fun;
		switch(fun)
		{
		case 1 :
			changtongShow();
			break;
		case 2:
			inforSolve();
			break;
			
		case 3:
			system("cls");
			break;
		case 4:  
			cout <<" 确认退出系统？(y/n)";
			cin >> returnFlag;
			if(returnFlag[0] == 'y' || returnFlag[0] == 'Y')
			{
				exit(0);  
			}
			else
			{
				continue;
			}			
			break; 			
		}
	}	
	return 0;
}

//显示台
void displayIndex()
{
	printf("╔═════数据结构课程设计  畅通工程═════╗\n");
	printf("║             1.问题描述;                      ║\n");
	printf("║             2.解决局部最小花费问题;          ║\n");	
	printf("║             3.清屏;                          ║\n");
	printf("║             4.退出程序;                      ║\n");
	printf("║                                              ║\n");
	printf("║                     Made By 钟佳闱 QQ26324636║\n");
	printf("╚═══════════════════════╝\n");
}

//畅通工程问题描述
void changtongShow()
{
	printf("╔═════════════畅通工程  问题描述═════════════╗\n");
	printf("    某地区经过对城镇交通状况的调查，得到现有城镇之间快速道路的统计数据,\n  提出“畅通工程”的目标：使整个地区任何两个城镇之间都可以实现快速交通（\n  不一定有直接的快速道路相连，只要互相间接通过快速路可达即可）。现得到城\n  镇道路统计表，表中列出了任意两城镇间修建快速路的费用，以及该道路是否已\n  经修建的状态。计算出全地区畅通需要的最低成本。\n    输入说明：第1行给出村庄数目；随后是N（N-1）/2行对应村庄间道路的成本及\n  修建状态：分别是两个村庄的编号、两村庄道路的修建成本以及修建的状态（1：\n  已建，0：未建），用prime算法或kruskal算法求最小代价生成树，并计算得到的\n  代价。\n");
	printf("╚═══════════════════════════════════╝\n");
}

//prime算法
int prime(int n)
{
	int min,sum,cnt,i,j,k;
    sum = cnt = i = j = k = 0;
	for(i = 0;i < n;i ++)
	{
		min = digit;
		for(j = 2;j <= n;j ++)
		{
			if((v[j] != 1) && p[j] < min)
			{   
				min = p[j];
				cnt = j;
			}
		}
		if(min != digit) 
		{
			sum += min;
			v[cnt] = 1;
			for(k = 2;k <= n;k ++)
			{
				if((v[k] != 1) && (p[k] > a[cnt][k]))
				{
					p[k]=a[cnt][k];
				}				
			}
		}	
	}	
	return sum;	
}

//问题解决
void inforSolve()
{
	string con;
	while(1)
	{
		memset(a,digit,sizeof(a));
		memset(v,0,sizeof(v));
		memset(p,0,sizeof(p));
		int n,num,i,j,flag,d,ans;
		cout << "请输入村庄的数目：" ;
		cin >> n;
		n = n * (n - 1) / 2;
		num = n;
		cout << "接下来" << n <<"行请输入两个村庄的编号、两村庄道路的修建成本以及修建的状态:"  << endl;
		while(n --)
		{
			cin >> i >> j >> d >> flag;
			a[i][j] = d;
			if(flag == 0)
			{
				a[j][i] = a[i][j];
			}
			else
			{
				
				a[i][j] = 0;
				a[j][i] = 0;
				
			}
		}
		for(i = 1 ; i <= num ; i ++)
		{
			p[i] = a[1][i];
		}
		v[1] = 1;
		ans = 0;
		ans = prime(num);
		cout << "该地区畅通需要的最低成本是：" << ans << endl;
		cout << "是否继续计算其他地区？(y/n):";
		cin >> con;
		if(con == "y" || con == "Y")
		{
			continue;
		}
		else
		{
			break;
		}
	}
}