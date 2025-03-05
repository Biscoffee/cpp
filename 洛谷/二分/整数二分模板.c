//查找最后一个 <= x的数的下标
int find(int x)
{
	int l = 0, r = n + 1; //开区间
	while (l + 1 < r)  //l+1==r时结束
	{
		int mid = (l + r) >> 1;  //相当于mid=(l+r)/2;
		if (a[mid] <= x) l = mid;
		else r = mid;
	}
	return l;
}
//查找第一个 >= x的数的下标
int find(int x)
{
	int l = 0, r = n + 1; //开区间
	while (l + 1 < r)  //l+1==r时结束
	{
		int mid = (l + r) >> 1;  //相当于mid=(l+r)/2;
		if (a[mid] >= x) r = mid;
		else l = mid;
	}
	return r;
}

//浮点数二分
double find(double y)
{
    double l = -100, r = 100; 
    while(r - l > 1e-8)
    {
        double mid = (l+r)/2;
        if(mif * mid * mid <= y) l = mid;
        else r = mid;
    }
    return l;
}

bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
