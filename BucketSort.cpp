#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100

int n;
vector<float> b[MAX];
float Min = 0.;
float Max = 0.;
int i, j;
int bi;

void bucketSort(float* arr, int n) {
	for (i = 0; i < n; i++) {
		bi = n * (arr[i] - Min) / (Max - Min);
		b[bi].push_back(arr[i]);
	}

	for (i = 0; i <= n; i++)
		sort(b[i].begin(), b[i].end());
    
	int index = 0;
	for (i = 0; i <= n; i++)
		for (j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}


int main() 
{
	cin >> n;
	float* arr = new float[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (i = 0; i < n; i++) {
		if (arr[i] < Min)
			Min = arr[i];
		if (arr[i] > Max)
			Max = arr[i];
	}

	bucketSort(arr, n);

	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;


	return 0;
}
