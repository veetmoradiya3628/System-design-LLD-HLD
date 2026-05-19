#include <iostream>
#include <string>
#include <memory>

using namespace std;

class WeatherProvider
{
public:
    virtual ~WeatherProvider() = default;
    virtual string getWeather(const string &city) = 0;
};

class OpenWeatherMapProvider : public WeatherProvider
{
public:
    string getWeather(const string &city) override
    {
        cout << "Calling OpenWeatherMap API for: " << city << endl;
        return "Sunny, 25C";
    }
};

class WeatherStackProvider : public WeatherProvider
{
public:
    string getWeather(const string &city) override
    {
        cout << "Calling WeatherStack API for: " << city << endl;
        return "Cloudy, 18C";
    }
};

class WeatherApp
{
private:
    unique_ptr<WeatherProvider> provider;

public:
    WeatherApp(unique_ptr<WeatherProvider> p) : provider(move(p)) {}

    void displayWeather(const string &city)
    {
        string weather = provider->getWeather(city);
        cout << "Weather in " << city << ": " << weather << endl;
    }
};

int main()
{
    cout << "--- OpenWeatherMap ---" << endl;
    WeatherApp app1(make_unique<OpenWeatherMapProvider>());
    app1.displayWeather("London");

    cout << endl;
    cout << "--- WeatherStack ---" << endl;
    WeatherApp app2(make_unique<WeatherStackProvider>());
    app2.displayWeather("London");

    return 0;
}