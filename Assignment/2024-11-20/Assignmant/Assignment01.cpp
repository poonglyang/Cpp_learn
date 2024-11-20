/*
# ���� 1

1. ���� Ŭ���� �� ��ӹ޴�
    1. ���� Ŭ����
        - ��ų 2��
    2. �÷��̾� Ŭ����
        - ��ų 2��

2. ���
    - �⺻���� Status
    - ������ �ɹ� �Լ��� Ȱ��

*/

#include <iostream>
#include <format>
#include <windows.h>

using namespace std;

class unit {
protected:
    string name;
    int healthPoint;
    int manaPoint;
    int atk;
    int def;
    bool isAlive;

    /// <summary>
    /// ��������� false �ϴ� �Լ�
    /// �׾��ٰ� ��µ� ��
    /// </summary>
    void Die() {
        isAlive = false;
        cout << "[" << name << "�� ������ ��Ƽ�� ���ߴ�]" << endl;
    }
public:

    /// <summary>
    /// unit�� ������
    /// </summary>
    /// <param name="name">�̸�</param>
    /// <param name="hp">hp</param>
    /// <param name="mp">mp</param>
    /// <param name="atk">���ݷ�</param>
    /// <param name="def">����</param>
    unit(const string& name, int hp, int mp, int atk, int def) : name(name), healthPoint(hp), manaPoint(mp), atk(atk), def(def) {
        isAlive = true;
    };

    /// <summary>
    /// �̸��� ��ȯ�ϴ� �Լ�
    /// </summary>
    /// <returns>�̸�</returns>
    string GetName() {
        return name;
    }

    /// <summary>
    /// hp�� ��ȯ�ϴ� �Լ�
    /// </summary>
    /// <returns>hp</returns>
    int GetHP() {
        return healthPoint;
    }

    /// <summary>
    /// hp�� �����ϸ� 0���ϰ� �Ǿ��� ��� �׾��ٴ� ���� �������ִ� �Լ�
    /// virtual�� ������ �÷��̾� ���� ��� hp�� ȸ���ϴ� ��찡 �����Ƿ� player Ŭ�������� ������ �ʿ��ϱ⿡ override �϶�� ����
    /// </summary>
    /// <param name="delta"></param>
    virtual void SetHP(int delta) {
        healthPoint += delta;   // delta��ŭ hp�� ������
        if (healthPoint <= 0) { // hp�� 0 ���ϰ� �Ǹ�
            healthPoint = 0;    // hp�� 0���� �����
            this->Die();        // �׾��� �� ������ �Լ��� ȣ����
        }
    }

    /// <summary>
    /// mp�� ���� ��ȯ�ϴ� �Լ�
    /// </summary>
    /// <returns>mp</returns>
    int GetMP() {
        return manaPoint;
    }

    /// <summary>
    /// mp�� �����ϴ� �Լ�
    /// virtual�� ������ �÷��̾� ���� ��� mp�� ȸ���ϴ� ��찡 �����Ƿ� player Ŭ�������� ������ �ʿ��ϱ⿡ override �϶�� ����
    /// </summary>
    /// <param name="delta"></param>
    /// <returns></returns>
    virtual void SetMP(int delta) {
        manaPoint += delta;
    }

    /// <summary>
    /// ���ݷ��� �޾ƿ��� �Լ�
    /// </summary>
    /// <returns>����</returns>
    int GetAtk() {
        return atk;
    }

    /// <summary>
    /// ������ �޾ƿ��� �Լ�
    /// </summary>
    /// <returns>����</returns>
    int GetDef() {
        return def;
    }

    /// <summary>
    /// ���� �������� ����ϴ� �Լ�,
    /// ���� ������ = ���� ���ݷ� - ���� ���� 
    /// </summary>
    /// <param name="attackerAtk">���� ���ݷ�</param>
    /// <returns>���� ���ݷ� - ���� ����</returns>
    int CalcDamage(int attackerAtk) {
        return (attackerAtk - this->def) > 0 ? attackerAtk - this->def : 0;
    }

    /// <summary>
    /// ���� �������� �� �����ϴ� �Լ�
    /// </summary>
    /// <param name="attackerAtk">���� ���ݷ�</param>
    void Hit(int attackerAtk) {
        cout << this->name << "�� " << CalcDamage(attackerAtk) << "��ŭ ���ظ� �Ծ���" << endl;
        SetHP(-CalcDamage(attackerAtk));
    }

    /// <summary>
    /// �����ϴ� �Լ�
    /// </summary>
    /// <param name="target">���� ���</param>
    void Attack(unit& target) {
        if (target.IsAlive() && isAlive) {
            int attackn = rand() % 2;
            if (attackn == 0) {
                Skill1(target);
            }
            else if (attackn == 1){
                Skill2(target);
            }
            else {
                cout << name << "�Ϲ� ����!" << endl;
                target.Hit(atk);
            }
            /*
            cout << name << "�� ����!" << endl;
            target.Hit(atk);
            */
        }
    }

    bool IsAlive() {
        return isAlive;
    }

    virtual void Skill1(unit& target) {
        
    }

    virtual void Skill2(unit& target) {

    }
};

