/*
[�� ����]
	���� ���� �˰��� �� �ϳ�.
	pivot : �迭���� ��� ����
	���� : �ǹ��� �������� ���� ���� ����, ū ������ �����ʿ� ��ġ�ϰ� ����
	���� : ���ҵ� �迭�� ���� �������� ��������� ȣ�� �Ͽ� ����

[���� ����]
	������ ���� 2���� ������ �����ϰ� ������ �ذ��� ���� ��ȭ�� ��Ƽ� ������ ������ �ذ��ϴ� ����
	ū ������ ���� ���� ������ �����Ͽ� �ذ��ϰ�, �� ���� �������� �ش��� �����Ͽ� ��ü ������ �ش��� ��´ٴ� �ǹ�

	���� : ���� ������ ���� ���� ������ ����, ���� ������� ������� �̷����
	���� : �� ���� ������ ��������� �ذ�, ���� ������ ũ�Ⱑ ����� �۾Ƽ� ���� �ذ��� �� �ִ� ��쿡 �ش�
	���� : ���� ������ �ش��� ����. ���� ������ �ش��� ����

[�ŵ� ���� �˰���]
	���� : �ŵ������� ������ ������ ������ �ΰ��� ���������� ����
	���� : �� ���������� ��������� �ذ�, �̶� ũ�Ⱑ ����� ������ ���� ���

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
	/// �迭�� �ǹ��� �������� ����
	/// �ǹ��� �������� �� �κ����� ����
	/// �ǹ��� �迭 ������ ���ҿ� ��ȯ, ���������� ���鼭 �ǹ����� ���� ���� ���ʿ�
	/// �� ������ ������ �ǹ��� �ڽ� �ڽ��� ������ġ�� ���̰� �Ǹ� �� ��ġ�� ����
	/// </summary>
	/// <param name="arr">�迭</param>
	/// <param name="left">����</param>
	/// <param name="right">������</param>
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

	cout << "���� ���Ŀ� �ҿ�� �ð� : " << elapsed.count() << "��" << endl;

	//std::sort();
}