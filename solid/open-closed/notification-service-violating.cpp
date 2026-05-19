#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class NotificationService
{
public:
    void sendNotification(const string &channel, const string &message)
    {
        if (channel == "Email")
        {
            cout << "Sending EMAIL: " << message << endl;
            // Email-specific logic
        }
        else if (channel == "SMS")
        {
            cout << "Sending SMS: " << message << endl;
            // SMS-specific logic
        }
        else
        {
            throw invalid_argument("Unknown channel: " + channel);
        }
    }
};

int main()
{
    NotificationService service;
    service.sendNotification("Email", "Your order has shipped!");
    service.sendNotification("SMS", "Your order has shipped!");
    return 0;
}

// TODO: Define a NotificationChannel interface with a send(message) method.
// TODO: Create EmailChannel, SMSChannel, PushChannel, and SlackChannel.
// TODO: Refactor NotificationService to accept a NotificationChannel.