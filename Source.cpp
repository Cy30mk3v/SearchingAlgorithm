#include "Header.h"

int LinearExhaustive(int a[], int n, int x) 
{
	clock_t start = clock();
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) 
		{
			return i;
		}
	}
	clock_t end = clock();
	cout << "Time used by this function: " << (double(end - start) / CLOCKS_PER_SEC);
	return -1; //-1 ở đây có ý nghĩa là không tìm thấy phần tử x trong mảng a
}

int LinearSentinel(int a[], int n, int x) 
{
	clock_t start = clock();
	a[n] = x; //Vì ta muốn việc thêm x không thay đổi các phần tử đã có trước đó có trong mảng
	for (int i = 0; ; i++) { //Bởi vì không có điều kiện dừng
		if (a[i] == x) {
			clock_t end = clock();
			cout << "Time used by this function: " << (double(end - start) / CLOCKS_PER_SEC);
			return i;
		}
	}
	/*Tại vì ta đã gán x vào phần tử thứ n của mảng a, do đó return ở trên chắc chắn sẽ trả ra một giá trị (nếu tìm thấy thì trong khoảng 0 đến n-1 
	và nếu không tìm thấy thì trả về phần tử cuối cùng đó là phần tử thứ n*/
}

int BinarySearch(int a[], int n, int x) 
{
	clock_t start = clock();
	int l = 0, r = n - 1;
	while (l <= r) 
	{
		int m = (l + r) / 2;
		if (a[m] == x) 
		{
			clock_t end = clock();
			cout << "Time used by this function: " << (double(end - start) / CLOCKS_PER_SEC) << endl;
			return m;
		}
		else 
		{
			if (x < a[m]) 
			{
				r = m - 1;
			}
			else 
			{
				l = m + 1;
			}
		}
	}
	clock_t end = clock();
	cout << "Time used by this function: " << (double(end - start) / CLOCKS_PER_SEC) << endl;
	return -1;
}

int BinarySearchRecur(int *A, int l, int r, int x)
{

	if (l > r)
	{
		return -1;
	}
	int mid = (l+r) / 2;
	if (A[mid] == x)
	{
		return mid;
	}
	if (A[mid] > x)
	{
		return BinarySearchRecur(A, l, mid - 1, x);
	}
	if(A[mid] < x)
	{
		return BinarySearchRecur(A, mid + 1, r, x);
	}
}

int BinarySR(int *A, int n, int x)
{
	clock_t start = clock();
	int i=BinarySearchRecur(A, 0, n-1, x);
	clock_t end = clock();
	cout << "Time used by this function: " << (double(end - start) / CLOCKS_PER_SEC) << endl;
	return i;
}


Dictionary readDictionary()
{
	Dictionary D;
	int n;
	cout << "Input dictionary's name: " << endl;
	getline(cin, D.name);
	cout << "Input number of words: " << endl;
	cin >> n;
	D.number = n;
	D.N = new WORD[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Input word: ";
		if (i == 0)
		{
			fflush(stdin);
			cin.ignore();
		}
		cin.getline(D.N[i].Name,255);
		cout << "Input word's meaning: ";
		cin.getline(D.N[i].Meaning,512);
	}
	return D;
}

char *getWord()
{	
	char B[255];
	cout << "Input word: ";
	cin.getline(B, 255);
	char *A = _strdup(B);
	return A;
}

void findWord(char *A,Dictionary D)
{
	for (int i = 0; i < D.number; i++)
	{
		if (strcmp(A, D.N[i].Name)==0)
		{
			cout << "Word: " << D.N[i].Name << endl;
			cout << "Meaning: " << D.N[i].Meaning << endl;
			return;
		}
	}
	cout << "Not found!" << endl;
	return;
}




