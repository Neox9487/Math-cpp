#pragma once

#include <iostream>
#include <stdio.h>
#include <math.h>

#define PI acos(-1)

using namespace std;

class Equation {

    enum Type{
        Circle, Line
    };

    public:
        Equation(int a, int b, int d, int e, int f); // Circle
        Equation(int a, int b, int c); // Line
        void get_equationInfo();
        void get_distance(Equation equation); // 取得與其他 圓心/線 的距離
        int a, b, c, d, e, f; // 係數
        double x, y; // 圓的中心座標

    private:
        Type type; // 方程式類型
        double diameter;    // 直徑
        double circumfe;    // 圓周長
        double cir_area;    // 圓面積
};

// It will define a equation like "ax2 + by2 + dx + ey + f = 0"
Equation::Equation(int _a, int _b, int _d, int _e, int _f) : a(_a), b(_b), d(_d), e(_e), f(_f){
    this->type = Circle;
    this->diameter = (pow(d, 2) + pow(e, 2) - 4*f) / 4;
    this->circumfe = diameter * PI;
    this->cir_area = pow(diameter/2, 2) * PI;
    this->x= -(d/2); 
    this->y= -(e/2); 

    // 沒有值設零
    this->c=0;
}


// It will define a equation like "ax + by + c = 0"
Equation::Equation(int _a, int _b, int _c) : a(_a), b(_b), c(_c){
    this->type = Line;

    // 沒有值設零
    this->d=0;this->e=0;this->f=0;
    this->diameter=0; this->circumfe=0; this->cir_area=0;
    this->x = 0; 
    this->y = 0;  
}

void Equation::get_distance(Equation equation){
    double distance;

    // Tow circles
    if(this->type == Circle && equation.type == Circle){
        equation.x= equation.x; equation.y= equation.y;
        distance = sqrt(pow((this->x - equation.x), 2) + pow((this->y - equation.y), 2));
    }

    // One circle one line
    else if(this->type == Circle && equation.type == Line){
        distance = abs(equation.a*-(this->d/2) + equation.b*-(this->e/2) + equation.c) / (sqrt(pow(equation.a, 2) + pow(equation.b, 2)));
    }

    // One line one circle
    else if(this->type == Line && equation.type == Circle){
        distance = abs(this->a*-(equation.d/2) + this->b*-(equation.e/2) + this->c) / sqrt(pow(this->a, 2) + pow(this->b, 2));
    }

    // Tow lines
    else if(this->type == Line && equation.type == Line){
        if((this->b/this->a) == (equation.b/equation.a)){
            double d = double(this->a) / double(equation.a);
            distance = abs(this->c - equation.c*d) / sqrt(pow(this->a, 2) + pow(this->b, 2));
        }
        else{
            distance = 0;
        }
    }

    cout<<distance<<endl;
}

void Equation::get_equationInfo(){
    cout<<"===================="<<endl;
    // Equation type
    if(type == Circle){
        cout<<"Equation type : Circle"<<endl;
        cout<<"Equation : ";
        if(a!=0) cout<<a<<"x^2";
        if(b!=0) {cout<<((b>0) ? "+":"");cout<<b<<"y^2";}
        if(d!=0) {cout<<((d>0) ? "+":"");cout<<d<<"x";}
        if(e!=0) {cout<<((e>0) ? "+":"");cout<<e<<"y";}
        if(f!=0) {cout<<((f>0) ? "+":"");cout<<f<<"=0\n";}
        cout<<"Diameter : "<<diameter<<endl;    // 直徑
        cout<<"Circumfe : "<<circumfe<<endl;    // 圓周長
        cout<<"Cir_area : "<<cir_area<<endl;    // 圓面積
        cout<<"Center   : ("<<x<<" , "<<y<<")"<<endl; // 圓心座標
    }
    else if(type == Line){
        cout<<"Equation type : Line"<<endl;
        cout<<"Equation : ";
        if(a!=0) cout<<a<<"x";
        if(b!=0) {cout<<((b>0) ? "+":"");cout<<b<<"y";}
        if(c!=0) {cout<<((c>0) ? "+":"");cout<<c<<"=0\n";}
    }
    cout<<"===================="<<endl;
};