#include<stdio.h>
#include<stdlib.h>
# define ll long long
# define BYTE 8

void printBin(char* bin, ll n) {
	for (int i = 63 - n; i < 64; i++)
		printf("%c", bin[i]);
	printf("\n");
}


char *numToBin(ll a) {
	char *bin;
	bin = (char*)calloc(1, 64);
	ll po = 63;
	ll size = sizeof(a)*8;
	ll p = 1;
	for (int i = 0; i < size; i++) {
		ll t = a&p;
		if (t == 0) {
			bin[po] = '0';
			po--;
		}
		else {
			bin[po] = '1';
			po--;
		}
		p *= 2;
	}
	return bin;
} 

struct node {
	char data; // Storing data
	struct node *left; //for storing 0
	struct node *right; //for storing 1
};

struct node * newnode(char element)
{
		struct node * temp=(node * )malloc(sizeof(node));
		temp->data=element;
		temp->left=temp->right=NULL;
		return temp;
}

struct node * buildTree(struct node * root, char* bin) {
	//printf("Building Tree\n");
	struct node * temp = root;
	for (int i = 32; i < 64; i++) {
		if (bin[i] == '1') {
			if (temp -> right == NULL) {
				struct node * New = newnode('1');
				temp -> right = New;
				temp = temp -> right;
			}
			else
				temp = temp -> right;
		}
		else {
			if (bin[i] == '0') {
			if (temp -> left == NULL) {
				struct node * New = newnode('0');
				temp -> left = New;
				temp = temp -> left;
			}
			else
				temp = temp -> left;
			}
		}
	}
	//printf("Built.\n");
	return root;
}

ll power(ll a, ll b) {
	ll p = 1;
	for (ll i = 0; i < b; i++)
		p *= a;
	return p;
}

ll findMax(struct node * root, char* bin) {
	ll max_xor = 0;
	ll p = power(2, 31);
	struct node * temp = root;
	for (int i = 32; i < 64; i++) {
		if (bin[i] == '0') {
			if (temp -> right != NULL) {
				max_xor += p;
				p = p/2;
				temp = temp -> right;
			}
			else {
				temp = temp -> left;
				p = p/2;
			}

		}

		if (bin[i] == '1') {
			if (temp -> left != NULL) {
				max_xor += p;
				p = p/2;
				temp = temp -> left;
			}
			else {
				temp = temp -> right;
				p = p/2;
			}

		}
	}

	return max_xor;
}



int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll n;
	scanf("%lld", &n);
	ll a[n];
	char* bin[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		bin[i] = numToBin(a[i]);
	}

	struct node * root = newnode('2');
	for (int i = 0; i < n; i++)
		root = buildTree(root, bin[i]);


	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll s;
		scanf("%lld", &s);
		char* binArray = numToBin(s);
		ll ans = findMax(root, binArray);
		//printBin(binArray, 5);
		printf("%lld\n", ans);
	}

	

	return 0;
}