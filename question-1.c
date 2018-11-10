#include<stdio.h>
# define ll long long

int dsu[10000];
int n, m;

struct pair {
	int first;
	int second;
};

struct pair2 {
	int first;
	pair second;
};

struct pair2 p[10000];

void sortPair() {

	int i, j;
	struct pair2 temp;
	for (i = 0; i < m; i++)
		for (j = 0; j < m-1; j++)
			if (p[j].first > p[j+1].first) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
}

void printPair() {
	for(int i = 0; i < m; i++)
		printf("%d %d %d\n", p[i].first, p[i].second.first, p[i].second.second);
}

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

int kruskal() {

	int x, y;
	int cost, min_cost = 0;
	for (int i = 0; i < m; i++) {
		x = p[i].second.first;
		y = p[i].second.second;

		cost = p[i].first;

		if(dsu[x] != dsu[y]) {
			min_cost += cost;
			dsuUnion(x, y);
		}
	}

	return min_cost;

}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		struct pair p1;
		p1.first = x;
		p1.second = y;
		p[i].first = k;
		p[i].second = p1;
	}

	printPair();
	printf("\n");
	sortPair();
	printPair();

	dsuInitialize();

	int cost = kruskal();

	printf("\ncost: %d", cost);





	return 0;
}