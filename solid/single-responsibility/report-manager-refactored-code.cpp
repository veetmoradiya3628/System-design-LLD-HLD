#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class ReportGenerator
{
public:
    vector<vector<string>> generate()
    {
        return {
            {"Name", "Sales", "Region"},
            {"Alice", "15000", "North"},
            {"Bob", "22000", "South"},
            {"Charlie", "18000", "East"}};
    }
};

class ReportFormatter
{
public:
    string formatAsCsv(const vector<vector<string>> &data)
    {
        ostringstream oss;
        for (size_t i = 0; i < data.size(); i++)
        {
            for (size_t j = 0; j < data[i].size(); j++)
            {
                if (j > 0)
                    oss << ",";
                oss << data[i][j];
            }
            if (i < data.size() - 1)
                oss << "\n";
        }
        return oss.str();
    }
};

class ReportDistributor
{
public:
    void distribute(const string &recipient, const string &formattedReport)
    {
        cout << "Sending report to: " << recipient << endl;
        cout << formattedReport << endl;
        cout << "Report sent successfully." << endl;
    }
};

int main()
{
    ReportGenerator generator;
    ReportFormatter formatter;
    ReportDistributor distributor;

    auto data = generator.generate();
    string csv = formatter.formatAsCsv(data);
    distributor.distribute("manager@company.com", csv);
    return 0;
}