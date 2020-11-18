#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

bool edge[101][101];
int iscnct[101];

bool isConnected(int deleted, int N)
{
	int i, j, k, cnt, index;
	cnt = 0;
	for (i = 1; i <= N; i++)
	{
		if (i == deleted) continue;

		for (j = 1; j <= N; j++)
		{
			if (j == deleted) continue;

			if (!edge[i][j]) continue;

			if (iscnct[i] == 0 && iscnct[j] == 0) {
				// �� �� ������ ���°��
				cnt++;
				iscnct[i] = cnt;
				iscnct[j] = cnt;
			}
			else if (iscnct[i] && iscnct[j]) {
				// �� �� ������ �ִ� ���
				if (iscnct[i] < iscnct[j]) {
					index = iscnct[j];
					for (k = 1; k <= N; k++)
					{
						if (iscnct[k] == index)
							iscnct[k] = iscnct[i];
					}
				}
				else {
					index = iscnct[i];
					for (k = 1; k <= N; k++)
					{
						if (iscnct[k] == index)
							iscnct[k] = iscnct[j];
					}
				}
			}
			else {
				// �� �� �ϳ��� ������ �ִ°��
				index = iscnct[i] | iscnct[j];
				iscnct[i] = iscnct[j] = index;
			}
		}
	}
	for (i = 1; i <= N; i++)
		if (iscnct[i] != 1)
			return false;
	return true;
}

void cal(int N, int R)
{
	int i, j, k;

	for (i = 1; i <= N; i++)
	{// i�� �����ϴ� ���





	}
}

int main()
{
	int N, i, j, n, R;
	string str1, str2;
	while (1)
	{
		map<string, int> name;
		scanf("%d", &N);
		if (N == 0) break;

		for (i = 1; i <= N; i++) {
			cin >> str1;
			name.insert(make_pair(str1, i));
		}

		scanf("%d", &R);

		for (i = 1; i <= R; i++)
		{
			cin >> str1;
			cin >> str2;
			edge[name[str1]][name[str2]] = true;
			edge[name[str2]][name[str1]] = true;
		}
		//-----------------------------�Է� �Ϸ�
		cal
	}
}