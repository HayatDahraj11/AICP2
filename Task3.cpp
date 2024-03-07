#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

// Enum to represent days of the week
enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    NUM_DAYS
};

// Class representing a cow
class Cow {
private:
    string identityCode;
    vector<double> yields; // Stores yields for each day of the week

public:
    Cow(string id) : identityCode(id) {
        yields.resize(NUM_DAYS, 0.0);
    }

    void recordYield(Day day, double yield) {
        yields[day] = yield;
    }

    double getTotalYield() const {
        double total = 0.0;
        for (double yield : yields) {
            total += yield;
        }
        return total;
    }

    double getAverageYield() const {
        return getTotalYield() / NUM_DAYS;
    }

    bool isLowYield() const {
        int lowDays = 0;
        for (double yield : yields) {
            if (yield < 12.0) {
                lowDays++;
            }
        }
        return lowDays >= 4;
    }

    string getIdentityCode() const {
        return identityCode;
    }
};

int main() {
    // Map to store cows
    map<string, Cow> cowMap;

    // Record yields for each cow
    cout << "Recording yields for the week...\n";
    for (int i = 0; i < 3; ++i) { // Assume 3 cows for demonstration
        string id;
        cout << "Enter cow identity code (3 digits): ";
        cin >> id;
        Cow cow(id);
        for (int j = 0; j < NUM_DAYS; ++j) {
            double yield;
            cout << "Enter yield for " << id << " on " << Day(j) << ": ";
            cin >> yield;
            cow.recordYield(static_cast<Day>(j), yield);
        }
        cowMap.insert(make_pair(id, cow));
    }

    // Calculate statistics
    double totalVolume = 0.0;
    double totalCows = 0.0;
    string mostProductiveCow;
    double maxVolume = 0.0;

    cout << "\nCalculating statistics...\n";
    for (auto& pair : cowMap) {
        double total = pair.second.getTotalYield();
        double average = pair.second.getAverageYield();
        totalVolume += total;
        totalCows++;
        cout << "Cow " << pair.first << " Total Yield: " << total << " litres, Average Yield: " << average << " litres\n";

        if (total > maxVolume) {
            maxVolume = total;
            mostProductiveCow = pair.first;
        }

        if (pair.second.isLowYield()) {
            cout << "Cow " << pair.first << " has low yield for four or more days this week.\n";
        }
    }

    cout << "\nTotal weekly volume of milk for the herd: " << fixed << setprecision(1) << totalVolume << " litres\n";
    cout << "Average yield per cow in a week: " << fixed << setprecision(1) << totalVolume / totalCows << " litres\n";
    cout << "The most productive cow this week is: " << mostProductiveCow << " with a total yield of " << maxVolume << " litres\n";

    return 0;
}
