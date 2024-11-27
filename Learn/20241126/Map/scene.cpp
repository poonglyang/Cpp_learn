#include <iostream>

#include <map>

class Scene {

private:
	std::string desc;
public:
	Scene() :desc("") {}
	Scene(const std::string& desc) : desc(desc) {}

	std::string GetDesc() const {
		return desc;
	}
};

class SceneManager {
private:
	std::map<std::string, Scene*> scenes;

	Scene* currentScene;

	std::string currentSceneName;

public:
	SceneManager() : currentScene(nullptr), currentSceneName("") {}
	~SceneManager() {
		for (auto& pair : scenes) {
			delete pair.second;
		}
	}
public:
	void AddScene(const std::string & name, Scene * scene) {
		scenes[name] = scene;
	}

	void RemoveScene(const std::string& name) {
		auto it = scenes.find(name);		// �� �̸����� map���� ã��
		if (it != scenes.end()) {			// ������
			delete it->second;				// �����Ҵ�� �� ��ü �޸� ����
			scenes.erase(it);				// map���� �� ����
		}
	}

	void SetCurrnetScene(const std::string& name) {
		auto it = scenes.find(name);		// �� �̸����� map���� ã��
		if (it != scenes.end()) {			// ������
			currentScene = it->second;		// ����� ����
			currentSceneName = name;		// ����� �̸�����
		}
		else {

		}
	}

	void ShowCurrentScene() const {
		if (currentSceneName.empty()) {		// ���� ���� �������� �ʴ� ���
			std::cout << "���� ���� �����Ǿ� ���� ����" << std::endl;
			return;
		}
		std::cout << "���� �� : " << currentSceneName << "" << std::endl;
		std::cout << "�� ���� : " << currentScene->GetDesc() << std::endl;

	}
};

int main() {
	SceneManager* sceneManager = new SceneManager();

	sceneManager->AddScene("MainMenu", new Scene("���� �޴� : ���� ����"));
	sceneManager->AddScene("BattleMap1", new Scene("���� 1 : ù��° ���� ����"));

	sceneManager->SetCurrnetScene("MainMenu");
	sceneManager->ShowCurrentScene();

	std::cout << "���� ��ȯ�Ѵ�" << std::endl;

	sceneManager->SetCurrnetScene("BattleMap1");
	sceneManager->ShowCurrentScene();

	sceneManager->RemoveScene("BattleMap1");

	delete sceneManager;
	sceneManager = nullptr;

}