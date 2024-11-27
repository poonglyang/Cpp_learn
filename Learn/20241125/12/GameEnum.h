#pragma once

namespace GameEnums {

	enum class ItemType {
		ITEM_EMPTY,
		ITEM_ARMOR,
		ITEM_WEAPON,
		ITEM_RING,
		ITEM_POTION,
		ITEM_SOLDOUT
	};

	enum class Location {
		LOCATION_SHOP = 1,
		LOCATION_SELL_INVENTORY,
		LOCATION_INVENTORY
	};
}