#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User;

class Message
{
private:
    User *author;
    string content;
    string timestamp;

public:
    Message(User *author, const string &content, const string &timestamp)
    {
        // TODO: Initialize fields
        this->author = author;
        this->content = content;
        this->timestamp = timestamp;
    }

    User *getAuthor() const { return author; }
    string getContent() const { return content; }
    string getTimestamp() const { return timestamp; }
};

class User
{
private:
    string name;
    vector<User *> followers;
    vector<User *> following;
    vector<Message *> messages;

    bool contains(const vector<User *> &list, User *user)
    {
        for (auto *u : list)
        {
            if (u == user)
                return true;
        }
        return false;
    }

public:
    User(const string &name) : name(name) {}

    void follow(User *user)
    {
        if (user == this)
            return;
        if (contains(following, user))
            return;
        following.push_back(user);
        user->followers.push_back(this);
    }

    void sendMessage(const string &content, const string &timestamp)
    {
        messages.push_back(new Message(this, content, timestamp));
    }

    string getName() const { return name; }
    vector<User *> getFollowers() const { return followers; }
    vector<User *> getFollowing() const { return following; }
    vector<Message *> getMessages() const { return messages; }
};

int main()
{
    User alice("Alice");
    User bob("Bob");
    User charlie("Charlie");

    alice.follow(&bob);
    alice.follow(&charlie);
    bob.follow(&alice);

    alice.sendMessage("Hello world!", "10:00 AM");
    bob.sendMessage("Learning OOP!", "10:30 AM");

    cout << alice.getName() << " is following:" << endl;
    for (auto *u : alice.getFollowing())
        cout << "  - " << u->getName() << endl;

    cout << bob.getName() << "'s followers:" << endl;
    for (auto *u : bob.getFollowers())
        cout << "  - " << u->getName() << endl;

    cout << alice.getName() << "'s messages:" << endl;
    for (auto *m : alice.getMessages())
        cout << "  [" << m->getTimestamp() << "] " << m->getContent() << endl;

    return 0;
}