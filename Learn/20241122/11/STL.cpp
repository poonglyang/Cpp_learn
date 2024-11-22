/***********************************
STL(���ٴٵ� ���ø� ���̺귯�� (ǥ�� ���ø� ���̺귯��))
	* �ݵ�� �˾ƾ���
	���α׷��� �ʿ��� �ڷᱸ���� �˰����� ���ø����� �����ϴ� ���̺귯��
	#include <list> #include <queue> #include <vector> #include <algorithm> ��

	���� ���
		�����̳�
			��ü�� �����ϴ� ��ü (������ Ŀ�ٶ� â��). 
			Ŭ���� ���ø� ���·� �����Ǿ� ����
			������ ���ҿ� ������ �� �ֵ��� �پ��� �ɹ��Լ��� ����

			������ �����̳�
				������ ����
				�����̳� ���Ұ� �ڽŸ��� ���� ��ġ�� ������ �����̳�

				vector(�迭 ���), list(��� ���), deque(�迭 ���)

			���� �����̳�
				���� ����
				���� ���Ұ� ���� �����ʹ� �ٸ��� Ư�� ���� ���ؿ� ���� �ڵ����� �Ǵ� �����̳�

				set(��� ���), multiset(��� ���), map(��� ���), multimap(��� ���)
		
		���ͷ����� (�ݺ���)
			�����Ϳ� ����� ����
			�����̳��� ���Ҹ� ����Ű�� ����Ű�� ���ҿ� �����Ͽ� ���� ���Ҹ� ����Ű�� �ϴ� ���

		
		�˰���
			���� ���� �˻� ���� �ذ��ϴ� �Ϲ�ȭ�� ����� �����ϴ� �Լ� ���ø�

	Vector
		���������� ����ȴ�(�޸𸮻�)
		���������� ���� �迭�� ����� ũ�⸦ �ڵ����� ����
		�ε����� ���� ���� ���ҿ� ���� ����(�迭�� [], ����Լ��� at)
			-> ������ ������
		�߰� ���� ������ ����ϰ� �Ͼ�� �ӵ��� ��������
			�߰��� �ִ� ���� ������ ��� �迭�� �ִ� ������ ��ĭ�� ����
				(1�ﰳ�� �����Ͱ� �ִ� Vector�� 5��° ���� �����ϸ� 9999�� 9995���� ����� �����)
			�߰��� ���� �����ϸ� �迭�� �ִ� ������ ��ĭ�� �δ�
				(1�ﰳ�� �����Ͱ� �ִ� Vector�� 5��°�� �����ϸ� 9999�� 9995���� �бⰡ �����)
		�� ���� ü���

		�ɹ� �Լ���
			empty()	: ���Ͱ� ��� �ִ��� Ȯ��
			clear()	: ������ ��� ��� ����
			at()	: ������ ��ҿ� �����ϸ� ���� �˻�(����ó��) ��
			front()	: ������ ù ��° ��� ��ȯ
			back()	: ������ ������ ��� ��ȯ
			push_back()	: ������ ���� ��� �߰�
			pop_back()	: ������ ������ ��Ҹ� ����
			erase()	: ������ ��ġ�� ��Ҹ� ����
			reserve	: ������ �뷮�� ����
			shrink_to_fit()	: ������ ���� ũ�⿡ �±� ����
			swap()	: �� ���͸� ��ȯ

	list
		����ũ�� ��������ִ�
		��� ���� �̴�



***********************************/

#include <iostream>
#include <algorithm>
#include <vector>

int main() 
{
#pragma region ����
	std::vector<int> v1;		// �� ���� ����
	std::vector<int> v2(10);	// 10���� Ÿ���� �⺻��(int�� ��� 0)���� �ʱ�ȭ �� ���� ����
	std::vector<int> v3(10, 5);	// 10���� ��Ҹ� 5�� �ʱ�ȭ�� ���� ����
	std::vector<int> v4 = {1,2,3,4,5,6,7,8,9,10};	// �ʱ�ȭ ����Ʈ�� ����� ���� ����

	std::cout << "���� v1�� ������ : " << v1.size() << std::endl;
	std::cout << "���� v2�� ������ : " << v2.size() << std::endl;
	std::cout << "���� v3�� ������ : " << v3.size() << std::endl;
	std::cout << "���� v4�� ������ : " << v4.size() << std::endl;

	
	std::cout << "===============================" << std::endl;

	// capacity() : ���� �Ҵ�� �޸𸮿��� ������ �� �ִ� �ִ� ���� ��
	std::cout << "������ v1�� capacity : " << v1.capacity() << std::endl;
	std::cout << "������ v2�� capacity : " << v2.capacity() << std::endl;
	std::cout << "������ v3�� capacity : " << v3.capacity() << std::endl;
	std::cout << "������ v4�� capacity : " << v4.capacity() << std::endl;


	std::cout << "===============================" << std::endl;

	v4.push_back(10);	// ������ ���� 10�� �߰�, vector�� capacity�� ������ ���� (���� capacity + ���� capacity * 0.5)�� �ȴ�
	std::cout << "���� v4�� ������ : " << v4.size() << std::endl;
	std::cout << "������ v4�� capacity : " << v4.capacity() << std::endl;

	std::vector<int> v5;
	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);
	std::cout << std::endl << "v5���" << std:: endl;
	for (int i = 0; i < v5.size(); i++) {
		std::cout << v5[i] << " ";
	}
	
	std::cout << std::endl << "v5���" << std::endl;

	std::vector<int> v6;
	v6.push_back(1);
	v6.push_back(2);
	v6.push_back(3);
	v6.push_back(4);
	v6.insert(v6.begin() + 1, 10);	// �ε��� 1�� 10�� �����Ѵ�
	v6.erase(v6.begin() + 3);		// �ε��� 3�� ��Ҹ� �����Ѵ�
	v6.pop_back();					// ������ ��� ����

	for (auto& i : v6) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
