/*
Ŭ������ Ȱ���Ͽ� ���¸� ĸ��ȭ �ϰ� ���°��� ��ȯ�� ���� ó���ϱ� ���� ���ǳ�
Ŭ������ ����ϴ� ���� ���� ������ �ֿ��� Ư¡�� �츮�µ� ������ �ȴ�.


*/
#include <iostream>

enum class State {
	ATTACK,
	RUN,
	JUMP
};

void RunState() {
	std::cout << "�޸��� �ִ�" << std::endl;
}

void JumpState() {
	std::cout << "���� ��" << std::endl;
}

void AttackState() {
	std::cout << "����" << std::endl;
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
	// CState��(��) ���� ��ӵ�
	void EnterState() override
	{
		std::cout << "���� ���� ����" << std::endl;
	}
	void InputEvent() override
	{
		std::cout << "�̺�Ʈ�� ����" << std::endl;
	}
	void Update() override
	{
		std::cout << "���� ������" << std::endl;
	}
	void ExitState() override
	{
		std::cout << "������ ������ �ٸ� ���·� �̵���" << std::endl;
	}
};

class CRunState : public CState {
	// CState��(��) ���� ��ӵ�
	void EnterState() override
	{
		std::cout << "�޸��� ���� ����" << std::endl;
	}
	void InputEvent() override
	{
		std::cout << "�޸��� ���� �̺�Ʈ�� ����" << std::endl;
	}
	void Update() override
	{
		std::cout << "�޸��� ������" << std::endl;
	}
	void ExitState() override
	{
		std::cout << "�޸��Ⱑ ������ �ٸ� ���·� �̵���" << std::endl;
	}
};

class CAttackState : public CState {
	// CState��(��) ���� ��ӵ�
	void EnterState() override
	{
		std::cout << "���� ���� ����" << std::endl;
	}
	void InputEvent() override
	{
		std::cout << "������ �̺�Ʈ�� ����" << std::endl;
	}
	void Update() override
	{
		std::cout << "���� ������" << std::endl;
	}
	void ExitState() override
	{
		std::cout << "������ ������ �ٸ� ���·� �̵���" << std::endl;
	}
};

class CIdle: public CState {
	// CState��(��) ���� ��ӵ�
	void EnterState() override
	{
		std::cout << "idle ���� ����" << std::endl;
	}
	void InputEvent() override
	{
		std::cout << "idle�� �̺�Ʈ�� ����" << std::endl;
	}
	void Update() override
	{
		std::cout << "idle ������" << std::endl;
	}
	void ExitState() override
	{
		std::cout << "idle�� ������ �ٸ� ���·� �̵���" << std::endl;
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