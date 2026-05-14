#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

class Discount
{
protected:
    string label;

public:
    Discount(const string &label) : label(label) {}
    virtual ~Discount() {}

    virtual double apply(double price) = 0;

    void describe(double originalPrice)
    {
        double discountedPrice = apply(originalPrice);

        printf("%s: $%.2f -> $%.2f\n",
               label.c_str(),
               originalPrice,
               discountedPrice);
    }
};

class PercentageDiscount : public Discount
{
    double percentage;

public:
    PercentageDiscount(double percentage)
        : Discount(string())
    {

        char buf[32];
        snprintf(buf, sizeof(buf), "%.1f", percentage);

        this->label = string(buf) + "% off";
        this->percentage = percentage;
    }

    double apply(double price) override
    {
        return price * (1 - percentage / 100.0);
    }
};

class FlatDiscount : public Discount
{
    double amount;

public:
    FlatDiscount(double amount)
        : Discount(string())
    {

        char buf[32];
        snprintf(buf, sizeof(buf), "%.1f", amount);

        this->label = "$" + string(buf) + " off";
        this->amount = amount;
    }

    double apply(double price) override
    {
        return max(price - amount, 0.0);
    }
};

class BuyOneGetOneFree : public Discount
{
public:
    BuyOneGetOneFree() : Discount("Buy 1 Get 1 Free") {}

    double apply(double price) override
    {
        return price / 2.0;
    }
};

class OrderProcessor
{
public:
    void processOrder(const string &itemName, double price, Discount &discount)
    {
        cout << "Item: " << itemName << endl;
        discount.describe(price);
    }
};

int main()
{
    OrderProcessor processor;

    PercentageDiscount pct(20);
    FlatDiscount flat(15);
    BuyOneGetOneFree bogo;

    processor.processOrder("Laptop", 999.99, pct);
    processor.processOrder("Headphones", 49.99, flat);
    processor.processOrder("Keyboard", 79.98, bogo);

    return 0;
}