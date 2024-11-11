
/*
	자료형 (DataType)
		자료의 형태를 지정하는 것
		데이터가 메모리에 저장되는 형태와 처리되는 방식을 명시하는 역활
		0,1로만 구성된 컴퓨터에게 여러 형태의 자료를 저장하기 위함
	
	과제 1
		자료형에 대해 조사하시오.

	자료형이름			형태				크기(byte)		범위
	
	정수형
	short				정수
	int					정수
	long
	longlong
	unsigned (키워드가 무엇을 의미하는지 쓰시오) 0 미만이 없다


	실수형
	float
	double
	long double 

	논리형			논리
	bool			참과 거짓만 표현		1				false, true

	문자형
	char



	과제 2
		정수, 실수 변수를 선언하고 출력해보기

	과제 3
		자료형 크기 출력하기

	제출 방법
		개인 드라이브에 저장하기

*/

/*
	변수
	-	값을 저장할 수 있는 메모리 공간에 붙혀진 이름
	-	변수를 선언하면 메모리 공간이 할당되고, 할당된 메모리 공간에 이름이 붙는다.

	[변수의 이름]
	-	변수의 이름을 통해 할당된 메모리 공간에 접근이 가능하다.
	-	값 저장, 저장된 값 참조 가능

	[변수 선언시 주의사항]
	-	변수의 이름은 알파벳, 숫자, 언더스코어(_)로 구성
	-	대소문자를 구분함. num과 Num은 다른것이다
	-	변수의 이름은 숫자로 시작할 수 없다, 키워드도 변수의 이름으로 사용할 수 없다(예약어 되겠냐)
	-	공백이 삽입 될 수 없다
	-	변수의 이름에 특수문자는 불가하다
	-	영어로 해줘..
	-	다른 사람이 변수명을 보고 무엇인지 알게 하라(의미 있는 이름으로 하라)
*/


#include <iostream> 
int main() {
	std::cout << "short형의 크기 : " << sizeof(int) <<std::endl;
	std::cout << "unsigned short형의 크기 : " << sizeof(unsigned short) << std::endl;
	std::cout << "int형의 크기 : " << sizeof(int) << std::endl;
	std::cout << "unsigned int형의 크기 : " << sizeof(unsigned int) << std::endl;
	std::cout << "long형의 크기 : " << sizeof(long) << std::endl;
	std::cout << "unsigned long형의 크기 : " << sizeof(unsigned long) << std::endl;
	std::cout << "long long형의 크기 : " << sizeof(long long) << std::endl;
	std::cout << "unsigned long long형의 크기 : " << sizeof(unsigned long long) << std::endl;

	// 데이터 타입은 int형이고 num 변수를 선언하였다.
	// 초기화(변수에 값을 지정)되지 않으면 사용할 수 없다.
	// 두 단어 이상을 조합해 변수를 지정할 때는 2번째 단어의 이름은 대문자로 한다 (회사마다 다름)
	int testNum1 = 3.14;	// 선언과 동시에 초기화

	int testNum2;			// 선언하고 
	testNum2 = 10;			// 초기화
	std::cout << testNum1 << ", " << testNum2 << std::endl;

}