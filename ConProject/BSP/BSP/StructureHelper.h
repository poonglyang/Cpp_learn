#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <queue>
#include "Node.h"

namespace StructureHelper {

	

	static enum class Orientation {
		Horiszontal,
		Vertical
	};

	static enum class RelativePosition
	{
		Up,
		Down,
		Right,
		Left
	};

	/// <summary>
	/// Ʈ���� ���� �����ϴ� �Լ�
	/// </summary>
	/// <param name="parentNode"></param>
	/// <returns></returns>
	static std::vector<Node*> TraverseGraphToExtractLowestLeafes
	(Node* parentNode)
	{
		std::queue<Node*> nodesToCheck;
		std::vector<Node*> listToReturn;

		if (parentNode->childrenNode.size() == 0) {
			listToReturn.push_back(parentNode);
			return listToReturn;
		}

		for (auto* child : parentNode->childrenNode) {
			nodesToCheck.push(child);
		}

		while (!nodesToCheck.empty()) {
			Node* currentNode = nodesToCheck.front();
			nodesToCheck.pop();
			if (currentNode->childrenNode.empty()) {
				listToReturn.push_back(currentNode);
			}
			else {
				for (int i = 0; i < currentNode->childrenNode.size(); i++) {
					Node* temp = currentNode->childrenNode[i];
					nodesToCheck.push(temp);
				}

				//for (auto* child : currentNode->childrenNode) {
				//	nodesToCheck.push(child);
				//}
			}
		}

		return listToReturn;
	}

	/// <summary>
	/// ���ϴ� �ڳ� ��ǥ�� ����� �Լ�
	/// </summary>
	/// <param name="boundrayLeftPoint">����� ���ϴ� ��ǥ</param>
	/// <param name="boundrayRightPoint">����� ���� ��ǥ</param>
	/// <param name="pointModifire">���� ����( 0�� ������ minX�� minY�� 1�� ������ maxX�� maxY�� ������ ����)</param>
	/// <param name="offset">���� ����</param>
	/// <returns>���ϴ� �ڳ�</returns>
	static Vector2Int GenerateBottomLeftCornerBetween(
		Vector2Int boundrayLeftPoint,
		Vector2Int boundrayRightPoint,
		double pointModifire, int offset) 
	{
		int minX = boundrayLeftPoint.x + offset;
		int maxX = boundrayRightPoint.x - offset;

		int minY = boundrayLeftPoint.y + offset;
		int maxY = boundrayRightPoint.y - offset;

		return Vector2Int(
			Mathf::Random::Range(minX, (int)(minX + (maxX - minX) * pointModifire)),
			Mathf::Random::Range(minY, (int)(minY + (maxY - minY) * pointModifire))
		);
	}


	static Vector2Int GenerateTopRightCornerBetween(
		Vector2Int boundrayLeftPoint, 
		Vector2Int boundrayRightPoint, 
		float pointModifire, int offset) 
	{
		int minX = boundrayLeftPoint.x + offset;
		int maxX = boundrayRightPoint.x - offset;

		int minY = boundrayLeftPoint.y + offset;
		int maxY = boundrayRightPoint.y - offset;

		return Vector2Int(
			Mathf::Random::Range((int)(minX + (maxX - minX) * pointModifire), maxX),
			Mathf::Random::Range((int)(minY + (maxY - minY) * pointModifire), maxY)
		);
	}


	static Vector2Int CalculateMiddlePoint(
		Vector2Int v1, Vector2Int v2) {
		Vector2 sum = Vector2(v1.x, v1.y) + Vector2(v2.x, v2.y);             // �� ���� ���ϰ�~
		Vector2 tempVector = sum * 0.5;   // �� ���� ������~
		return Vector2Int((int)tempVector.x, (int)tempVector.y);    // �� �� ��ȯ �ϱ�~
	}

	
}

namespace playHelper {

	static struct Map {
		int mapArr[51][51] = { 0 };
	};

	static struct DungeonFloor {
		std::vector<Node*> rooms;

		std::vector<Node*> cooridorVector;

		Map map;
	};

	static enum class EventEnum {
		SHOP_EVENT,
		WELL_EVENT,
		ANGEL_STATUES_EVENT,
		DEVIL_STATUES_EVENT,
		BOX_EVENT,
		MONSTER_EVENT
	};

