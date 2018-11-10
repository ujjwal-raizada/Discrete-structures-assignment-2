#include<stdio.h>
# define ll long long

int dsu[10000];
int n, m;



void dsuInitialize() {
	for (int i = 0; i < n; i++)
		dsu[i] = i;
}

void dsuUnion(int x, int y) {
	int dsuY = dsu[y];
	for (int i = 0; i < n; i++)
		if (dsu[i] == dsuY)
			dsu[i] = dsu[x];
}

int isDisjoint(int x) {
	int t = dsu[0];
	for (int i = 0; i < n; i++)
		if (dsu[i] != t && dsu[i] != x)
			return 1;
	return 0;
}

void printDsu() {
	printf("\ndsu: ");
	for (int i = 0; i < n; i++)
		printf("%d ", dsu[i]);
	printf("\n");
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &n);
	scanf("%d", &m);

	int input[m][2];

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		input[i][0] = x;
		input[i][1] = y;
	}

	for (int i = 0; i < n; i++) {
		dsuInitialize();
		for (int j = 0; j < m; j++) {
			if(input[j][0] != i && input[j][1] != i)
				dsuUnion(input[j][0], input[j][1]);
		}

		//printDsu();

		if(isDisjoint(i))
			printf("%d ", i);
	}

	





	return 0;
}