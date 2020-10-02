#include<cstdio>
#include<iostream>
#include<string>
#include <fstream>
using namespace std;
struct stu {
	string num;//学号
	char name[10];//姓名
	int ds;//平时成绩
	int es;//实验成绩
	int fs;//期末成绩
}s1[10];
struct final {
	string num;//学号
	double score;//总成绩
	int rank;//排名
}f1[10];

int main() {
	int N;//学生总数
	cin >> N;
	//信息录入
	cout << "输入学生基本信息及成绩信息（顺序：学号、姓名、平时成绩、实验成绩、期末成绩" << endl;
	ifstream in("data.txt");
	for (int i = 0; i < N; i++) {
		in >> s1[i].num >> s1[i].name >> s1[i].ds >> s1[i].es >> s1[i].fs;
	}
	//计算各学生总成绩及排名情况
	for (int i = 0;i < N;i++) {
		cout << s1[i].num << s1[i].name << s1[i].ds << s1[i].es << s1[i].fs << endl;
	}
	for (int j = 0; j < N; j++) {
		f1[j].num = s1[j].num;
		f1[j].score = s1[j].ds * 0.2 + s1[j].es * 0.2 + s1[j].fs * 0.6;
	}
	for (int k = 0; k < N; k++) {
		int g = 1;
		for (int t = 0; t < N; t++) {
			if (f1[k].score < f1[t].score)
				g++;
			else
				g;
		}
		f1[k].rank = g;
		g = 0;
	}//排名
	//输入学号查询成绩信息
	cout << "输入学号查询该学生成绩及排名" << endl;
	string num;
	int name1;
	cin >> num;
	for (int i = 0; i < N; i++) {
		if (f1[i].num == s1[i].num) {
			name1 = i;
			break;
		}
		else
			name1;
	}
	cout << f1[name1].score << " " << f1[name1].rank << endl;
	//统计全班学生成绩的均值和标准方差
	double ave = 0;//均值
	double dev = 0;//标准方差
	for (int k = 0; k < N; k++) {
		ave = ave + f1[k].score;
	}
	ave = ave / N;
	for (int k = 0; k < N; k++) {
		dev = dev + (f1[k].score - ave)*(f1[k].score - ave);
	}
	dev = dev / (N - 1);
	cout << "均值:" << ave << " " << "方差:" << dev << endl;
	return 0;
}

