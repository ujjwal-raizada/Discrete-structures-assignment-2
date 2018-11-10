#include<stdio.h>
# define ll long long

int sw[1000][1000];
int vw[1000][1000];
int flag = 0;
int ns, ms, nv, mv, n, m;

void printArr(int a[]) {
	for (int i = 0; i < n; i++)
		printf("%d -> %d\n", i, a[i]);
	printf("\n");
}

void findMatch(int a[]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if(sw[i][j] != vw[a[i]][a[j]])
				return;
	
	printArr(a);
	flag = 1;
	return;
}

void permutation(int a[], int size) {


	if (size == 1) {
		//printArr(a);
		findMatch(a);
		return;
	}

	for (int i = 0; i < size; i++) {
		permutation(a, size-1);

		if (size%2 == 1) {
			int t = a[0];
			a[0] = a[size-1];
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

	scanf("%d %d", &ns, &ms);
	for (int i = 0; i < ns; i++)
		for (int j = 0; j < ns; j++)
			sw[i][j] = 0;

	for (int i = 0; i < ms; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		sw[p][q] = 1;
		sw[q][p] = 1;
	}

	scanf("%d %d", &nv, &mv);
	for (int i = 0; i < nv; i++)
		for (int j = 0; j < nv; j++)
			vw[i][j] = 0;

	for (int i = 0; i < mv; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		vw[p][q] = 1;
		vw[q][p] = 1;
	}

	if ( ns == nv && ms == mv ) {
		n = ns; m = ms;
		int a[n];
		for (int i = 0; i < n; i++)
			a[i] = i;

		permutation(a, n);
		if (flag == 1)
			printf("\nYes\n");
		else
			printf("\nNo\n");

	}
	else {
		printf("\nNo\n");
	}




	return 0;
}