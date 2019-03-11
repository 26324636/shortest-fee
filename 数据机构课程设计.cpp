#include<iostream>
#include<string>
#include<windows.h>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define digit 9999999  
using namespace std;
void displayIndex(); //��ʾ̨
void changtongShow(); //��ͨ������������
void inforSolve(); //��ͨ����������
int prime(int n);  //prime�㷨

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
		cout << "������ѡ�";
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
			cout <<" ȷ���˳�ϵͳ��(y/n)";
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

//��ʾ̨
void displayIndex()
{
	printf("�X�T�T�T�T�T���ݽṹ�γ����  ��ͨ���̨T�T�T�T�T�[\n");
	printf("�U             1.��������;                      �U\n");
	printf("�U             2.����ֲ���С��������;          �U\n");	
	printf("�U             3.����;                          �U\n");
	printf("�U             4.�˳�����;                      �U\n");
	printf("�U                                              �U\n");
	printf("�U                     Made By �Ӽ��� QQ26324636�U\n");
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}

//��ͨ������������
void changtongShow()
{
	printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T��ͨ����  ���������T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("    ĳ���������Գ���ͨ״���ĵ��飬�õ����г���֮����ٵ�·��ͳ������,\n  �������ͨ���̡���Ŀ�꣺ʹ���������κ���������֮�䶼����ʵ�ֿ��ٽ�ͨ��\n  ��һ����ֱ�ӵĿ��ٵ�·������ֻҪ������ͨ������·�ɴＴ�ɣ����ֵõ���\n  ���·ͳ�Ʊ������г���������������޽�����·�ķ��ã��Լ��õ�·�Ƿ���\n  ���޽���״̬�������ȫ������ͨ��Ҫ����ͳɱ���\n    ����˵������1�и�����ׯ��Ŀ�������N��N-1��/2�ж�Ӧ��ׯ���·�ĳɱ���\n  �޽�״̬���ֱ���������ׯ�ı�š�����ׯ��·���޽��ɱ��Լ��޽���״̬��1��\n  �ѽ���0��δ��������prime�㷨��kruskal�㷨����С������������������õ���\n  ���ۡ�\n");
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}

//prime�㷨
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

//������
void inforSolve()
{
	string con;
	while(1)
	{
		memset(a,digit,sizeof(a));
		memset(v,0,sizeof(v));
		memset(p,0,sizeof(p));
		int n,num,i,j,flag,d,ans;
		cout << "�������ׯ����Ŀ��" ;
		cin >> n;
		n = n * (n - 1) / 2;
		num = n;
		cout << "������" << n <<"��������������ׯ�ı�š�����ׯ��·���޽��ɱ��Լ��޽���״̬:"  << endl;
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
		cout << "�õ�����ͨ��Ҫ����ͳɱ��ǣ�" << ans << endl;
		cout << "�Ƿ������������������(y/n):";
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