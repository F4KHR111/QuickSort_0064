#include <iostream>
using namespace std;

//deklarasi array untuk menyimpan nilai
int arr[20];
int cmp_count = 0; //jumlah perbandingan
int mov_count = 0; //jumlah pergerakan data
int n;

void input() {
	while (true)
	{
		cout << "Masukan Panjang Element Array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum Panjang Array adalah 20" << endl;
	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++) {
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}

void swap(int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
	mov_count++;
}

void q_short(int low, int high) {
	
	int temp;
	int pivot, i, j;
	if (low > high) {
		return;
	}

	pivot = arr[low];
	i = low + 1;
	j = high;

	while (i <= j) {
		while ((arr[i] <= pivot) && (i <= high)) {
			i++;
			cmp_count++;
		}
		cmp_count++;
		//search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low)) {
			j--;
			cmp_count++;
		}
		cmp_count++;
		if (i < j) {
			//swap the element at index i with the element at index j
			swap(i, j);
		}
	}

	if (low < j) { 
		//swap the pivot element with the element at index j
		swap(low, j);
	}

	//recrusive call to sort the left sub array
	q_short(low, j - 1);

	//recrusive call to sort the right sub array
	q_short(j + 1, high);
}

void display() {
	cout << "\n------------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "------------------" << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparasions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
	char ch;

	do {
		input();
		q_short(0, n - 1);
		display();
		cout << "\n\nDo you want to continue? (y/n): ";
		cin >> ch;
		if (ch == 'n' || ch == 'N')
			break;

		system("pause");
		system("cls");
	} while (true);

	return 0;
}

