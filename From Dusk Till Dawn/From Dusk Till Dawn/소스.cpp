#include <cstdio>
#include <map>
#include <string>
#include <queue>
using namespace std;

int route[1002][4];
int mintime[102][2];

int main()
{
	int t, T, i, j, numE, n, N, startt, endt, point, curtime[2], pointd, pointt, dest;
	char start[40], end[40];
	scanf("%d", &T);

	for (t = 1; t <= T; t++)
	{
		map<string, int> namelist;
		queue<int> q;

		for (j = 0; j < 101; j++)
			mintime[j][0] = mintime[j][1] = 10000000;
		j = 1;
		numE = 0;

		scanf("%d", &N);
		for (i = 0; i < N; i++) {

			scanf("%s %s %d %d", start, end, &startt, &endt);
			if ((5 < startt && startt < 18) || ((6 < ((startt + endt) % 24)) && ((startt + endt) % 24) < 19))
				continue;
			if (namelist.find(start) == namelist.end())
				namelist.insert(make_pair(start, j++));
			if (namelist.find(end) == namelist.end())
				namelist.insert(make_pair(end, j++));
			startt = (startt + 6) % 24;

			route[numE][0] = namelist[start];
			route[numE][1] = namelist[end];
			route[numE][2] = startt;
			route[numE][3] = endt;
			numE++;
		}
		scanf("%s %s", start, end);
		if (namelist.size()) {
			q.push(namelist[start]);
			mintime[q.front()][0] = mintime[q.front()][1] = 0;
		}
		// ��߽ð� 0��, ������ 12�� ����, �� 18�ÿ� �� �Ծ�ߵ�
		while (!q.empty()) {
			point = q.front();  // ���� ���� point �� ����
			curtime[0] = mintime[point][0]; // ���� ��¥
			curtime[1] = mintime[point][1]; // ���� �ð�
			q.pop();
			if (point == namelist[end])
				continue;

			for (i = 0; i < numE; i++) // i���� ����ϴ� ��Ʈ ���ʷ� �湮
			{
				if (route[i][0] != point)continue; // ������� ���� ��ġ�� �ƴ϶��

				pointd = curtime[0]; // pointd �� i�� �������� �� ��¥
				pointt = route[i][2] + route[i][3];		// pointt �� i�� �������� �� �ð�
				dest = route[i][1];

				if (route[i][2] < curtime[1]) { // ���� ���� �̹� ����ߴٸ�
					pointd++; // ������ �� Ÿ�ߵ�
				}

				if (pointd < mintime[dest][0] || ((pointd == mintime[dest][0]) && pointt < mintime[dest][1])) {
					mintime[dest][0] = pointd;
					mintime[dest][1] = pointt;
					q.push(route[i][1]);
				}
			}


		}
		i = namelist[end];
		printf("Test Case %d.\n", t);
		if (mintime[namelist[end]][1] != 10000000)
			printf("Vladimir needs %d litre(s) of blood.\n", mintime[namelist[end]][0]);
		else
			printf("There is no route Vladimir can take.\n");
	}
}