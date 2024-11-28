/*
[���� ����]




*/

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void BubbleSort(vector<int>& arr) {
	int n = arr.size();

	for (int i = 0; i < n; i++) {
		// �� �ݺ����� ���� ū ��Ұ� �� �ڷ� �̵�
		// �� �ε����� �����Ͽ� �ݺ�Ƚ���� ����
		for (int k = 0; k < n - i - 1; k++) {
			if (arr[k] > arr[k + 1]) {
				std::swap(arr[k], arr[k + 1]);
			}
		}
	}
}

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	std::vector<int> data(1000000);

	for (size_t i = 0; i < data.size(); i++) {
		data[i] = rand() % 1000000;
	}

	auto start = std::chrono::high_resolution_clock::now();

	BubbleSort(data);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = end - start;

	cout << "���� ���Ŀ� �ҿ�� �ð� : " << elapsed.count() << "��" << endl;

}