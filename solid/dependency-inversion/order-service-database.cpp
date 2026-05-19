#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Database
{
public:
    virtual ~Database() = default;
    virtual void insert(const string &table, const string &data) = 0;
    virtual string query(const string &table, const string &id) = 0;
};

class MySQLDatabase : public Database
{
public:
    void insert(const string &table, const string &data) override
    {
        cout << "MySQL: Inserting into " << table << " -> " << data << endl;
    }

    string query(const string &table, const string &id) override
    {
        cout << "MySQL: Querying " << table << " for id " << id << endl;
        return "{ id: " + id + ", item: 'Widget' }";
    }
};

class PostgresDatabase : public Database
{
public:
    void insert(const string &table, const string &data) override
    {
        cout << "PostgreSQL: Inserting into " << table << " -> " << data << endl;
    }

    string query(const string &table, const string &id) override
    {
        cout << "PostgreSQL: Querying " << table << " for id " << id << endl;
        return "{ id: " + id + ", item: 'Widget' }";
    }
};

class OrderService
{
private:
    unique_ptr<Database> database;

public:
    OrderService(unique_ptr<Database> db) : database(move(db)) {}

    void placeOrder(const string &orderId, const string &orderData)
    {
        cout << "Placing order: " << orderId << endl;
        database->insert("orders", orderData);
        cout << "Order placed successfully." << endl;
    }

    string getOrder(const string &orderId)
    {
        return database->query("orders", orderId);
    }
};

int main()
{
    cout << "--- MySQL ---" << endl;
    auto mysqlService = OrderService(make_unique<MySQLDatabase>());
    mysqlService.placeOrder("ORD-001", "{ item: 'Widget', qty: 3 }");
    string order1 = mysqlService.getOrder("ORD-001");
    cout << "Order: " << order1 << endl;

    cout << endl;
    cout << "--- PostgreSQL ---" << endl;
    auto pgService = OrderService(make_unique<PostgresDatabase>());
    pgService.placeOrder("ORD-001", "{ item: 'Widget', qty: 3 }");
    string order2 = pgService.getOrder("ORD-001");
    cout << "Order: " << order2 << endl;

    return 0;
}