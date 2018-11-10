#include<stdio.h>
# define ll long long

ll flag = 0;

void findInTree(ll x, ll y, ll z) {
	if (x == y)
		flag = 1;

	if (z <= 0)
		return;

	if (x > y)
		return;

	//printf("\nx1 (step %lld): %lld", z, x<<1);
	findInTree(x<<1, y, z-1);
	
	//printf("\nx2 (step %lld): %lld", z, (((x<<1)<<1)<<1) + (x<<1) + 1);
	findInTree((((x<<1)<<1)<<1) + (x<<1) + 1, y, z-1);
	
	return;
} 


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll t, x, y, z;
	scanf("%lld", &t);


	while (t--) {

		scanf("%lld %lld %lld", &x, &y, &z);
		findInTree(x, y, z);

		if(flag == 1)
			printf("Yes\n");
		else
			printf("No\n");

		flag = 0;



	}
	





	return 0;
}