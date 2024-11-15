/*
포인터 배열
	말 그대로 포인터들의 배열(배열의 각 요소가 포인터)
	배열의 타입을 int, char 등등으로 하듯이 배열의 타입을 int* 으로 선언
	배열의 각각의 원소는 int를 가리키는 포인터 형으로 선언
	따라서 int 배열에서 각각의 원소를 int형 변수로 취급했던 것처럼 int* 배열에서 각각의 원소를 포인터로 취급할 수 있다

배열 포인터
	배열의 첫 번째 요소를 가리키는 포인터
	배열의 이름은 배열의 첫 번째 요소의 주소이므로 배열포인터를 사용하면 배열 요소에 쉽게 접근이 가능하다.

배열의 이름과 첫 번째 원소와의 관계
	배열의 이름은 첫 번째 원소를 가리키는 포인터라고 할 수 있나?
	엄밀히 따지면 첫 번째 원소의 주소와 같지만 배열의 이름 자체는 포인터가 아니다
	배열은 배열 자체의 데이터 구조, 포인터는 메모리의 주소를 가리키기 때문
	배열의 이름을 사용할 때 암묵적으로 배열의 첫 번째 원소를 가리키는 포인터로 타입 변화됨
	배열의 이름을 포인터처럼 사용할 수는 있지만 다른 개념이다.

상수 포인터
	1. 포인터 자체가 상수인 경우
		포인터가 가리키는 주소를 변경할 수 없지만, 그 주소에 저장된 값은 변경 가능

	2. 포인터가  가리키는 경우
		포인터가 가리키는 값을 변경할 수 없지만 포인터 자체는 다른 주소를 가리킬 수 있다


*/
#include <iostream> 

using namespace std;

//만약 배열을 받아서 두 숫자를 더하는 함수를 만든다면
int AddNum(int number[]) {	// 이 경우 매개변수가 배열의 포인터로 취급 된다

	return number[0] + number[1];
}

void AddArr(int number[], int number2[],int size) {
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		cout << number[i] << " + " << number2[i] << " = " << number[i] + number2[i] << endl;
	}
}

int main() {
	int* arr[3];	// 포인터 배열

	int num1 = 1;
	int num2 = 2;
	int num3 = 3;

	arr[0] = &num1;
	arr[1] = &num2;
	arr[2] = &num3;

	cout << "num1 : " << num1 << ", *arr[0] : " << *arr[0] << endl;
	cout << "num2 : " << num1 << ", *arr[1] : " << *arr[1] << endl;
	cout << "num3 : " << num1 << ", *arr[2] : " << *arr[2] << endl << endl;

	cout << &num1 << ", " << arr[0] << endl << endl;


	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* pArr;
	pArr = arr1;	// 배열의 시작 주소를 저장

	for (int i = 0; i < 10; i++) {
		cout << "arr[" << i << "] : " << &arr1[i];
		cout << " \t(pArr + " << i << ") 의 값" << " : " << (pArr + i) << "\n";

	}
	
	cout << endl << endl;

	int num = 10;
	int* const ptr = &num;	// 포인터 상수 : ptr이 가리키는 값은 변경 가능
	*ptr = 30;
	cout << *ptr << endl;
	int otherNum = 5;
	

	int val = 10;
	const int* ptr1 = &val;	// 상수 포인터 : 
	
	int otherNum1 = 5;

	ptr1 = &otherNum1;	// *ptr1 = 20 이런거 불가능

	int arr2[3] = {1,2,3};

	int k = AddNum(arr2);

	cout << k << endl << endl;


	const int size = 3;
	int arr3[size] = { 1,2,3 };
	int arr4[size] = { 4,5,6 };

	AddArr(arr3, arr4, size);
	

}