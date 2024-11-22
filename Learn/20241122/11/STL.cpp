/***********************************
STL(스텐다드 템플릿 라이브러리 (표준 템플릿 라이브러리))
	* 반드시 알아야함
	프로그램에 필요한 자료구조와 알고리즘을 템플릿으로 제공하는 라이브러리
	#include <list> #include <queue> #include <vector> #include <algorithm> 등

	구성 요소
		컨테이너
			객체를 보관하는 객체 (일종의 커다란 창고). 
			클래스 템플릿 형태로 구현되어 있음
			각각의 원소에 접근할 수 있도록 다양한 맴버함수를 제공

			시퀀스 컨테이너
				선형적 구조
				컨테이너 원소가 자신만의 삽입 위치를 가지는 컨테이너

				vector(배열 기반), list(노드 기반), deque(배열 기반)

			연관 컨테이너
				비선형 구조
				저장 원소가 삽입 순서와는 다르게 특정 정렬 기준에 의해 자동정렬 되는 컨테이너

				set(노드 기반), multiset(노드 기반), map(노드 기반), multimap(노드 기반)
		
		이터레이터 (반복자)
			포인터와 비슷한 개념
			컨테이너의 원소를 가리키고 가리키는 원소에 접근하여 다음 원소를 가리키게 하는 기능

		
		알고리즘
			정렬 삭제 검색 등을 해결하는 일반화된 방법을 제공하는 함수 템플릿

	Vector
		순차적으로 저장된다(메모리상)
		내부적으로 동적 배열을 사용해 크기를 자동으로 조절
		인덱스를 통해 임의 원소에 접근 가능(배열의 [], 멤버함수인 at)
			-> 접근이 빠르다
		중간 삽입 삭제가 빈번하게 일어나면 속도가 느려진다
			중간에 있는 값을 삭제할 경우 배열에 있는 값들을 한칸씩 당긴다
				(1억개의 데이터가 있는 Vector에 5번째 것을 삭제하면 9999만 9995번의 당김이 생긴다)
			중간에 값을 삽입하면 배열에 있는 값들을 한칸씩 민다
				(1억개의 데이터가 있는 Vector에 5번째에 삽입하면 9999만 9995번의 밀기가 생긴다)
		뒤 부터 체운다

		맴버 함수들
			empty()	: 백터가 비어 있는지 확인
			clear()	: 벡터의 모든 요소 제거
			at()	: 백터의 요소에 접근하며 범위 검사(예외처리) 함
			front()	: 벡터의 첫 번째 요소 반환
			back()	: 벡터의 마지막 요소 반환
			push_back()	: 벡터의 끝에 요소 추가
			pop_back()	: 벡터의 끝에서 요소를 제거
			erase()	: 지정한 위치의 요소를 제거
			reserve	: 벡터의 용량을 지정
			shrink_to_fit()	: 벡터의 현재 크기에 맞기 줄임
			swap()	: 두 벡터를 교환

	list
		더블링크로 만들어져있다
		노드 단위 이다



***********************************/

#include <iostream>
#include <algorithm>
#include <vector>

