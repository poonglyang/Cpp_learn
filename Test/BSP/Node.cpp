class Node {
public:

	int Width() {
		return width;
	}



private:
	
	//Node (const Node &);
	
	int level;
	int topRightCorner;
	int bottomLeftCorner;
	int width;
	int height;
};