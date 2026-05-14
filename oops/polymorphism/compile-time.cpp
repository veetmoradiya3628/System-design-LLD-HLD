#include <iostream>

class Calculator
{
public:
    // Two ints
    int add(int a, int b)
    {
        return a + b;
    }

    // Two doubles
    double add(double a, double b)
    {
        return a + b;
    }

    // Three ints
    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{
    Calculator calc;
    std::cout << calc.add(2, 3) << std::endl;     // Calls add(int, int) -> 5
    std::cout << calc.add(2.5, 3.5) << std::endl; // Calls add(double, double) -> 6
    std::cout << calc.add(1, 2, 3) << std::endl;  // Calls add(int, int, int) -> 6
    return 0;
}