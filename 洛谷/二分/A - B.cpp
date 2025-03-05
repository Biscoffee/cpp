#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const int N = 2e5+10;
int a[N], n, c;
ll sum;
 
int find1(int x)
{
	int l = -1, r = n;
	while (l + 1 < r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] >= x) r = mid;
		else l = mid;
	}
	if (a[r] == x) return r;
	else return 0;
}
 
int find2(int x)
{
	int l = -1, r = n;
	while (l + 1 < r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] <= x) l = mid;
		else r = mid;
	}
	if (a[l] == x) return l;
	else return 0;
}
 
int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		int x = a[i] + c;
		if (find1(x))
			sum += find2(x) - find1(x) + 1;
	}
	cout << sum << endl;
	return 0;
}
