#include <iostream>
#include <conio.h>


int PlayerHp = 100;
int PlayerAtt = 15;
int PlayerEXP = 0;

int MonsterHp = 40;
int MonsterAtt = 10;
int MonsterEX = 15;




void Status(int Hp, int Att, bool _PM)
{
    if (_PM)
    {
        printf_s("----------------P L A Y E R----------------\n");
        printf_s("Hp %d\tAtt %d\t\t\tExp %d\n", Hp, Att, PlayerEXP);
        printf_s("-------------------------------------------\n");
    }
    else
    {
        printf_s("---------------M O N S T E R---------------\n");
        printf_s("Hp %d\tAtt %d\n", Hp, Att);
        printf_s("-------------------------------------------\n");
    }
}

void Damage(int* Hp, int Att, bool _PM)
{
    // true  플레이어가 몬스터 타격
    // false 몬스터가 플레이어 타격

    *Hp -= Att;

    system("cls");
    Status(PlayerHp, PlayerAtt, true);
    Status(MonsterHp, MonsterAtt, false);

    if (_PM)
    {
        printf_s("몬스터가 ");
    }
    else
    {
        printf_s("플레이어가 ");
    }
    printf_s("%d의 데미지를 입었습니다.\n", Att);

}



int main()
{
    int i = 1;
    while (PlayerHp)
    {
        // 콘솔화면을 한번 깨끗하게 삭제해주는 함수
        system("cls");
        Status(PlayerHp, PlayerAtt, true);
        Status(MonsterHp, MonsterAtt, false);
        _getch();

        if (i % 2)
        {
            Damage(&MonsterHp, PlayerAtt, true);
        }
        else
        {
            Damage(&PlayerHp, MonsterAtt, false);
        }
        _getch();

        if (0 < PlayerHp)
        {
            printf_s("플레이어는 생존했습니다.\n");
        }

        if (0 >= MonsterHp)
        {
            PlayerEXP += MonsterEX;
            printf_s("몬스터가 사망했습니다.\n");
            printf_s("%d의 경험치를 얻었습니다.\n", MonsterEX);
            MonsterHp = 40;
           
        }
        _getch();

        i++;
    }
    printf_s("게임이 끝났습니다.\n");
    _getch();
}
