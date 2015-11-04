// My implementation for bubble sort.
#include <iostream>
#include <vector>
using namespace std;

/*
template <typename T>
void swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}
*/

void bubbleSort(vector<int> &v)
{
	int n, i, j;
	int val;
	
        n = (int)v.size();
        for (i = 0; i < n; ++i) {
            for (j = n - 1; j > i; --j) {
                if (v[j - 1] > v[j]) {
                    swap(v[j -1 ], v[j]);
                }
            }
        }
}


void bubbleSort2(vector<int> &v)
{
	int n, i, j;
	int val;
        bool swapped = true;
	
	n = (int)v.size();
        i = 0;
        while (swapped) {
            swapped = false;
            for (j = n - 1; j > i; --j) {
                if (v[j - 1] > v[j]) {
                    swap(v[j -1 ], v[j]);
                    swapped = true;
                }
            }
            i++;
        }
}


void bubbleSort3(vector<int> &v)
{
	int n, i, j;
	int val;
        int lastSwapped ;
	
	n = (int)v.size();
        lastSwapped = n - 1;
        i = 0;
        while (lastSwapped > 0) {
            lastSwapped = 0 ;
            for (j = n - 1; j > i; --j) {
                if (v[j - 1] > v[j]) {
                    swap(v[j -1 ], v[j]);
                    lastSwapped = j;
                }
            }
            i = lastSwapped ;
        }
}


int main()
{
	vector<int> v;
	int n, i;
	
	while (cin >> n && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
	//	bubbleSort(v);
		bubbleSort(v);
		for (i = 0; i < n; ++i) {
			cout << v[i] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
