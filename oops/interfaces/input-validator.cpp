#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Validator
{
public:
    virtual ~Validator() {}
    virtual bool validate(const string &input) = 0;
};

class EmailValidator : public Validator
{
public:
    bool validate(const string &input) override
    {
        // Return true if input contains "@"
        return input.find("@") != string::npos;
    }
};

class PasswordValidator : public Validator
{
public:
    bool validate(const string &input) override
    {
        // Return true if input.length() >= 8
        return input.size() >= 8;
    }
};

class RegistrationService
{
    vector<Validator *> validators;

public:
    RegistrationService(const vector<Validator *> &validators)
        : validators(validators) {}

    void registerInput(const string &input)
    {
        // Run all validators on input. If all pass, print "input" - PASSED
        // If any fail, print "input" - FAILED
        for (auto validator : validators)
        {
            if (!validator->validate(input))
            {
                cout << "\"" << input << "\" - FAILED" << endl;
                return;
            }
        }
        cout << "\"" << input << "\" - PASSED" << endl;
    }
};

int main()
{
    EmailValidator emailVal;
    vector<Validator *> emailValidators = {&emailVal};
    RegistrationService emailReg(emailValidators);
    emailReg.registerInput("user@example.com"); // Should pass
    emailReg.registerInput("invalid-email");    // Should fail

    PasswordValidator passVal;
    vector<Validator *> passValidators = {&passVal};
    RegistrationService passReg(passValidators);
    passReg.registerInput("strongpassword"); // Should pass
    passReg.registerInput("short");          // Should fail

    return 0;
}