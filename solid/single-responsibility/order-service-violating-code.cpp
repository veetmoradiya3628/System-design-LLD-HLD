#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Before: One class doing three unrelated jobs
class OrderService
{
private:
    map<string, int> inventory;
    vector<string> orders;

public:
    OrderService()
    {
        inventory["LAPTOP"] = 10;
        inventory["PHONE"] = 25;
        inventory["TABLET"] = 15;
    }

    void placeOrder(const string &productId, int quantity,
                    const string &customerEmail)
    {
        // Responsibility 1: Inventory check
        auto it = inventory.find(productId);
        if (it == inventory.end() || it->second < quantity)
        {
            cout << "Insufficient stock for " << productId << endl;
            return;
        }

        // Responsibility 2: Order processing
        double pricePerUnit = 100.0;
        double total = pricePerUnit * quantity;
        string orderId = "ORD-" + to_string(orders.size() + 1);
        orders.push_back(orderId);

        // Responsibility 3: Update inventory
        it->second -= quantity;

        // Responsibility 4: Send notification
        cout << "Email to " << customerEmail << ": Order " << orderId
             << " confirmed. Total: $" << total << endl;
    }
};

// TODO: Refactor into OrderProcessor, InventoryManager, and NotificationService.

int main()
{
    // After refactoring, usage should look like:
    // InventoryManager inventory;
    // NotificationService notifications;
    // OrderProcessor processor(inventory, notifications);
    // processor.placeOrder("LAPTOP", 2, "alice@example.com");
    return 0;
}