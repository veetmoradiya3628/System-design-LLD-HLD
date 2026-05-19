#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Segregated interfaces
class UserCrud
{
public:
    virtual void createUser(const string &name, const string &email) = 0;
    virtual string getUser(const string &userId) = 0;
    virtual void updateUser(const string &userId, const string &newEmail) = 0;
    virtual void deleteUser(const string &userId) = 0;
    virtual ~UserCrud() = default;
};

class AdminControls
{
public:
    virtual void banUser(const string &userId, const string &reason) = 0;
    virtual void promoteUser(const string &userId, const string &role) = 0;
    virtual ~AdminControls() = default;
};

class AuditLog
{
public:
    virtual vector<string> getLoginHistory(const string &userId) = 0;
    virtual vector<string> getActivityLog(const string &userId) = 0;
    virtual ~AuditLog() = default;
};

// BasicUserService implements only UserCrud
class BasicUserService : public UserCrud
{
public:
    void createUser(const string &name, const string &email) override
    {
        cout << "BasicUserService -> Creating user: " << name << " (" << email << ")" << endl;
    }

    string getUser(const string &userId) override
    {
        cout << "BasicUserService -> Fetching user: " << userId << endl;
        return "User-" + userId;
    }

    void updateUser(const string &userId, const string &newEmail) override
    {
        cout << "BasicUserService -> Updating user " << userId << " email to " << newEmail << endl;
    }

    void deleteUser(const string &userId) override
    {
        cout << "BasicUserService -> Deleting user: " << userId << endl;
    }
};

// AdminUserService implements UserCrud and AdminControls
class AdminUserService : public UserCrud, public AdminControls
{
public:
    void createUser(const string &name, const string &email) override
    {
        cout << "AdminUserService -> Creating user: " << name << " (" << email << ")" << endl;
    }

    string getUser(const string &userId) override
    {
        cout << "AdminUserService -> Fetching user: " << userId << endl;
        return "User-" + userId;
    }

    void updateUser(const string &userId, const string &newEmail) override
    {
        cout << "AdminUserService -> Updating user " << userId << " email to " << newEmail << endl;
    }

    void deleteUser(const string &userId) override
    {
        cout << "AdminUserService -> Deleting user: " << userId << endl;
    }

    void banUser(const string &userId, const string &reason) override
    {
        cout << "AdminUserService -> Banning user " << userId << ": " << reason << endl;
    }

    void promoteUser(const string &userId, const string &role) override
    {
        cout << "AdminUserService -> Promoting user " << userId << " to " << role << endl;
    }
};

// FullUserService implements all three interfaces
class FullUserService : public UserCrud, public AdminControls, public AuditLog
{
public:
    void createUser(const string &name, const string &email) override
    {
        cout << "FullUserService -> Creating user: " << name << " (" << email << ")" << endl;
    }

    string getUser(const string &userId) override
    {
        cout << "FullUserService -> Fetching user: " << userId << endl;
        return "User-" + userId;
    }

    void updateUser(const string &userId, const string &newEmail) override
    {
        cout << "FullUserService -> Updating user " << userId << " email to " << newEmail << endl;
    }

    void deleteUser(const string &userId) override
    {
        cout << "FullUserService -> Deleting user: " << userId << endl;
    }

    void banUser(const string &userId, const string &reason) override
    {
        cout << "FullUserService -> Banning user " << userId << ": " << reason << endl;
    }

    void promoteUser(const string &userId, const string &role) override
    {
        cout << "FullUserService -> Promoting user " << userId << " to " << role << endl;
    }

    vector<string> getLoginHistory(const string &userId) override
    {
        vector<string> history = {"2024-01-01", "2024-01-05"};
        cout << "FullUserService -> Login history for " << userId << ": [2024-01-01, 2024-01-05]" << endl;
        return history;
    }

    vector<string> getActivityLog(const string &userId) override
    {
        vector<string> log = {"created_post", "updated_profile"};
        cout << "FullUserService -> Activity log for " << userId << ": [created_post, updated_profile]" << endl;
        return log;
    }
};

int main()
{
    BasicUserService basic;
    basic.createUser("Alice", "alice@example.com");
    basic.getUser("u123");

    AdminUserService admin;
    admin.createUser("Bob", "bob@example.com");
    admin.banUser("u456", "spam");
    admin.promoteUser("u456", "admin");

    FullUserService full;
    full.createUser("Carol", "carol@example.com");
    full.banUser("u789", "abuse");
    full.getLoginHistory("u789");

    return 0;
}