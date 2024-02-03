// main.cpp
#include <iostream>
#include "Sequence.h"

using namespace std;

int main(){
    // 等差 
    Sequence s_1 = Sequence(AS);               // 宣告一個等差數列
    cout<< s_1.get_n_value(10, 2, 3) <<endl;   // 計算第 n 項的值

    // 等比
    Sequence s_2 = Sequence(GS);               // 宣告一個等比數列 
    cout<< s_2.get_n_value(100, -1, 4) <<endl; // 計算第 n 項的值

    // 等差(和)
    Sequence s_3 = Sequence(AS);               // 宣告一個等差數列
    cout<< s_3.get_Sn_value(2, 4, 3) <<endl;   // 計算 Sn 的值

    // 等比(和)
    Sequence s_4 = Sequence(GS);               // 宣告一個等比數列
    cout<< s_4.get_Sn_value(2, -2, 3) <<endl;  // 計算 Sn 的值

    return 0;
}
