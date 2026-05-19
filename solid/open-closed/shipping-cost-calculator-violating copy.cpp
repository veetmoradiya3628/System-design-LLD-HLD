#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class ShippingCostCalculator
{
public:
    double calculate(const string &shippingType, double weight)
    {
        if (shippingType == "Standard")
        {
            return weight * 1.5;
        }
        else if (shippingType == "Express")
        {
            return weight * 3.0;
        }
        else if (shippingType == "Overnight")
        {
            return weight * 5.0;
        }
        else if (shippingType == "International")
        {
            return weight * 10.0;
        }
        throw invalid_argument("Unknown shipping type: " + shippingType);
    }
};

int main()
{
    ShippingCostCalculator calculator;
    cout << "Standard: $" << calculator.calculate("Standard", 2.0) << endl;
    cout << "Express: $" << calculator.calculate("Express", 2.0) << endl;
    return 0;
}

// TODO: Define a ShippingStrategy interface with a calculateCost(weight) method.
// TODO: Create concrete implementations for each shipping type.
// TODO: Refactor ShippingCostCalculator to accept a ShippingStrategy.