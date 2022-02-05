#include<iostream>
#include"Event.h"

void ShowB()
{
    std::cout << "BBB" << std::endl;
}

class CCC
{
public:
    void ShowC()
    {
        std::cout << "CCC" << std::endl;
    }
};


int main(void)
{
    Event e;
    CCC c;

    e.AddFunc(
        []() -> void {std::cout << "AAA" << std::endl; }//ラムダ
    );

    e.AddFunc(
       ShowB//グローバル
    );

    e.AddFunc(
       std::bind(& CCC::ShowC,&c)//クラス
    );


    e.Run();


    return 1;
}