int main() 
{
#pragma region 백터
	std::vector<int> v1;		// 빈 백터 생성
	std::vector<int> v2(10);	// 10개의 타입의 기본값(int의 경우 0)으로 초기화 한 백터 생성
	std::vector<int> v3(10, 5);	// 10개의 요소를 5로 초기화한 백터 생성
	std::vector<int> v4 = {1,2,3,4,5,6,7,8,9,10};	// 초기화 리스트를 사용한 백터 생성

	std::cout << "백터 v1의 사이즈 : " << v1.size() << std::endl;
	std::cout << "백터 v2의 사이즈 : " << v2.size() << std::endl;
	std::cout << "백터 v3의 사이즈 : " << v3.size() << std::endl;
	std::cout << "백터 v4의 사이즈 : " << v4.size() << std::endl;

	
	std::cout << "===============================" << std::endl;

	// capacity() : 현재 할당된 메모리에서 저장할 수 있는 최대 원소 수
	std::cout << "백터의 v1의 capacity : " << v1.capacity() << std::endl;
	std::cout << "백터의 v2의 capacity : " << v2.capacity() << std::endl;
	std::cout << "백터의 v3의 capacity : " << v3.capacity() << std::endl;
	std::cout << "백터의 v4의 capacity : " << v4.capacity() << std::endl;


	std::cout << "===============================" << std::endl;

	v4.push_back(10);	// 백터의 끝에 10을 추가, vector의 capacity가 증가할 때는 (지금 capacity + 지금 capacity * 0.5)가 된다
	std::cout << "백터 v4의 사이즈 : " << v4.size() << std::endl;
	std::cout << "백터의 v4의 capacity : " << v4.capacity() << std::endl;

	std::vector<int> v5;
	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);
	std::cout << std::endl << "v5출력" << std:: endl;
	for (int i = 0; i < v5.size(); i++) {
		std::cout << v5[i] << " ";
	}
	
	std::cout << std::endl << "v5출력" << std::endl;

	std::vector<int> v6;
	v6.push_back(1);
	v6.push_back(2);
	v6.push_back(3);
	v6.push_back(4);
	v6.insert(v6.begin() + 1, 10);	// 인덱스 1에 10을 삽입한다
	v6.erase(v6.begin() + 3);		// 인덱스 3의 요소를 제거한다
	v6.pop_back();					// 마지막 요소 제거

	for (auto& i : v6) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
#pragma endregion

#pragma region 범위 기반 for
	std::cout << std::endl << "===============범위 기반 for===============" << std::endl;
	// 범위 기반 for
	// 컨테이너의 모든 요소를 간단하게 순회.
	// 일반 for문을 더 많은 제어를 제공하지만 코드가 복잡해질 수 있다.
	// 특정 조건이나 일부 순회는 어렵다. 반복자를 내부적으로 사용한다
	// 복사 형태로 넘겨지기에 &(참조) 형태를 사용하자

	for (int i : v5) {				// 복사
		std::cout << i << " ";
	}

	std::cout << std::endl;

	for (int& i : v5) {				// 참조
		std::cout << i << " ";
	}

	std::cout << std::endl;

	// auto : 타입 추론
	// 복잡한 타입을 사용할 때 유용하다

	for (auto i : v5) {				// 형식을 자동으로 지정 복사
		std::cout << i << " ";
	}

	std::cout << std::endl;

	// 값이 수정되지 않는다면 const좀 써라
	for (const auto& i : v5) {			// 형식을 자동으로 지정 참조
		std::cout << i << " ";
	}
#pragma endregion

#pragma region iterator 반복자
	std::cout << std::endl<< "=============반복자=============" << std::endl;
	std::vector<int> v7;
	v7.push_back(1);
	v7.push_back(2);
	v7.push_back(3);
	v7.push_back(4);
	v7.push_back(5);

	
	for (std::vector<int>::iterator it = v7.begin(); it != v7.end(); ++it) // for(iterator할 것::iterator it = 시작점; 반복할 조건; 증감값), 
	{
		std::cout << *it << "->";
	}

	// 내부에서 수정할 일이 없다면
	for (std::vector<int>::const_iterator it = v7.begin(); it != v7.end(); ++it) // for(iterator할 것::iterator it = 시작점; 반복할 조건; 증감값), 
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

	std::vector<int>::const_iterator iter = v8.begin();		// 시작 원소를 가리키는 반복자, 너무 길다

	for (std::vector<int>::reverse_iterator it = v8.rbegin(); it != v8.rend(); ++it) // for(iterator할 것::iterator it = 시작점; 반복할 조건; 증감값), 
	{
		std::cout << *it << "->";
	}

	std::cout << std::endl << std::endl;

	std::vector<int> vec = { 10,20,30,40 };
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << "->";
	}
	std::cout << std::endl << std::endl;

	// 왜 에러가 나는지 확인해보자
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
	vt.push_back(10);		// 3단위로 생성됨을 알았다
	vt.push_back(10);

	vt.clear();
	std::cout << vt.size() << std::endl;
	std::cout << vt.capacity() << std::endl;		// clear를 해도 메모리상 할당은 기존 크기를 유지한다

	std::vector<int> emptyVector;
	vt.swap(emptyVector);
	std::cout << vt.capacity() << std::endl;		// 빈 백터로 바꿔버린다

	emptyVector.~vector();							// 소멸자
	std::cout << emptyVector.capacity() << std::endl;


#pragma endregion
}