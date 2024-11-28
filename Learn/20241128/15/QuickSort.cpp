/*
[퀵 정렬]
	분할 정복 알고리즘 중 하나.
	pivot : 배열안의 요소 선택
	분할 : 피벗을 기준으로 작은 값은 왼쪽, 큰 값들은 오른쪽에 위치하고 분할
	정복 : 분할된 배열에 대해 퀵정렬을 재귀적으로 호출 하여 정렬

[분할 정복]
	문제를 작은 2개의 문제로 분할하고 각각을 해결한 다음 결화를 모아서 원래의 문제를 해결하는 전략
	큰 문제를 작은 하위 문제로 분할하여 해결하고, 그 하위 문제들의 해답을 조합하여 전체 문제의 해답을 얻는다는 의미

	분할 : 원래 문제를 작은 하위 문제로 분할, 보통 재귀적인 방법으로 이루어짐
	정복 : 각 하위 문제를 재귀적으로 해결, 하위 문제의 크기가 충분히 작아서 직접 해결할 수 있는 경우에 해당
	결합 : 하위 문제의 해답을 결합. 원래 문제의 해답을 얻음

[거듭 제곱 알고리즘]
	분할 : 거듭제복의 지수를 반으로 나누어 두개의 하위문제로 분할
	정복 : 각 하위문제를 재귀적으로 해결, 이때 크기가 충분히 작으면 직접 계산

	2^8 == 2^4 * 2^4
	2^4 == 2^2 * 2^2
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;


class CQuickSort {
public:

	void QuickSort(std::vector<int>& items) {
		QuickSortHelper(items, 0, items.size() - 1);
	}

	void QuickSortHelper(vector<int>& items, int left, int right) {
		if (left < right) {
			int partitionIndex = Partition(items, left, right);

			QuickSortHelper(items, left, partitionIndex -1);
			QuickSortHelper(items, partitionIndex + 1, right);
		}
	}

	/// <summary>
	/// 배열의 피벗을 기준으로 분할
	/// 피벗을 기준으로 두 부분으로 나눔
	/// 피벗을 배열 마지막 원소와 교환, 순차적으로 돌면서 피벗보다 작은 값을 왼쪽에
	/// 이 과정이 끝나면 피벗은 자시 자신의 최종위치에 놓이게 되며 이 위치를 리턴
	/// </summary>
	/// <param name="arr">배열</param>
	/// <param name="left">왼쪽</param>
	/// <param name="right">오른쪽</param>
	/// <returns></returns>
	int Partition(vector<int>& arr, int left, int right) {
		int pivotIndex = (left + right) / 2;
		int pivotValue = arr[pivotIndex];

		Swap(arr, pivotIndex, right);
		int storeIndex = left;
		for (int i = left; i < right; ++i) {
			if (arr[i] < arr[pivotIndex]) {
				Swap(arr, i, storeIndex);
				++storeIndex;
			}
		}
		Swap(arr, storeIndex, right);

		return storeIndex;
	}

	void Swap(vector<int>& arr, int a, int b) {
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	void printArr(vector<int>& arr) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}

		cout << endl;
	}
};


vector<int> QuickSort(vector<int>& arr) {
	if (arr.size() == 0) {
		return arr;
	}

	int n = arr.size();

	int pivot = rand() % n;

	vector<int> leftArr;
	vector<int> rightArr;

	for (int i = 0; i < n; i++) {
		if (i == pivot) {
			continue;
		}

		if (arr[i] < arr[pivot]) {
			leftArr.push_back(arr[i]);
		}
		else {
			rightArr.push_back(arr[i]);
		}
	}

	leftArr = QuickSort(leftArr);
	rightArr = QuickSort(rightArr);

	vector<int> tempArr = vector<int>(n);

	for (int i = 0; i < leftArr.size(); i ++) {
		tempArr[i] = leftArr[i];
	}

	tempArr[pivot] = arr[pivot];

	for (int i = 0; i < rightArr.size(); i++) {
		tempArr[pivot + 1 + i] = rightArr[i];
	}

	return tempArr;
}

int main() {
	CQuickSort q;

	vector <int> arr = { 4,51,6,2,3,4,76,4,14,5 };

	q.QuickSort(arr);
	q.printArr(arr);


	vector<int> data(1000000);

	std::random_device rd;
	std::mt19937 gen(rd());
	uniform_int_distribution<>dis(0, 9999999);

	for (int& num : data) {
		num = dis(gen);
	}

	//vector<int> data2 =  QuickSort(arr);

	auto start = std::chrono::high_resolution_clock::now();

	q.QuickSort(data);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = end - start;

	cout << "버블 정렬에 소요된 시간 : " << elapsed.count() << "초" << endl;

	//std::sort();
}