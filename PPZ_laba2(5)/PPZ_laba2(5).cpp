#include <iostream>
using namespace std;
void filling1(int*& nums, int i, int n,int m, bool mode)
{
	if (mode) {
		if (i < n) {
			nums[i] = rand() % 21-10;
			i++;
			filling1(nums, i, n, m, mode);
		}
		else if (i < (n + m))
		{
			nums[i] = 0;
			i++;
			filling1(nums, i, n, m, mode);
		}
	}
	else {
		if (i < n) {
			do { cin >> nums[i]; } while (nums[i] < -10 || nums[i]>10);
			cout << " writed...\n";
			i++;
			filling1(nums, i, n, m, mode);
		}
		else if (i < (n + m))
		{
			nums[i] = 0;
			i++;
			filling1(nums, i, n, m, mode);
		}
	}
}
void filling2(int*& nums, int i, int m, bool mode)
{
	if (mode) {
		if (i < m) {
			nums[i] = rand() % 21 - 10;
			i++;
			filling2(nums, i, m, mode);
		}
		else return;
	}
	else {
		if (i < m) {
			do { cin >> nums[i]; } while (nums[i] < -10 || nums[i]>10);
			cout << " writed...\n";
			i++;
			filling2(nums, i, m, mode);
		} return;
	}
}
void extract(int* nums, int i, int n)
{
	if (i < n) {
		cout << nums[i] << ' ';
		i++;
		extract(nums, i, n);
	}
}
void sorting(int*& numb, int n)
{
	int i, j, k, x;
	for (i = 0; i < n; i++) {
		k = i;
		x = numb[i];
		for (j = i + 1; j < n; j++) {
			if (numb[j] < x) {
				k = j;
				x = numb[j];
			}
		}
		numb[k] = numb[i];
		numb[i] = x;
	}
}
void connecting(int*& num, int*& num1, int n, int m)
{
	for(int i = m+n; i >= n;i--)
	{ 
		num[i] = num1[i-n];
	}
}
int main()
{
	int n, m, modeint;
	bool mode;
	do {
		cout << "Enter n size: ";
		cin >> n;
		cout << "Enter m size: ";
		cin >> m;
	} while (m < 0 || n <0 || m+n<1 || m+n >200);
	int* nums = new int[n+m];
	int* nums1 = new int[m];
	srand(time(NULL));
	do {
		cout << "Choose mode (1 - autoentering, 0 - enterig by yourself): ";
		cin >> modeint;
	} while (modeint < 0 || modeint > 1);
	mode = modeint;
	filling1(nums, 0, n, m, mode);
	filling2(nums1, 0, m, mode);
	sorting(nums, n);
	extract(nums, 0, n+m);
	cout << "\n";
	sorting(nums1, m);
	extract(nums1, 0, m);
	cout << "\n";
	connecting(nums, nums1, n, m);
	sorting(nums, n + m);
	extract(nums, 0, n+m);
}