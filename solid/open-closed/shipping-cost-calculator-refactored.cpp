#include <iostream>
#include <iomanip>
#include <memory>
using namespace std;

// ShippingStrategy interface
class ShippingStrategy
{
public:
    virtual ~ShippingStrategy() = default;
    virtual double calculateCost(double weight) const = 0;
};

// Concrete strategies
class StandardShipping : public ShippingStrategy
{
public:
    double calculateCost(double weight) const override
    {
        return weight * 1.5;
    }
};

class ExpressShipping : public ShippingStrategy
{
public:
    double calculateCost(double weight) const override
    {
        return weight * 3.0;
    }
};

class OvernightShipping : public ShippingStrategy
{
public:
    double calculateCost(double weight) const override
    {
        return weight * 5.0;
    }
};

class InternationalShipping : public ShippingStrategy
{
public:
    double calculateCost(double weight) const override
    {
        return weight * 10.0;
    }
};

// Refactored calculator - no if-else
class ShippingCostCalculator
{
private:
    unique_ptr<ShippingStrategy> strategy;

public:
    ShippingCostCalculator(unique_ptr<ShippingStrategy> strategy)
        : strategy(move(strategy)) {}

    double calculate(double weight) const
    {
        return strategy->calculateCost(weight);
    }
};

int main()
{
    double weight = 2.0;

    ShippingCostCalculator standard(make_unique<StandardShipping>());
    ShippingCostCalculator express(make_unique<ExpressShipping>());
    ShippingCostCalculator overnight(make_unique<OvernightShipping>());
    ShippingCostCalculator international(make_unique<InternationalShipping>());

    cout << fixed << setprecision(1);
    cout << "Standard: $" << standard.calculate(weight) << endl;
    cout << "Express: $" << express.calculate(weight) << endl;
    cout << "Overnight: $" << overnight.calculate(weight) << endl;
    cout << "International: $" << international.calculate(weight) << endl;

    return 0;
}