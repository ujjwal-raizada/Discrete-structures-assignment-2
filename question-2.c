#include<stdio.h>
# define ll long long

int n, m, min_cost = 999999;
int am[1000][1000];
int final_path[10000];

void printArr(int a[]) {
	for (int i = 0; i < n+1; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void findHam(int a[]) {

	a[0] = 0;
	a[n] = 0;

	//printArr(a);
	int cost = 0;
	for (int i = 0; i < n; i++) {
		if(am[a[i]][a[i+1]] == -1)
			return;
		cost += am[a[i]][a[i+1]];
	}

	if (cost < min_cost) {
		min_cost = cost;
		//printArr(a);
		for (int i = 0; i <= n; i++)
			final_path[i] = a[i];
	}

}

void permutation(int a[], int size) {


	if (size == 1) {
		//printArr(a);
		findHam(a);
		return;
	}

	for (int i = 1; i < size; i++) {
		permutation(a, size-1);

		if (size%2 == 1) {
			int t = a[1];
			a[1] = a[size-1];
			a[size-1] = t;
		}

		else {
			int t = a[i];
			a[i] = a[size-1];
			a[size-1] = t;
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			am[i][j] = -1;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		am[x][y] = z;
		am[y][x] = z;
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		printf("%d ", am[i][j]);
	// 	}
	// 	printf("\n");
	// }


	int a[n];

	for (int i = 1; i < n; i++) {
		a[i] = i;
	}

	permutation(a, n);

	for (int i = 0; i < n; i++)
		printf("%c => ", (char)(final_path[i] + 65));
	printf("%c", (char)(final_path[n] + 65));
	printf("\nCost: %d", min_cost);

	return 0;
}