#pragma endregion

#pragma region ���� ��� for
	std::cout << std::endl << "===============���� ��� for===============" << std::endl;
	// ���� ��� for
	// �����̳��� ��� ��Ҹ� �����ϰ� ��ȸ.
	// �Ϲ� for���� �� ���� ��� ���������� �ڵ尡 �������� �� �ִ�.
	// Ư�� �����̳� �Ϻ� ��ȸ�� ��ƴ�. �ݺ��ڸ� ���������� ����Ѵ�
	// ���� ���·� �Ѱ����⿡ &(����) ���¸� �������

	for (int i : v5) {				// ����
		std::cout << i << " ";
	}

	std::cout << std::endl;

	for (int& i : v5) {				// ����
		std::cout << i << " ";
	}

	std::cout << std::endl;

	// auto : Ÿ�� �߷�
	// ������ Ÿ���� ����� �� �����ϴ�

	for (auto i : v5) {				// ������ �ڵ����� ���� ����
		std::cout << i << " ";
	}

	std::cout << std::endl;

	// ���� �������� �ʴ´ٸ� const�� ���
	for (const auto& i : v5) {			// ������ �ڵ����� ���� ����
		std::cout << i << " ";
	}
#pragma endregion

#pragma region iterator �ݺ���
	std::cout << std::endl<< "=============�ݺ���=============" << std::endl;
	std::vector<int> v7;
	v7.push_back(1);
	v7.push_back(2);
	v7.push_back(3);
	v7.push_back(4);
	v7.push_back(5);

	
	for (std::vector<int>::iterator it = v7.begin(); it != v7.end(); ++it) // for(iterator�� ��::iterator it = ������; �ݺ��� ����; ������), 
	{
		std::cout << *it << "->";
	}

	// ���ο��� ������ ���� ���ٸ�
	for (std::vector<int>::const_iterator it = v7.begin(); it != v7.end(); ++it) // for(iterator�� ��::iterator it = ������; �ݺ��� ����; ������), 
	{
		std::cout << *it << "->";
	}

	std::cout << std::endl << "===============================" << std::endl;

	std::vector<int> v8;
	v8.push_back(1);
	v8.push_back(2);
	v8.push_back(3);
	v8.push_back(4);
	v8.push_back(5);

	std::vector<int>::const_iterator iter = v8.begin();		// ���� ���Ҹ� ����Ű�� �ݺ���, �ʹ� ���

	for (std::vector<int>::reverse_iterator it = v8.rbegin(); it != v8.rend(); ++it) // for(iterator�� ��::iterator it = ������; �ݺ��� ����; ������), 
	{
		std::cout << *it << "->";
	}

	std::cout << std::endl << std::endl;

	std::vector<int> vec = { 10,20,30,40 };
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << "->";
	}
	std::cout << std::endl << std::endl;

	// �� ������ ������ Ȯ���غ���
	/*for (auto it = vec.rbegin(); it != vec.rend(); --it) {
		std::cout << *it << "->";
	}*/

	std::cout <<  "===============================" << std::endl;
	std::vector<int> vt;
	vt.push_back(10);
	vt.push_back(10);
	vt.push_back(10);
	vt.push_back(10);
	vt.push_back(10);
	vt.push_back(10);		// 3������ �������� �˾Ҵ�
	vt.push_back(10);

	vt.clear();
	std::cout << vt.size() << std::endl;
	std::cout << vt.capacity() << std::endl;		// clear�� �ص� �޸𸮻� �Ҵ��� ���� ũ�⸦ �����Ѵ�

	std::vector<int> emptyVector;
	vt.swap(emptyVector);
	std::cout << vt.capacity() << std::endl;		// �� ���ͷ� �ٲ������

	emptyVector.~vector();							// �Ҹ���
	std::cout << emptyVector.capacity() << std::endl;


#pragma endregion
}