	static Map CreateMap(std::vector<Node*> rooms, std::vector<Node*> cooridorVector) {
		Map map;
		for (Node* cooridor : cooridorVector) {
			for (int i = cooridor->GetBottomLeftCorner().x; i <= cooridor->GetBottomRightCorner().x; i++) {
				map.mapArr[cooridor->GetBottomLeftCorner().y][i] = 7;
				map.mapArr[cooridor->GetTopLeftCorner().y][i] = 7;
			}

			for (int j = cooridor->GetBottomLeftCorner().y; j <= cooridor->GetTopLeftCorner().y; j++) {
				map.mapArr[j][cooridor->GetBottomLeftCorner().x] = 7;
				map.mapArr[j][cooridor->GetBottomRightCorner().x] = 7;
			}
		}

		for (Node* room : rooms) {

			std::vector<std::pair<int, int>> notWall;

			// ���� �� ġ��
			for (int i = room->GetBottomLeftCorner().x; i <= room->GetBottomRightCorner().x; i++) {

				if (map.mapArr[room->GetBottomLeftCorner().y][i] == 7) {
					// ���� ������ ���̿�����
					notWall.push_back(std::pair<int, int>(room->GetBottomLeftCorner().y, i)); // ���� �ƴԿ� �־��ְ� (���̶� ���Ʊ� ����)
					map.mapArr[room->GetBottomLeftCorner().y][i] = 0;	// 
				}
				else
				{
					bool canWall = true;
					for (std::pair<int, int> point : notWall) {
						if (point.first == room->GetBottomLeftCorner().y && point.second == i) {
							canWall = false;
							break;
						}
					}
					if (canWall) {
						map.mapArr[room->GetBottomLeftCorner().y][i] = 7;
					}
				}

				if (map.mapArr[room->GetTopLeftCorner().y][i] == 7) {
					notWall.push_back(std::pair<int, int>(room->GetTopLeftCorner().y, i));
					map.mapArr[room->GetTopLeftCorner().y][i] = 0;
				}
				else {
					bool canWall = true;
					for (std::pair<int, int> point : notWall) {
						if (point.first == room->GetTopLeftCorner().y && point.second == i) {
							canWall = false;
							break;
						}
					}
					if (canWall) {
						map.mapArr[room->GetTopLeftCorner().y][i] = 7;
					}

				}

			}


			// ���� �� ġ��
			for (int j = room->GetBottomLeftCorner().y; j <= room->GetTopLeftCorner().y; j++) {
				if (map.mapArr[j][room->GetBottomLeftCorner().x] == 7) {
					notWall.push_back(std::pair<int, int>(j, room->GetBottomLeftCorner().x));
					map.mapArr[j][room->GetBottomLeftCorner().x] = 0;

				}
				else {
					bool canWall = true;
					for (std::pair<int, int> point : notWall) {
						if (point.first == j && point.second == room->GetBottomLeftCorner().x) {
							canWall = false;
							break;
						}
					}
					if (canWall) {
						map.mapArr[j][room->GetBottomLeftCorner().x] = 7;
					}
				}

				if (map.mapArr[j][room->GetBottomRightCorner().x] == 7) {
					notWall.push_back(std::pair<int, int>(j, room->GetBottomRightCorner().x));
					map.mapArr[j][room->GetBottomRightCorner().x] = 0;
				}
				else {
					bool canWall = true;
					for (std::pair<int, int> point : notWall) {
						if (point.first == j && point.second == room->GetBottomRightCorner().x) {
							canWall = false;
							break;
						}
					}
					if (canWall) {
						map.mapArr[j][room->GetBottomRightCorner().x] = 7;
					}
				}

				map.mapArr[room->GetBottomLeftCorner().y][room->GetBottomLeftCorner().x] = 7;
				map.mapArr[room->GetBottomRightCorner().y][room->GetBottomRightCorner().x] = 7;
				map.mapArr[room->GetTopLeftCorner().y][room->GetTopLeftCorner().x] = 7;
				map.mapArr[room->GetTopRightCorner().y][room->GetTopRightCorner().x] = 7;
			}
			

			// ���� ���� �̻��ϰ� �� �ȿ� �ִ� ��찡 �����Ƿ� ����� ���� 0���� �ʱ�ȭ
			for (int i = room->GetBottomLeftCorner().x + 1; i < room->GetBottomRightCorner().x; i++) {
				for (int j = room->GetBottomLeftCorner().y + 1; j < room->GetTopLeftCorner().y; j++) {
					map.mapArr[j][i] = 0;
				}
			}

			
		}
		/*for (Node* room : rooms) {
			for (int room_col = room->GetBottomLeftCorner().x; room_col <= room->GetBottomRightCorner().x; room_col++) {

				for (Node* cooridor : cooridorVector) {
					for (int cooridor_col = cooridor->GetBottomLeftCorner().x; cooridor_col <= cooridor->GetTopLeftCorner().x; cooridor_col++) {
						if (room->GetBottomLeftCorner().y == cooridor->GetBottomLeftCorner().y && room_col == cooridor_col) {
							map.mapArr[cooridor->GetBottomLeftCorner().y][cooridor_col] = 0;
						}
						if (room->GetTopLeftCorner().y == cooridor->GetBottomLeftCorner().y && room_col == cooridor_col) {
							map.mapArr[cooridor->GetTopLeftCorner().y][cooridor_col] = 0;
						}
						if(room->GetTopLeftCorner().y == )
					}

					for (int cooridor_row = cooridor->GetBottomLeftCorner().y; cooridor_row <= cooridor->GetTopLeftCorner().y; cooridor_row++) {

					}
				}
			}

			for (int j = room->GetBottomLeftCorner().y; j <= room->GetTopLeftCorner().y; j++) {
			
				for (Node* cooridor : cooridorVector) {
					for (int cooridor_col = cooridor->GetBottomLeftCorner().x; cooridor_col <= cooridor->GetTopLeftCorner().x; cooridor_col++) {

					}

					for (int cooridor_row = cooridor->GetBottomLeftCorner().y; cooridor_row <= cooridor->GetTopLeftCorner().y; cooridor_row++) {

					}
				}

			}
		}*/
		

		// ���� �ȿ� �ִ� �� �ʱ�ȭ
		for (Node* cooridor : cooridorVector) {
			for (int i = cooridor->GetBottomLeftCorner().x + 1; i < cooridor->GetBottomRightCorner().x; i++) {
				for (int j = cooridor->GetBottomLeftCorner().y + 1; j < cooridor->GetTopLeftCorner().y; j++) {
					map.mapArr[j][i] = 0;
				}
			}
		}



		return map;
	}

