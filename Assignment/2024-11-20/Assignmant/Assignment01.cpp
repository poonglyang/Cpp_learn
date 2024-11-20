/*
# 과제 1

1. 유닛 클래스 를 상속받는
    1. 몬스터 클래스
        - 스킬 2개
    2. 플레이어 클래스
        - 스킬 2개

2. 출력
    - 기본적인 Status
    - 각각의 맴버 함수를 활용

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
    /// 살아있음을 false 하는 함수
    /// 죽었다고 출력도 함
    /// </summary>
    void Die() {
        isAlive = false;
        cout << "[" << name << "은 공격을 버티지 못했다]" << endl;
    }
public:

    /// <summary>
    /// unit의 생성자
    /// </summary>
    /// <param name="name">이름</param>
    /// <param name="hp">hp</param>
    /// <param name="mp">mp</param>
    /// <param name="atk">공격력</param>
    /// <param name="def">방어력</param>
    unit(const string& name, int hp, int mp, int atk, int def) : name(name), healthPoint(hp), manaPoint(mp), atk(atk), def(def) {
        isAlive = true;
    };

    /// <summary>
    /// 이름을 반환하는 함수
    /// </summary>
    /// <returns>이름</returns>
    string GetName() {
        return name;
    }

    /// <summary>
    /// hp를 반환하는 함수
    /// </summary>
    /// <returns>hp</returns>
    int GetHP() {
        return healthPoint;
    }

    /// <summary>
    /// hp를 설정하며 0이하가 되었을 경우 죽었다는 것을 설정해주는 함수
    /// virtual인 이유는 플레이어 같은 경우 hp를 회복하는 경우가 있으므로 player 클래스에서 수정이 필요하기에 override 하라고 써줌
    /// </summary>
    /// <param name="delta"></param>
    virtual void SetHP(int delta) {
        healthPoint += delta;   // delta만큼 hp에 더해줌
        if (healthPoint <= 0) { // hp가 0 이하가 되면
            healthPoint = 0;    // hp를 0으로 만들고
            this->Die();        // 죽었을 때 실행할 함수를 호출함
        }
    }

    /// <summary>
    /// mp의 값을 반환하는 함수
    /// </summary>
    /// <returns>mp</returns>
    int GetMP() {
        return manaPoint;
    }

    /// <summary>
    /// mp를 설정하는 함수
    /// virtual인 이유는 플레이어 같은 경우 mp를 회복하는 경우가 있으므로 player 클래스에서 수정이 필요하기에 override 하라고 써줌
    /// </summary>
    /// <param name="delta"></param>
    /// <returns></returns>
    virtual void SetMP(int delta) {
        manaPoint += delta;
    }

    /// <summary>
    /// 공격력을 받아오는 함수
    /// </summary>
    /// <returns>방어력</returns>
    int GetAtk() {
        return atk;
    }

    /// <summary>
    /// 방어력을 받아오는 함수
    /// </summary>
    /// <returns>방어력</returns>
    int GetDef() {
        return def;
    }

    /// <summary>
    /// 입은 데미지를 계산하는 함수,
    /// 입은 데미지 = 적의 공격력 - 나의 방어력 
    /// </summary>
    /// <param name="attackerAtk">적의 공격력</param>
    /// <returns>적의 공격력 - 나의 방어력</returns>
    int CalcDamage(int attackerAtk) {
        return (attackerAtk - this->def) > 0 ? attackerAtk - this->def : 0;
    }

    /// <summary>
    /// 적이 공격했을 때 실행하는 함수
    /// </summary>
    /// <param name="attackerAtk">적의 공격력</param>
    void Hit(int attackerAtk) {
        cout << this->name << "은 " << CalcDamage(attackerAtk) << "만큼 피해를 입었다" << endl;
        SetHP(-CalcDamage(attackerAtk));
    }

    /// <summary>
    /// 공격하는 함수
    /// </summary>
    /// <param name="target">공격 대상</param>
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
                cout << name << "일반 공격!" << endl;
                target.Hit(atk);
            }
            /*
            cout << name << "의 공격!" << endl;
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
    /// 플레이어 클래스의 생성자, 경험치, 경험치 바를 생성한다
    /// </summary>
    /// <param name="name">이름</param>
    /// <param name="hp">hp</param>
    /// <param name="mp">mp</param>
    /// <param name="atk">공격력</param>
    /// <param name="def">방어력</param>
    /// <param name="maxHP">최대 hp</param>
    /// <param name="maxMP">최대 mp</param>
    Player(const string& name, int hp, int mp, int atk, int def, int maxHP, int maxMP)
        : unit(name, hp, mp, atk, def), maxHP(maxHP), maxMP(maxMP) {
        level = 1;
        exp = 0;
        maxExp = 20;
    }

    /// <summary>
    /// 레벨업을 하는 함수
    /// </summary>
    void LevelUp() {
        this->exp -= maxExp;
        cout << "[레벨업!]" << endl;
        if (this->exp >= maxExp) {
            LevelUp();
        }
    }

    /// <summary>
    /// 경험치를 얻는 함수
    /// </summary>
    /// <param name="exp">획득한 경험치</param>
    void AddExp(int exp) {
        this->exp += exp;
        cout << "[" << exp << "만큼 경험치를 획득했다]" << endl;
        if (this->exp >= maxExp) {
            LevelUp();
        }
    }

    /// <summary>
    /// 부모 클래스 SetHP를 오버라이드 한 함수
    /// 플레이어 같은 경우 maxHP가 있으므로 maxHP를 안넘어가게 해야함
    /// </summary>
    /// <param name="delta">hp 증감값</param>
    void SetHP(int delta) override {
        unit::SetHP(delta);
        if (healthPoint > maxHP) {
            healthPoint = maxHP;
        }
    }

    /// <summary>
    /// 부모 클래스 SetMP를 오버라이드 한 함수
    /// 플레이어 같은 경우 maxMP가 있으므로 maxMP를 안넘어가게 해야함
    /// </summary>
    /// <param name="delta">hp 증감값</param>
    void SetMP(int delta) override {
        unit::SetMP(delta);
        if (manaPoint > maxMP) {
            manaPoint = maxMP;
        }
    }

    void Skill1(unit& target) override {
        if (manaPoint >= 100) {
            SetMP(-100);
            cout << name << "의 매우매우 강하게 때기리" << endl;
            target.Hit(atk * 5);
        }
        else {
            cout << name << "의 일반 공격!" << endl;
            target.Hit(atk);
        }
    }

    void Skill2(unit& target) override {
        if (manaPoint >= 50) {
            SetMP(-50);
            cout << name << "의 그냥 강하게 때기리" << endl;
            target.Hit(atk * 1.5);
        }
        else {
            cout << name << "의 일반 공격!" << endl;
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
    /// 몬스터에게 지정된 exp의 값을 반환하는 함수
    /// </summary>
    /// <returns>경험치</returns>
    int GetExp() {
        return exp;
    }

    void Skill1(unit& target) override {
        if (manaPoint >= 100) {
            SetMP(-100);
            cout << name << "의 영혼담긴 일격!" << endl;
            target.Hit(atk * 1.8);
        }
        else {
            cout << name << "의 독침 공격!" << endl;
            target.Hit(atk);
        }
    }

    void Skill2(unit& target) override {
        if (manaPoint >= 50) {
            SetMP(-50);
            cout << name << "의 그냥 강하게 때기리" << endl;
            target.Hit(atk * 1.3);
        }
        else {
            cout << name << "의 일반 공격!" << endl;
            target.Hit(atk);
        }
    }
};

int main() {
    srand(time(0));

    Player* player = new Player("김전사", 1000, 300, 25, 5, 1000, 300);
    Monster* monster = new Monster("고블린", 200, 50, 10, 1, 30);

    unit* uPlayer;
    uPlayer = player;
    unit* uMonster;
    uMonster = monster;
    

    cout << monster->GetName() << "이 나타났다" << endl;
    while (player->IsAlive() && monster->IsAlive()) {
        Sleep(500);
        player->Attack(*uMonster);
        cout << endl;

        Sleep(500);
        monster->Attack(*uPlayer);
        cout << endl;

        Sleep(500);
        cout << player->GetName() << "의 채력 : " << player->GetHP()
            << ", " << monster->GetName() << "의 채력 : " << monster->GetHP() << endl << endl;;

        if (!monster->IsAlive()) {
            player->AddExp(monster->GetExp());
        }
    }

    delete player, monster, uPlayer, uMonster;
    player = nullptr;
    monster = nullptr;
    uPlayer = uMonster = nullptr;
}