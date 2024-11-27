/*
클래스를 활용하여 상태를 캡슐화 하고 상태간의 전환을 쉽게 처리하기 위해 사용되낟
클래스를 사용하는 것이 상태 패턴의 주요한 특징을 살리는데 도움이 된다.


*/
#include <iostream>

enum class State {
	ATTACK,
	RUN,
	JUMP
};

void RunState() {
	std::cout << "달리고 있다" << std::endl;
}

void JumpState() {
	std::cout << "점프 중" << std::endl;
}

void AttackState() {
	std::cout << "공격" << std::endl;
}


class CState {
private:

public:
	virtual void EnterState() = 0;
	virtual void InputEvent() = 0;
	virtual void Update() = 0;
	virtual void ExitState() = 0;
};

class CJumpState : public CState {
	// CState을(를) 통해 상속됨
	void EnterState() override
	{
		std::cout << "점프 상태 진입" << std::endl;
	}
	void InputEvent() override
	{
		std::cout << "이벤트가 들어옴" << std::endl;
	}
	void Update() override
	{
		std::cout << "점프 도중임" << std::endl;
	}
	void ExitState() override
	{
		std::cout << "점프가 끝나고 다른 상태로 이동함" << std::endl;
	}
};

class CRunState : public CState {
	// CState을(를) 통해 상속됨
	void EnterState() override
	{
		std::cout << "달리는 상태 진입" << std::endl;
	}
	void InputEvent() override
	{
		std::cout << "달리는 도중 이벤트가 들어옴" << std::endl;
	}
	void Update() override
	{
		std::cout << "달리는 도중임" << std::endl;
	}
	void ExitState() override
	{
		std::cout << "달리기가 끝나고 다른 상태로 이동함" << std::endl;
	}
};

class CAttackState : public CState {
	// CState을(를) 통해 상속됨
	void EnterState() override
	{
		std::cout << "공격 상태 진입" << std::endl;
	}
	void InputEvent() override
	{
		std::cout << "공격중 이벤트가 들어옴" << std::endl;
	}
	void Update() override
	{
		std::cout << "공격 도중임" << std::endl;
	}
	void ExitState() override
	{
		std::cout << "공격이 끝나고 다른 상태로 이동함" << std::endl;
	}
};

class CIdle: public CState {
	// CState을(를) 통해 상속됨
	void EnterState() override
	{
		std::cout << "idle 상태 진입" << std::endl;
	}
	void InputEvent() override
	{
		std::cout << "idle중 이벤트가 들어옴" << std::endl;
	}
	void Update() override
	{
		std::cout << "idle 도중임" << std::endl;
	}
	void ExitState() override
	{
		std::cout << "idle이 끝나고 다른 상태로 이동함" << std::endl;
	}
};

class Character {
private :
	CState* currentState;

public:
	Character() {
		currentState = new CIdle();
	}

	void SetCurrentState(CState* s) {
		currentState->ExitState();
		
		currentState = s;

		currentState->EnterState();
	}

	void InputEvent() {
		currentState->InputEvent();
	}

	void Update() {
		currentState->Update();
	}
};

int main() {
	Character c;
	c.InputEvent();
	c.Update();
	std::cout << std::endl;
	c.SetCurrentState(new CAttackState());
}