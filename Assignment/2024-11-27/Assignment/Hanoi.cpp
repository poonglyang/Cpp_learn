#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Hanoi {
private:
	/// <summary>
	/// 기둥 1
	/// </summary>
	stack<int> pillar1;

	/// <summary>
	/// 기둥 2
	/// </summary>
	stack<int> pillar2;

	/// <summary>
	/// 기둥 3
	/// </summary>
	stack<int> pillar3;

public:

	void InputPillar1(int diskNum) {
		if (pillar1.empty()) {
			// 기둥에 원반이 아에 없다면
			pillar1.push(diskNum);
			return;
		}

		if (pillar1.top() < diskNum) {
			// 스택의 가장 앞에 있는 것보다 들어올려는게 크다면 들어갈 수 없다
			cout << "아래 원반보다 큰 원반은 넣을 수 없습니다" << endl;
			return;
		}
		else {
			pillar1.push(diskNum);
		}
	}

	void InputPillar2(int diskNum) {
		if (pillar2.empty()) {
			// 기둥에 원반이 아에 없다면
			pillar2.push(diskNum);
			return;
		}
		if (pillar2.top() < diskNum) {
			// 스택의 가장 앞에 있는 것보다 들어올려는게 크다면 들어갈 수 없다
			cout << "아래 원반보다 큰 원반은 넣을 수 없습니다" << endl;
			return;
		}
		else {
			pillar2.push(diskNum);
		}
	}

	void InputPillar3(int diskNum) {
		if (pillar3.empty()) {
			// 기둥에 원반이 아에 없다면
			pillar3.push(diskNum);
			return;
		}
		if (pillar3.top() < diskNum) {
			// 스택의 가장 앞에 있는 것보다 들어올려는게 크다면 들어갈 수 없다
			cout << "아래 원반보다 큰 원반은 넣을 수 없습니다" << endl;
			return;
		}
		else {
			pillar3.push(diskNum);
		}
	}
	//cout << fromPiller << "에서 " << toPiller << "로 " << pop << "원반 이동" << endl;
	void MoveDisk(int fromPiller, int toPiller) {
		int pop;
		switch (fromPiller)
		{
		case 1:
			pop = pillar1.top();
			pillar1.pop();
			
			switch (toPiller)
			{
			case 2:
				InputPillar2(pop);
				break;

			case 3:
				InputPillar3(pop);
				break;
			}
			break;
		case 2:
			pop = pillar2.top();
			pillar2.pop();
			switch (toPiller) {
			case 1:
				InputPillar1(pop);
				break;

			case 3:
				InputPillar3(pop);
				break;
			}
			break;
		case 3:
			pop = pillar3.top();
			pillar3.pop();
			switch (toPiller) {
			case 1:
				InputPillar1(pop);
				break;
			case 2:
				InputPillar2(pop);
				break;
			}
			break;
		}
	}

	void PrintPillar() {
		stack<int> temp1 = pillar1;

		stack<int> temp2;

		//cout << "[원반은 위에 있는 것부터 출력 됩니다]" << endl;
		cout << "[기둥 1] : ";

		while (!temp1.empty()) {
			temp2.push(temp1.top());
			temp1.pop();
		}

		while (!temp2.empty()) {
			cout << temp2.top() << " ";
			temp2.pop();
		}

		cout << endl;

		temp1 = pillar2;
		cout << "[기둥 2] : ";
		while (!temp1.empty()) {
			temp2.push(temp1.top());
			temp1.pop();
		}

		while (!temp2.empty()) {
			cout << temp2.top() << " ";
			temp2.pop();
		}
		
		cout << endl;

		temp1 = pillar3;
		cout << "[기둥 3] : ";
		while (!temp1.empty()) {
			temp2.push(temp1.top());
			temp1.pop();
		}

		while (!temp2.empty()) {
			cout << temp2.top() << " ";
			temp2.pop();
		}

		cout << endl;
	}

	int GetPillarTop(int pillarNum) {
		switch (pillarNum) {
		case 1:
			return pillar1.top();
		case 2:
			return pillar2.top();
		case 3:
			return pillar3.top();
		}
	}

};

void H(int diskNum, int fromPillar, int extraPiller, int toPillar, Hanoi* h) {

	if (diskNum == 0) {
		return;
	}

	H(diskNum - 1, fromPillar, toPillar, extraPiller, h);
	cout << endl;
	cout << fromPillar << "에서 " << toPillar << "로 " << h->GetPillarTop(fromPillar) << "이동" << endl;
	h->MoveDisk(fromPillar, toPillar);
	h->PrintPillar();
	H(diskNum - 1, extraPiller, fromPillar, toPillar, h);
}



int main() {
	Hanoi* h = new Hanoi();

	int diskCount;
	cout << "넣을 원반의 갯수를 입력하세요 : ";
	cin >> diskCount;

	for (int i = diskCount; i > 0; --i) {
		h->InputPillar1(i);
	}

	h->PrintPillar();


	H(diskCount, 1, 2, 3, h);


}