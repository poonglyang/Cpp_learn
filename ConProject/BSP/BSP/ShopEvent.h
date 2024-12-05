#include "Event.h"

#pragma once
class ShopEvent : public Event
{
	// Event��(��) ���� ��ӵ�
private:
	ItemManager itemManager; 

	Inventory shopInventory;

	void EventUpdate() override;
	void EventEnd() override;
	void RenderEvent() override;
public:
	void EventStart(Player* player) override;
	ShopEvent();
};

