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


int main()
{
 
}