	/// <summary>
	/// ��ũ�� / 10 ~ ��ũ�� / 10 + 2��ŭ ���� ������
	/// </summary>
	/// <param name="room">��</param>
	/// <returns>������ ���� ��</returns>
	static int GetMonsterCount(Node* room) {
		int roomArea =
		(room->GetBottomRightCorner().x - room->GetBottomLeftCorner().x)
		* (room->GetTopLeftCorner().y - room->GetBottomLeftCorner().y);

		return Mathf::Random::Range(roomArea / 20 - 1, roomArea / 15 - 1);
	}
	

	/// <summary>
	/// ���� ��ġ������ ���� �ٵ� �ϴ� �濡�� ���� ��ǥ�� �ϳ� �̾�
	/// </summary>
	/// <param name="room">���� ��ǥ ���� ��</param>
	/// <returns>�泻�� ���� ��ǥ</returns>
	static Vector2Int PlaceStructuresInRoom(Node* room) {
		
		return Vector2Int(
			Mathf::Random::Range(
				room->GetBottomLeftCorner().y + 1,
				room->GetTopLeftCorner().y
			),
			Mathf::Random::Range(
				room->GetBottomLeftCorner().x + 1,
				room->GetBottomRightCorner().x
			)
		);
	}

	static int getCommand()
	{
		while (true) {
			if (_kbhit()) { // Ű �Է� ����
				int input = _getch(); // Ű �Է� �б�
				if (input == 224) { // ����Ű�� ù ��° ����Ʈ (224)
					input = _getch(); // �� ��° ����Ʈ (����Ű�� �ش��ϴ� ��)
					//std::cout << "�Էµ� ��: " << input << std::endl;
					return input;
					/*switch (input) {
					case 72:
						std::cout << "�� ����Ű" << std::endl;
						break;
					case 80:
						std::cout << "�Ʒ� ����Ű" << std::endl;
						break;
					case 75:
						std::cout << "���� ����Ű" << std::endl;
						break;
					case 77:
						std::cout << "������ ����Ű" << std::endl;
						break;
					default:
						std::cout << "�� �� ���� ����Ű" << std::endl;
						break;
					}*/
				}
				//std::cout << "�Էµ� ��: " << input << std::endl;
				return input;
				// break; // ���� ����
			}
		}

		return -1;
	}
}

