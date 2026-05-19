#include <iostream>
#include <string>

using namespace std;

// Segregated interfaces - each with a single capability
class Printable
{
public:
    virtual void print(const string &document) = 0;
    virtual ~Printable() = default;
};

class Scannable
{
public:
    virtual void scan(const string &document) = 0;
    virtual ~Scannable() = default;
};

class Faxable
{
public:
    virtual void fax(const string &document, const string &number) = 0;
    virtual ~Faxable() = default;
};

class Stapleable
{
public:
    virtual void staple(const string &document) = 0;
    virtual ~Stapleable() = default;
};

// BasicPrinter only implements Printable
class BasicPrinter : public Printable
{
public:
    void print(const string &document) override
    {
        cout << "BasicPrinter -> Printing: " << document << endl;
    }
};

// OfficePrinter implements three interfaces
class OfficePrinter : public Printable, public Scannable, public Faxable
{
public:
    void print(const string &document) override
    {
        cout << "OfficePrinter -> Printing: " << document << endl;
    }

    void scan(const string &document) override
    {
        cout << "OfficePrinter -> Scanning: " << document << endl;
    }

    void fax(const string &document, const string &number) override
    {
        cout << "OfficePrinter -> Faxing: " << document << " to " << number << endl;
    }
};

// FullDevice implements all four interfaces
class FullDevice : public Printable, public Scannable, public Faxable, public Stapleable
{
public:
    void print(const string &document) override
    {
        cout << "FullDevice -> Printing: " << document << endl;
    }

    void scan(const string &document) override
    {
        cout << "FullDevice -> Scanning: " << document << endl;
    }

    void fax(const string &document, const string &number) override
    {
        cout << "FullDevice -> Faxing: " << document << " to " << number << endl;
    }

    void staple(const string &document) override
    {
        cout << "FullDevice -> Stapling: " << document << endl;
    }
};

int main()
{
    BasicPrinter basic;
    basic.print("report.pdf");

    OfficePrinter office;
    office.print("memo.pdf");
    office.scan("memo.pdf");
    office.fax("memo.pdf", "555-1234");

    FullDevice full;
    full.print("contract.pdf");
    full.scan("contract.pdf");
    full.fax("contract.pdf", "555-5678");
    full.staple("contract.pdf");

    return 0;
}