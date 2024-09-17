#include <iostream>

int main(){
    double x = 1.0;
    double x_step = 0.5;
    double x_finish = 4.0;

    while(x <= x_finish){

        double z = std::abs(x) + std::pow(x, 3);
        double y = z * std::pow(std::sin(x+2), 2) / 2 + x;
        std::cout << "when x: " << x << ", then y: " << y << std::endl;
        x += x_step;
    };
}