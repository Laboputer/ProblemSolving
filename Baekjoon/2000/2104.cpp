#include <stdio.h>
#define MAXN 100005
#define MIN(a,b) ((a<b) ? (a) :(b))
#define MAX(a,b) ((a<b) ? (b) : (a))
int N;
long long a[MAXN];

long long F(int l, int r)
{
	if (l == r) return a[l] * a[l];

	int mid = (l + r) / 2;
	long long ans = MAX(F(l, mid), F(mid + 1, r));

	long long mn = MIN(a[mid], a[mid + 1]);
	long long sum = a[mid] + a[mid + 1];

	int ll = mid - 1;
	int rr = mid + 2;
	
	while (l <= ll || rr <= r)
	{
		while (l <= ll && mn <= a[ll]) sum += a[ll], ll--;
		while (rr <= r && mn <= a[rr]) sum += a[rr], rr++;
		ans = MAX(ans, mn*sum);
		
		if (l > ll && rr > r) break;
		if (l > ll && rr <= r) sum += a[rr], mn = a[rr], rr++;
		else if (rr > r && l <= ll) sum += a[ll], mn = a[ll], ll--;
		else
		{
			if (a[ll] < a[rr]) sum += a[rr], mn = a[rr], rr++;
			else sum += a[ll], mn = a[ll], ll--;
		}
		ans = MAX(ans, mn*sum);
	}

	return ans;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &a[i]);
	
	printf("%lld", F(1, N));

	return 0;
}