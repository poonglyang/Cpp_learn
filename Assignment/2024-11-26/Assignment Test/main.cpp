#include <iostream>
#include <map>

using namespace std;

int main()
{
    using namespace std;
    map<int, int> m1, m2, m3;
    int i;
    typedef pair<int, int> Int_Pair;

    //for (i = 1; i < 3; i++)
    //{
    //    m1.insert(Int_Pair(i, i));
    //    m2.insert(Int_Pair(i, i * i));
    //    m3.insert(Int_Pair(i, i - 1));
    //}

    /*m1.insert(Int_Pair(1, 1));
    m1.insert(Int_Pair(2, 2));
    m1.insert(Int_Pair(3, 99));

    m2.insert(Int_Pair(1, 1));
    m2.insert(Int_Pair(2, 3));
    m2.insert(Int_Pair(3, 0));*/

    m1.insert(Int_Pair(1, 2));
    m1.insert(Int_Pair(99999, -99));

    m2.insert(Int_Pair(1, 9999));
    m2.insert(Int_Pair(2, 3));
    m2.insert(Int_Pair(3, 0));

    if (m1 < m2)
        cout << "map m1�� map m2���� �۴�" << endl;
    else
        cout << "map m1�� map m2���� ũ��" << endl;

    if (m1 <= m2)
        cout << "map m1�� map m2���� �۰ų� ����" << endl;
    else
        cout << "map m1�� map m2���� ũ��" << endl;

    /*if (m1 < m3)
        cout << "The map m1 is less than the map m3." << endl;
    else
        cout << "The map m1 is not less than the map m3." << endl;*/
}