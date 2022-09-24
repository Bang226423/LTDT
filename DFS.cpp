#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <vector>
#define MAX 100
using namespace std;
int n;// so dinh do thi
int arr[MAX][MAX];// ma tran ke do thi
bool DFS(int start, int goal, vector <bool>& visited, vector <int>& vertex, vector <int> path);
void Docfiledothi();// doc file
void Docfiledothi()
{
	
	//Doc file
	fstream file_in("D:\\Linh tinh\\input2.txt", ios::in);
	file_in >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			file_in >> arr[i][j];
	}
	//cout << "Da doc xong file " << endl;
	//cout << n << endl;
}
void Xuatfile()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

}
bool DFS(int start,int goal, vector <bool> &visited, vector <int> &vertex, vector <int> path)
{
	visited[start] = true;
	vertex.push_back(start);
	path.push_back(start);
	if (start == goal && goal >= 0)
		return true;
	for(int i= 0; i< n; i++)
		if (arr[start][i])
		{
			if (visited[i])
			{
				continue;
			}
			if (DFS(i, goal, visited, vertex, path))
			{
				return true;
			}
			else
				path.pop_back();
		}
	return false;
}
void main()
{
	int start;
	int goal;
	vector <bool> visited;
	vector <int> vertex;
	vector <int> path;
	Docfiledothi();
	Xuatfile();
	cout << "Nhap dinh bat dau : " << endl;
	cin >> start;
	cout << "Nhap dinh ket thuc : " << endl;
	cin >> goal;
	if (DFS(start, goal, visited, vertex, path) == true)
	{
		cout << "Danh sach dinh da duyet theo thu tu :" << endl;
		cout << vertex[start] << " ";
		cout << "Duong di :" << endl;
		cout << path[start] << "<-";
	}
	else
	{
		cout << "Khong co duong di tu " << start << "den " << goal << endl;
	}
	cout << endl;
	
}


