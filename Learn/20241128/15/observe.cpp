/*
[observer Parttern] ������ ����
	��ü�� �Ǵ� ��ü�� ���°� ������ �� �� �ش� ���¸� �����ϴ� ��������� ��ü���� �ڵ����� �˷��ش�
	���������� ���¿� ���� �����ϴ� ��
	���º�ȭ�� �Ǵ� �ý����̳� �̺�Ʈ ���, ���� - �˸� �ý��ۿ� �����ϰ� ����

	��ü
		���¸� ������ ������ ��ȭ�� ���� �� ���������� �˸��� ��Ȱ ���������� ����ϰų� �����ϴ� �޼��带 ����

	������
		��ü�� ���¸� �����ϴ� ��ü
		��ü�� ���°� ����Ǹ� �ڵ����� �����ް� ������

	��
		����Ʈ �ý��ۿ��� ������ �÷��̾ Ư�� ����Ʈ�� �����ϸ鼭 ���°� ����� ������ ����Ʈ ���� ��Ȳ�� �����ϴ� �������� ����
		�������� ui���� ����Ʈ�� �����Ȳ�� ǥ���ϰų� npc�� �ý��ۿ��� ��ȭ�� �ݿ��ϴ� ������� ���� ����

		������ �÷��̾ ����Ʈ�� �����ϸ� ��ȭ�Ǵ� ���� �����ϴ� ���� ��ü���� �ڵ����� ������Ʈ �ǰ� ��
*/

#include <iostream>
#include <vector>

/// <summary>
/// ������ �������̽�
/// </summary>
class Observer {
public :
	virtual void Update(const std::string& questState) = 0;

	virtual ~Observer() = default;
};

/// <summary>
/// ��ü
/// </summary>
class Subject {
public:
	virtual void Attach(Observer* observer) = 0;	// ���
	virtual void Detach(Observer* observer) = 0;	// ����
	virtual void Notify() = 0;	// ���������� �˷��ִ� ��
	virtual ~Subject() = default;
};

class QuestSystem : public Subject {
private:
	std::vector<Observer*> observers;
	std::string questStatus;

public:
	void Attach(Observer* observer) override {
		observers.push_back(observer);				// ���� �������� observers ���Ϳ� ����
	}

	void Detach(Observer* observer) override
	{
		auto it = std::find(observers.begin(), observers.end(), observer);	// ���Ϳ��� �������� ã���� �������� ��ȯ�ϰ� ������ end ��ȯ
		
		if (it != observers.end()) {
			observers.erase(it);			// ã�� �������� ������ ������
		}
	}

	void Notify() override
	{
		for (Observer* observer : observers) {
			observer->Update(questStatus);
		}
	}

	void SetQuestStatus(const std::string& status) {
		questStatus = status;
		Notify();
	}

	std::string GetQuestStatus() const {
		return questStatus;
	}

};

class QuestUI : public Observer {
	// Observer��(��) ���� ��ӵ�
	void Update(const std::string& questState) override
	{
		std::cout << "UI ����Ʈ ���°� ����� " << questState << std::endl;
	}
};

class QuestLog : public Observer {
	// Observer��(��) ���� ��ӵ�
	void Update(const std::string& questState) override
	{
		std::cout << "����Ʈ �α׿� ��� " << questState << std::endl;
	}
};

class NPC : public Observer {
private:
	std::string name;
public:
	NPC(const std::string name) : name(name) {

	}

	void Update(const std::string& questState) override
	{
		std::cout << "NPC�� ����Ʈ ���¸� Ȯ���� : " << questState << std::endl;
	}
};

int main() {
	QuestSystem qs;
	QuestUI ui;
	QuestLog log;
	NPC npc("��μ�");

	qs.Attach(&ui);
	qs.Attach(&log);
	qs.Attach(&npc);

	std::cout << "����Ʈ ���� : ����" << std::endl;
	qs.SetQuestStatus("����Ʈ ����");
	std::cout << "����Ʈ ���� : �Ϸ�" << std::endl;
	qs.SetQuestStatus("����Ʈ ���� : �Ϸ�");
}