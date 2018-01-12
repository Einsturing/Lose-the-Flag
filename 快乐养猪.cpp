#include <iostream>
#include <cstdlib> 
using namespace std;
const int WHITEPIG = 0;//�װ׵�С����Ϊ0��
const int BLACKPIG = 1;//�ںڵ�С����Ϊ1��
//¥��������������
int type_up[50][5];
double speed_up[50][5];
double weight_up[50][5];
int days_up[50][5];
//¥�±�����������
int type_down[50][4];
double speed_down[50][4];
double weight_down[50][4];
int days_down[50][4];
//��¥�ϼ�С���ӡ�
void add_upPIG()
{
	for(int i=0;i<=49;i++)
		for (int j = 0;j <= 4;j++)
		{
			type_up[i][j] = rand() % 2;
			weight_up[i][j] = 20 + rand() % 31;
		}
}
//��¥�¼�С���ӡ�
void add_downPIG()
{
	for(int i=0;i<=49;i++)
		for (int j = 0;j <= 3;j++)
		{
			type_down[i][j] = rand() % 2;
			weight_up[i][j] = 20 + rand() % 31;
		}
}
//¥�ϵ�С������ô���أ�
void setup_speed()
{
	for(int i=0;i<=49;i++)
		for (int j = 0;j <= 4;j++)
		{
			speed_up[i][j] = 0.2 + rand() % 2;
		}
}
//¥�µ�С������ô���أ�
void setdown_speed()
{
	for(int i=0;i<=49;i++)
		for (int j = 0;j <= 3;j++)
		{
			speed_up[i][j] = rand() % 2;
		}
}
//¥��С����һ���쳤��QWQ��
void bigger_up()
{
	for(int i=0;i<=49;i++)
		for (int j = 0;j <= 4;j++)
		{
			weight_up[i][j] += speed_up[i][j];
			days_up[i][j]++;
		}
}
//¥��С����һ���쳤��QWQ��
void bigger_down()
{
	for(int i=0;i<=49;i++)
		for (int j = 0;j <= 3;j++)
		{
			weight_down[i][j] += speed_down[i][j];
			days_down[i][j]++;
		}
}
//����¥��С���ӡ�
int sell_up()
{
	int sum_up;
	for (int i = 0;i <= 49;i++)
	{
		for (int j = 0;j <= 4;j++)
		{
			if (weight_up[i][j] > 75 || days_up[i][j] > 182)
			{
				if (type_up[i][j] == 0)
					sum_up += 7 * (weight_up[i][j] / 2);
				else
					sum_up += 14 * (weight_up[i][j] / 2);
				days_up[i][j] = 0;
				weight_up[i][j] = 0;
				speed_up[i][j] = 0;
			}
		}
	}
	return sum_up;
}
//����¥��С���ӡ�
int sell_down()
{
	int sum_down;
	for (int i = 0;i <= 49;i++)
	{
		for (int j = 0;j <= 3;j++)
		{
			if (weight_down[i][j] > 75 || days_down[i][j] > 182)
			{
				if (type_up[i][j] == 0)
					sum_down += 7 * (weight_down[i][j] / 2);
				else
					sum_down += 14 * (weight_down[i][j] / 2);
				days_down[i][j] = 0;
				weight_down[i][j] = 0;
				speed_down[i][j] = 0;
			}
		}
	}
	return sum_down;
}
int main()
{
	unsigned seed;
	cin>>seed;
	srand(seed); 
	cout << "Fed Pig Simulator!" << endl;//��ʼ��Ϸ��
	int price;
	add_upPIG();
	add_downPIG();
	setup_speed();
	setdown_speed();
	for (int i = 1;i <= 365;i++)
	{
		cout << "��" << i << "���ȥ��" << endl;
		bigger_up();
		bigger_down();
		if (i == 90 || i == 180 || i == 270 || i == 365)
		{
			price = sell_up() + sell_down();
			cout << "�������룺" << price << endl;
			add_upPIG();
			add_downPIG();
			setup_speed();
			setdown_speed();
		}
	}
	system("pause");
}
