#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>

enum Mode{
    AS,GS
};

class Sequence{

    public:
        Sequence(Mode mode);
        double get_n_value(double a1, double dr, double n);  // 計算第 n 項的值
        double get_Sn_value(double a1, double dr, double n); // 計算第 Sn 的值

    private:
        Mode mode;    // AS 等差 , GS 等比
        int n;               // n 項數
        double a1, dr, num;  // a1 首項 , dr 等差/比 , num 總數 
        
};

// ========== Utils ==========

Sequence::Sequence(Mode mode){
    this->mode = mode;
}

double Sequence::get_n_value(double a1, double dr, double n){
    this->a1 = a1; this->dr = dr; this->n = n;
    if(n <= 0){
        std::cout<<"Value \"n\" can't be smaller than ";
        return 1;
    }
    num = (mode == AS) ? a1 + dr * (n - 1) : a1 * pow(dr, n-1);
    return num;
}

double Sequence::get_Sn_value(double a1, double dr, double n){
    this->a1 = a1; this->dr = dr; this->n = n;
    if(n <= 0){
        std::cout<<"Value \"n\" can't be smaller than ";
        return 1;
    }
    num = (mode == AS) ? n * (2 * a1 + dr * (n - 1)) / 2 : (a1 * (pow(dr, n) - 1)) / (dr - 1); // 等差級數 n*(a1+an)/2 , 等比級數 a1*(r的n次方-1)/r-1 
    return num;
}