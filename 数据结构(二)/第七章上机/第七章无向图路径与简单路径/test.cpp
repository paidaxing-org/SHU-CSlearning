#include "Assistance.h"
#include "AdjMatrixUndirGraph.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "测试是否两点可达" << endl;
	int t;
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	AdjMatrixUndirGraph<int> g1(a,10);
	g1.InsertArc(0, 2);
	g1.InsertArc(2, 1);
	g1.InsertArc(2, 4);
	g1.InsertArc(1, 6);
	g1.InsertArc(6, 2);
	g1.InsertArc(4, 5);
	cout << "输入测试组数：" << endl;
	cin >> t;
	while (t--)
	{
		int a, b;
		cout << "请输入想要判断的起点v1与终点v2:" << endl;
		cin >> a >> b;
		int Posa, Posb;
		Posa = g1.GetOrder(a);
		Posb = g1.GetOrder(b);
		g1.Display();
		system("pause");
		system("cls");
		if (g1.JudgePath(Posa, Posb) == 1)
		{
			cout << "可以从" << a << "顶点到" << b << "顶点" << endl;
			g1.GetSimplePath(Posa, Posb, 0);
		}
		else
			cout << "不可以从" << a << "顶点到" << b << "顶点" << endl;
	}
	system("cls");
	cout << "测试是否两点可达" << endl;*/

	
	
}