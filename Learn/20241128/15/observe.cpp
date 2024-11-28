/*
[observer Parttern] 옵저버 패턴
	주체가 되는 객체의 상태가 변경이 될 때 해당 상태를 관찰하는 옵저버라는 객체에게 자동으로 알려준다
	옵저버들이 상태에 따라 반응하는 것
	상태변화가 되는 시스템이나 이벤트 기반, 구독 - 알림 시스템에 적합하게 쓰임

	주체
		상태를 가지며 상태의 변화가 있을 때 옵저버에게 알리는 역활 옵저버들을 등록하거나 제거하는 메서드를 제공

	옵저버
		주체의 상태를 관찰하는 객체
		주체의 상태가 변경되면 자동으로 통지받고 반응함

	예
		퀘스트 시스템에서 게임의 플레이어가 특정 퀘스트를 진행하면서 상태가 변경될 때마다 퀘스트 진행 상황을 추적하는 옵저버가 받음
		옵저버는 ui에서 퀘스트의 진행상황을 표시하거나 npc나 시스템에서 변화를 반영하는 방식으로 동작 가능

		게임의 플레이어가 퀘스트를 진행하며 변화되는 것을 추적하는 여러 객체들이 자동으로 업데이트 되게 함
*/

#include <iostream>
#include <vector>

/// <summary>
/// 옵저버 인터페이스
/// </summary>
class Observer {
public :
	virtual void Update(const std::string& questState) = 0;

	virtual ~Observer() = default;
};

/// <summary>
/// 주체
/// </summary>
class Subject {
public:
	virtual void Attach(Observer* observer) = 0;	// 등록
	virtual void Detach(Observer* observer) = 0;	// 제거
	virtual void Notify() = 0;	// 옵저버에게 알려주는 것
	virtual ~Subject() = default;
};

class QuestSystem : public Subject {
private:
	std::vector<Observer*> observers;
	std::string questStatus;

public:
	void Attach(Observer* observer) override {
		observers.push_back(observer);				// 받은 옵저버를 observers 백터에 넣음
	}

	void Detach(Observer* observer) override
	{
		auto it = std::find(observers.begin(), observers.end(), observer);	// 백터에서 옵저버를 찾으며 옵저버를 반환하고 없으면 end 반환
		
		if (it != observers.end()) {
			observers.erase(it);			// 찾는 옵저버가 있으면 삭제함
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
	// Observer을(를) 통해 상속됨
	void Update(const std::string& questState) override
	{
		std::cout << "UI 퀘스트 상태가 변경됨 " << questState << std::endl;
	}
};

class QuestLog : public Observer {
	// Observer을(를) 통해 상속됨
	void Update(const std::string& questState) override
	{
		std::cout << "퀘스트 로그에 기록 " << questState << std::endl;
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
		std::cout << "NPC가 퀘스트 상태를 확인함 : " << questState << std::endl;
	}
};

int main() {
	QuestSystem qs;
	QuestUI ui;
	QuestLog log;
	NPC npc("김민수");

	qs.Attach(&ui);
	qs.Attach(&log);
	qs.Attach(&npc);

	std::cout << "퀘스트 변경 : 시작" << std::endl;
	qs.SetQuestStatus("퀘스트 시작");
	std::cout << "퀘스트 변경 : 완료" << std::endl;
	qs.SetQuestStatus("퀘스트 변경 : 완료");
}