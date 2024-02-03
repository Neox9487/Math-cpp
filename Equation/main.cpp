#include <iostream>
#include "Equation.h"

using namespace std;

int main(){
    
    Equation *e_1 = new Equation(1, 1, -2, 4, -4);
    e_1->get_equationInfo();
    Equation *e_2 = new Equation(4, -3, 5);
    e_2->get_equationInfo();

    // // 圓 -> 線 距離
    // Equation *e_1 = new Equation(1, 1, -2, 4, -4);
    // Equation *e_2 = new Equation(4, -3, 5);
    // e_1->get_distance(*e_2);

    // // 線 -> 圓 距離
    // Equation *e_3 = new Equation(12, 5, 11);
    // Equation *e_4 = new Equation(1, 1, -2, 4, -4);
    // e_3->get_distance(*e_4);

    // // 兩個圓 距離
    // Equation *e_5 = new Equation(1, 1, -8, 6, 0);
    // Equation *e_6 = new Equation(1, 1, 0, 0, 0);
    // e_5->get_distance(*e_6);

    // // 兩條線 距離
    // Equation *e_7 = new Equation(3, 4, 11);
    // Equation *e_8 = new Equation(6, 8, -9);
    // e_7->get_distance(*e_8);

}