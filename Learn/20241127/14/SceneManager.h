#pragma once
#include <map>
#include <iostream>
#include "Singleton.h"
template <typename T>
class SceneManager : public Singleton
{
public :
	SceneManager();
	~SceneManager();

	void AddScene(const std::string& name, const std::string& description);
	void SetScrrentScene(const std::string& name);
};