class Player : public unit {
private:
    int maxHP;
    int maxMP;
    int level;
    int exp;
    int maxExp;

public:
    /// <summary>
    /// �÷��̾� Ŭ������ ������, ����ġ, ����ġ �ٸ� �����Ѵ�
    /// </summary>
    /// <param name="name">�̸�</param>
    /// <param name="hp">hp</param>
    /// <param name="mp">mp</param>
    /// <param name="atk">���ݷ�</param>
    /// <param name="def">����</param>
    /// <param name="maxHP">�ִ� hp</param>
    /// <param name="maxMP">�ִ� mp</param>
    Player(const string& name, int hp, int mp, int atk, int def, int maxHP, int maxMP)
        : unit(name, hp, mp, atk, def), maxHP(maxHP), maxMP(maxMP) {
        level = 1;
        exp = 0;
        maxExp = 20;
    }

    /// <summary>
    /// �������� �ϴ� �Լ�
    /// </summary>
    void LevelUp() {
        this->exp -= maxExp;
        cout << "[������!]" << endl;
        if (this->exp >= maxExp) {
            LevelUp();
        }
    }

    /// <summary>
    /// ����ġ�� ��� �Լ�
    /// </summary>
    /// <param name="exp">ȹ���� ����ġ</param>
    void AddExp(int exp) {
        this->exp += exp;
        cout << "[" << exp << "��ŭ ����ġ�� ȹ���ߴ�]" << endl;
        if (this->exp >= maxExp) {
            LevelUp();
        }
    }

    /// <summary>
    /// �θ� Ŭ���� SetHP�� �������̵� �� �Լ�
    /// �÷��̾� ���� ��� maxHP�� �����Ƿ� maxHP�� �ȳѾ�� �ؾ���
    /// </summary>
    /// <param name="delta">hp ������</param>
    void SetHP(int delta) override {
        unit::SetHP(delta);
        if (healthPoint > maxHP) {
            healthPoint = maxHP;
        }
    }

    /// <summary>
    /// �θ� Ŭ���� SetMP�� �������̵� �� �Լ�
    /// �÷��̾� ���� ��� maxMP�� �����Ƿ� maxMP�� �ȳѾ�� �ؾ���
    /// </summary>
    /// <param name="delta">hp ������</param>
    void SetMP(int delta) override {
        unit::SetMP(delta);
        if (manaPoint > maxMP) {
            manaPoint = maxMP;
        }
    }

    void Skill1(unit& target) override {
        if (manaPoint >= 100) {
            SetMP(-100);
            cout << name << "�� �ſ�ſ� ���ϰ� ���⸮" << endl;
            target.Hit(atk * 5);
        }
        else {
            cout << name << "�� �Ϲ� ����!" << endl;
            target.Hit(atk);
        }
    }

    void Skill2(unit& target) override {
        if (manaPoint >= 50) {
            SetMP(-50);
            cout << name << "�� �׳� ���ϰ� ���⸮" << endl;
            target.Hit(atk * 1.5);
        }
        else {
            cout << name << "�� �Ϲ� ����!" << endl;
            target.Hit(atk);
        }
    }
};

class Monster : public unit {

private:
    int exp;

public:
    Monster(const string& name, int hp, int mp, int atk, int def, int exp)
        : unit(name, hp, mp, atk, def), exp(exp) {
    }

    /// <summary>
    /// ���Ϳ��� ������ exp�� ���� ��ȯ�ϴ� �Լ�
    /// </summary>
    /// <returns>����ġ</returns>
    int GetExp() {
        return exp;
    }

    void Skill1(unit& target) override {
        if (manaPoint >= 100) {
            SetMP(-100);
            cout << name << "�� ��ȥ��� �ϰ�!" << endl;
            target.Hit(atk * 1.8);
        }
        else {
            cout << name << "�� ��ħ ����!" << endl;
            target.Hit(atk);
        }
    }

    void Skill2(unit& target) override {
        if (manaPoint >= 50) {
            SetMP(-50);
            cout << name << "�� �׳� ���ϰ� ���⸮" << endl;
            target.Hit(atk * 1.3);
        }
        else {
            cout << name << "�� �Ϲ� ����!" << endl;
            target.Hit(atk);
        }
    }
};

int main() {
    srand(time(0));

    Player* player = new Player("������", 1000, 300, 25, 5, 1000, 300);
    Monster* monster = new Monster("���", 200, 50, 10, 1, 30);

    unit* uPlayer;
    uPlayer = player;
    unit* uMonster;
    uMonster = monster;
    

    cout << monster->GetName() << "�� ��Ÿ����" << endl;
    while (player->IsAlive() && monster->IsAlive()) {
        Sleep(500);
        player->Attack(*uMonster);
        cout << endl;

        Sleep(500);
        monster->Attack(*uPlayer);
        cout << endl;

        Sleep(500);
        cout << player->GetName() << "�� ä�� : " << player->GetHP()
            << ", " << monster->GetName() << "�� ä�� : " << monster->GetHP() << endl << endl;;

        if (!monster->IsAlive()) {
            player->AddExp(monster->GetExp());
        }
    }

    delete player, monster, uPlayer, uMonster;
    player = nullptr;
    monster = nullptr;
    uPlayer = uMonster = nullptr;
}