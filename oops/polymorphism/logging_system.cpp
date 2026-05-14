#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Logger
{
public:
    virtual ~Logger() {}

    virtual void log(const string &level, const string &message) = 0;
    virtual string getDestination() = 0;
};

class ConsoleLogger : public Logger
{
public:
    void log(const string &level, const string &message) override
    {
        cout << "[" << level << "] " << message << endl;
    }

    string getDestination() override
    {
        return "Console";
    }
};

class FileLogger : public Logger
{
private:
    string filePath;

public:
    FileLogger(const string &filePath)
    {
        this->filePath = filePath;
    }

    void log(const string &level, const string &message) override
    {
        cout << "Writing to " << filePath
             << ": [" << level << "] "
             << message << endl;
    }

    string getDestination() override
    {
        return "File: " + filePath;
    }
};

class DatabaseLogger : public Logger
{
private:
    string tableName;

public:
    DatabaseLogger(const string &tableName)
    {
        this->tableName = tableName;
    }

    void log(const string &level, const string &message) override
    {
        cout << "INSERT INTO " << tableName
             << ": [" << level << "] "
             << message << endl;
    }

    string getDestination() override
    {
        return "Database: " + tableName;
    }
};

class Application
{
private:
    Logger *logger;

public:
    Application(Logger *logger)
    {
        this->logger = logger;
    }

    void run()
    {
        logger->log("INFO", "Application starting...");
        logger->log("INFO", "Processing data...");
        logger->log("INFO", "Application shutting down.");
    }
};

int main()
{
    ConsoleLogger console;
    FileLogger file("/var/log/app.log");
    DatabaseLogger db("app_logs");

    vector<Logger *> loggers = {&console, &file, &db};

    for (auto *logger : loggers)
    {
        cout << "--- Using " << logger->getDestination() << " ---" << endl;

        Application app(logger);
        app.run();

        cout << endl;
    }

    return 0;
}