#include "count system.h"
string name;

void menu0()

{
	string x;
	cout << "\t\t\t-----------------------------------------\n" << endl;
	cout << "\t\t\t\t名称：小学生算数自测系统\n" << endl;
	cout << "\t\t\t\t工具：Visual Studio 2019\n" << endl;
	cout << "\t\t\t\t作者：张怀民\n" << endl;
	cout << "\t\t\t-----------------------------------------\n" << endl;
	cout << "\t\t\t\t请输入你的名字：";
	cin >> name;
	cout << "\t\t\t\t你的名字是"<<name<<",你想继续吗？\n" << endl;
	cout << "\t\t\t\t如果你想继续，输入Y,想退出就输入N:\t" ;
	cin >> x;
	if (x=="Y"||x=="y")
	{
		system("cls");
		menu1();
	}
	else if(x=="N"||x=="n")
	{
		exit(0);
	}

}
void menu1()
{
	cout <<"\t\t\t\t前言\n" << endl;
	cout << name<<"同学，你好，欢迎使用【小学生算数自测系统】，本程序以全菜单形式实现了以下功能；\n" << endl;
	cout << "*****************1.单项加法练习*******************" << endl;
	cout << "*****************2.单项减法练习*******************" << endl;
	cout << "*****************3.加减混合练习*******************" << endl;
	cout << "*****************4.退出系统***********************" << endl;
	cout << "请输入你的选择：";
}
void menu2()
{
	cout << "*********************选择菜单*********************" << endl;
	cout << "*****************1.单项加法练习*******************" << endl;
	cout << "*****************2.单项减法练习*******************" << endl;
	cout << "*****************3.加减混合练习*******************" << endl;
	cout << "*****************4.退出系统***********************" << endl;
	cout << "请输入你的选择：";
}
void sound1()
{
	PlaySound(LPWSTR(IDR_WAVE3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	//PlaySound(TEXT(IDR_WAVE1), NULL, SND_FILENAME | SND_ASYNC );
}
void sound2()
{
	PlaySound(LPWSTR(IDR_WAVE2), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	//PlaySound(TEXT("D:\\2.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void add()
{
	ofstream fout("text.txt", ios::app);	

	static int count=1;
	int n, a, b, r, result;
	//result 为正确结果；n为题数；a，b为两个随机生成的数；r为用户输入的结果；
	double score = 0;//score为分数
	srand((unsigned)time(0));
	n = 1 + rand() % 10;
	//随机生成1—10道加法题
	cout << "**********欢迎来到单项加法运算练习系统!***********" << endl;
	cout << "**********您将回答" << n << "道单项加法运算题********" << endl;
	fout << "加法试题第" << count << "套" << endl; 
	count += count;
	fout << "答题人:" << name<< endl;
	//fout<<time()<<"用时"<<endl;

	SYSTEMTIME sys;
	GetLocalTime(&sys);
	fout <<"答题时间是:"<<sys.wYear<<"."<< sys.wMonth<<"."<< sys.wDay<<"   "<< sys.wHour<<":"<< sys.wMinute<<"   " <<endl;

	for (int i = 0; i < n; ++i)
	{
		a = 1 + rand() % 20;//随机生成1-20的随机整数
		b = 1 + rand() % 20;//随机生成1-20的随机整数
		result = a + b;
		cout << "第" << i + 1 << "题：" << a << "+" << b << "=";
		fout << "第" << i + 1 << "题：" << a << "+" << b << "=";
		cin >> r;
		if (r == result)
		{
			cout << "恭喜你，答对了！" << endl;
			sound1();
			//加音频
			++score;
		}
		else
		{
			cout << "很遗憾，回答错误..." << endl;
			sound2();
			//加音频
			cout << "正确的答案是：" << result << endl;
		}
		fout << "正确答案是：" << result << endl<< "您的答案是：" << r << endl;
	}
	cout << endl;
	cout << "练习结束，您一共回答了" << n << "道题" << endl;
	cout << "您答对了" << score << "道题，得到了"<< setiosflags(ios::fixed) <<setprecision(0)<<(score/n)*100<<"分"<<endl;
	//避免成绩的小数的出现
	fout << "练习结束，您一共回答了" << n << "道题" << endl;
	fout << "您答对了" << score << "道题，得到了" << setiosflags(ios::fixed) << setprecision(0) << (score / n) * 100 << "分" << endl;
	fout << endl;
	system("pause");//停留在控制台
	system("cls");//清屏
	return menu2();//返回至菜单2界面
}
void sub()
{
	ofstream fout("text.txt", ios::app);
	int n, a, b, r, result;
	static int count=1;
	//result 为正确结果；n为题数；a，b为两个随机生成的数；r为用户输入的结果；
	double score = 0;//score为分数
	cout << "**********欢迎来到单项减法运算练习系统!***********" << endl;
	cout << "            请输入需要练习的题目数:";
	cin >> n;
	cout << "**********您将回答" << n << "道单项减法运算题********" << endl;
	fout << "减法试题第" << count << "套" << endl; //无法实现第几套
	count += count;
	fout << "答题人:" << name << endl;
	//fout << time() << "    ";
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	fout << "答题时间是:" << sys.wYear << "." << sys.wMonth << "." << sys.wDay << "   " << sys.wHour << ":" << sys.wMinute << endl;

	for (int i = 0; i < n; ++i)
	{
		cout << "请输入两数作为被减数和减数："; 
		cin >> a >> b;
		if (a < b)
		{
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
			//用位运算实现两数交换，实现大的数为被减数，小的数为减数
		}
		result = a - b;
		cout << "第" << i + 1 << "题：" << a << "-" << b << "=";
		fout << "第" << i + 1 << "题：" << a << "-" << b << "=";
		cin >> r;
		if (r == result)
		{
			cout << "恭喜你，答对了！" << endl;
			sound1();
			//加音频
			++score;
		}
		else
		{
			cout << "很遗憾，回答错误..." << endl;
			sound2();
			//加音频
			cout << "正确的答案是：" << result << endl;
		}
		fout << "正确答案是：" << result << endl << "您的答案是：" << r << endl;
	}
	cout << endl;
	cout << "练习结束，您一共回答了" << n << "道题" << endl;
	cout << "您答对了" << score << "道题，得到了" << setiosflags(ios::fixed) << setprecision(0) << (score / n) * 100 << "分" << endl;
	//避免成绩的小数的出现
	fout << "练习结束，您一共回答了" << n << "道题" << endl;
	fout << "您答对了" << score << "道题，得到了" << setiosflags(ios::fixed) << setprecision(0) << (score / n) * 100 << "分" << endl;
	fout << endl;
	system("pause");//停留在控制台
	system("cls");//清屏
	return menu2();//返回至菜单2界面
}
void mix()
{
	ofstream fout("text.txt", ios::app);
	int n,a,b,c,d,r,result;
	static int count=1;
	//result 为正确结果；n为题数；a，b，c为三个随机生成的数；r为用户输入的结果；d为随机生成+-号的因子
	double score = 0;//score为分数
	srand((unsigned)time(0));
	n = 1 + rand() % 10;
	//随机生成1—10道加法题
	cout << "**********欢迎来到单项加法运算练习系统!***********" << endl;
	cout << "**********您将回答" << n << "道单项加法运算题********" << endl;
	fout << "混合加减试题第" << count << "套" << endl; //无法实现第几套
	count += count;
	fout << "答题人:" << name << endl;

	SYSTEMTIME sys;
	GetLocalTime(&sys);
	fout << "答题时间是:" << sys.wYear << "." << sys.wMonth << "." << sys.wDay << "   " << sys.wHour << ":" << sys.wMinute << endl;

	for (int i = 0; i < n; ++i)
	{
		a = 1 + rand() % 20;//随机生成1-20的随机整数
		b = 1 + rand() % 20;//随机生成1-20的随机整数
		c = 1 + rand() % 20;//随机生成1-20的随机整数
		d = 1 + rand() % 2;//随机生成加减号的因子
		result = a + b;
		switch (d)
		{
		case 1://a+b-c
			if (b - c < 0)
			{
				int temp;
				temp = b;
				b = c;
				c = temp;
				//引入第三变量来实现两数交换
			}
			result = a + b - c;
			cout << "第" << i + 1 << "题：" << a << "+" << b << "-" << c << "=";
			fout << "第" << i + 1 << "题：" << a << "+" << b << "-" << c << "=";
			cin >> r;
			if (r == result)
			{
				cout << "恭喜你，答对了！" << endl;
				sound1();
				//加音频
				++score;
			}
			else
			{
				cout << "很遗憾，回答错误..." << endl;
				sound2();
				//加音频
				cout << "正确的答案是：" << result << endl;
				fout << "正确答案是：" << result << endl<< "您的答案是：" << r << endl;
			}
			break;
		case 2://a-b+c
			if (a-b< 0)
			{
				swap(a, b);
				//用swap函数来实现两数的交换
			}
			result = a -b + c;
			cout << "第" << i + 1 << "题：" << a << "-" << b << "+" << c << "=";
			fout << "第" << i + 1 << "题：" << a << "-" << b << "+" << c << "=";
			cin >> r;
			if (r == result)
			{
				cout << "恭喜你，答对了！" << endl;
				sound1();
				//加音频
				++score;
			}
			else
			{
				cout << "很遗憾，回答错误..." << endl;
				sound2();
				//加音频
				cout << "正确的答案是：" << result << endl;
				fout << "正确答案是：" << result <<endl<< "您的答案是：" << r << endl;
			}
			break;
		}
		
		
	}
	cout << endl;
	cout << "练习结束，您一共回答了" << n << "道题" << endl;
	cout << "您答对了" << score << "道题，得到了" << setiosflags(ios::fixed) << setprecision(0) << (score / n) * 100 << "分" << endl;
	fout << "练习结束，您一共回答了" << n << "道题" << endl;
	fout << "您答对了" << score << "道题" << " " << "错误" << n - score << "道题" << endl;
	fout << endl;
	system("pause");//停留在控制台
	system("cls");//清屏
	return menu2();//返回至菜单2界面
}
