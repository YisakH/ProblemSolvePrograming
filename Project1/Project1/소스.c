#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int T;
	int x1, x2, y1, y2, r1, r2, result;
	double distance;
	
	for (int i = 0; ;i++)
	{
		srand((unsigned int)time(NULL));
		x1 = (rand() % 20000) - 10000;
		y1 = (rand() % 20000) - 10000;
		r1 = abs((rand() % 20000) - 10000);
		x2 = (rand() % 20000) - 10000;
		y2 = (rand() % 20000) - 10000;
		r2 = abs((rand() % 20000) - 10000);

		distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		if (distance > r1 + r2)
			result = 0;
		else if (abs(distance - (r1 + r2)) < 0.000001)
			result = 1;


		else if (distance < abs(r1 - r2))
			result = 0;
		else if (x1 == x2 && y1 == y2 && r1 == r2)
			result = -1;
		else if (abs(distance - abs(r1 - r2)) <= 0.0000001)
			result = 1;
		else
			result = 2;
		if (result != your(x1, y1, r1, x2, y2, r2)) {
			printf("%d %d %d %d %d %d", x1, y1, r1, x2, y2, r2);
			return 0;
		}
		printf("%d\n", i);
	}
}


int your(int x1, int y1, int r1, int x2, int y2, int r2)
{
	double d;
	//d�� �� �߽� ������ �Ÿ�
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	//���� �߽��� ���� �������� ������ ������ ���Ѵ�
	if (x1 == x2 && y1 == y2 && r1 == r2) return -1;

	// d�� ������ r1, r2�� ������ �պ��� ũ�� ����
	else if (d * d > r1 * r1 + r2 * r2) {
		if (r1 >= r2) {
			if (r1 + r2 > d) return 2;
			else if (r1 + r2 < d) return 0;
			else return 1;
		}
		else {
			if (r2 + r1 > d) return 2;
			else if (r2 + r1 < d) return 0;
			else return 1;
		}
	}

	// d�� ������ r1, r2�� ������ �պ��� ������ ����
	else {
		if (r1 > r2) {
			if (r1 - r2 > d) return 0;
			else if (r1 - r2 < d) return 2;
			else return 1;
		}
		else {
			if (r2 - r1 > d) return 0;
			else if (r2 - r1 < d) return 2;
			else return 1;
		}

	}
}