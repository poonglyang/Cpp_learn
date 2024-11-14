#include <iostream>
#include <algorithm>

/*
2차원 배열도 메모리 구조상 직선이다

*/

int main() {
	//int arr[4][3];

	//arr[0][0] = 1;
	//arr[0][1] = 2;
	//arr[0][2] = 3;

	//arr[1][0] = 4;
	//arr[1][1] = 5;
	//arr[1][2] = 6;

	//arr[2][0] = 7;
	//arr[2][1] = 8;
	//arr[2][2] = 9;

	//arr[3][0] = 10;
	//arr[3][1] = 11;
	//arr[3][2] = 12;

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << arr[i][j] << "\t";
	//	}
	//	std::cout << std::endl;
	//}

	//std::cout << std::endl;

	//int arr2[4][3] = {
	//	{1,2,3},
	//	{4,5,6},
	//	{7,8,9},
	//	{10,11,12}
	//};

	//int arr3[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	//for (int i = 0; i < 4; i++) {
	//	for (int k = 0; k < 3; k++) {
	//		std::cout << arr3[i][k];
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;

	//// 2중 배열을 사용하여
	//// 각 아파트에는 사람이 살고 있다
	//// 각 층에는 3개의 호실만 존재하고 3층까지 있다
	//// 각 층 각 호의 가족이 몇명 사는지 입력받고 아프트에 총 몇명이 살고 있는지 합을구하라

	//int apt[3][3];
	//int total = 0;

	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << i + 1 << "층 " << i+1  << "0" << j+1 << "호에는 몇명이 살고 있나요? : ";
	//		std::cin >> apt[i][j];
	//	}
	//}

	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		total += apt[i][j];
	//	}
	//}

	//std::cout << "아파트에는 총 " << total << "명이 살고 있습니다" << std::endl;


	char name[6] = "hello";
	// 컴퓨터의 문자열은 마지막을 나타내는 null을 자동으로 추가하기에 helloa를 outofrange가 난다

	std::cout << name << std::endl;

	char name1[] = { 'h','e','l','l','o','\0'};		// 이렇게 선언을 하면 자동으로 null문자가 삽입되지 않기 때문에 뒤가 이상하게 뜬다
													// 수동으로 null(\0)을 넣으면 된다

	std::cout << std::endl << std::endl << name1;

	for (int i = 0; i < 5; i++) {
		std::cout << name1[i];
	}

	std::cout << std::endl << std::endl;
	std::string s = "이게 당근 더 편함";

	// const char* : 문자열의 시작 주소를 가르킨다
	const char* str = "hello";

	std::cout << str << std::endl;
	std::cout << &str << std::endl;
	std::cout << &str[0]  << std::endl;

	/*
	hello : 

	주소 :	1000, 1001, 1002, 1003, 1004, 1005
	값 :		h	  e	    l	  l		o	  \0
	
	
	*/

	const char* str3 = "abce";
	std::cout << &str3 << std::endl;

	str3 = "efgh";
	std::cout << &str3 << std::endl;


	const char* const str2 = "aaa";
	

	/*
	const char * a = "Hello" 랑
		문자열이 저장된 메모리 주소를 가리키는 포인터를 선언
		포인터 자체는 상수가 아니지만 가리키는 대상은 상수

	const char ab[] = "ddd"의 차이점은 무엇인가


	
	
	*/
}