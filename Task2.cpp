#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

//I am unable to record a video because of academic burden, however I full fully explain the  code
//ENUMS and classes used + vectors

using namespace std;
// Enum for different age group ranges
enum AgeGroup 
{
    GROUP_12_16,
    GROUP_17_26,
    GROUP_27_39
};

// Class for outing cost calculator
class OutingCostCalculator 
{
private:
    const double coachCosts[3] = {150, 190, 225}; // Coach costs for each age group
    const double mealCosts[3] = {14.00, 13.50, 13.00}; // Meal costs for each age group
    const double theatreTicketCosts[3] = {21.00, 20.00, 19.00}; // Theatre ticket costs for each age group
    
public:
    // Function to calculate total cost for an outing based on the number of senior citizens
    double calculateTotalCost(int numOfSeniors)
     {
        AgeGroup ageGroup;
        if (numOfSeniors >= 12 && numOfSeniors <= 16)
            ageGroup = GROUP_12_16;
        else if (numOfSeniors >= 17 && numOfSeniors <= 26)
            ageGroup = GROUP_17_26;
        else if (numOfSeniors >= 27 && numOfSeniors <= 39)
            ageGroup = GROUP_27_39;
        else {
            cout << "Error: Number of seniors must be between 12 and 39." << endl;
            return -1; // Return -1 to indicate error
        }
        


        double totalCost = coachCosts[ageGroup] + mealCosts[ageGroup] + theatreTicketCosts[ageGroup];
        return totalCost;
    }
    
    // Function to calculate cost per person for an outing based on the number of senior citizens
    double calculateCostPerPerson(int numOfSeniors) 
    
    {
        return calculateTotalCost(numOfSeniors) / numOfSeniors;
    }
};

// Class for managing outing participants and payments
class OutingManager 

{
private:
    vector<std::string> participants;
    vector<double> payments;
    
public:
    // Function to add participant and their payment
    void addParticipant(const std::string& name, double payment)
    
     {
        participants.push_back(name);
        payments.push_back(payment);
    }
    
    // Function to calculate total amount that is collected
    double calculateTotalCollected()
    
     {
        double total = 0;
        for (double payment : payments) 
        
        
        {
            total += payment;
        }
        return total;
    }
    
    // Function here is implemnted to print list of participants
    void printParticipantList() 
    {
        cout << "Participant List:" << endl;
        for (size_t i = 0; i < participants.size(); ++i) {
            cout << participants[i] << " - $" << payments[i] << endl;
        }
    }
};

int main() 

{
    OutingCostCalculator costCalculator;
    OutingManager outingManager;

    int numOfSeniors;
    cout << "Enter the number of senior citizens attending the outing: ";
    cin >> numOfSeniors;

    double totalCost = costCalculator.calculateTotalCost(numOfSeniors);
    if (totalCost != -1) 
    {
        double costPerPerson = costCalculator.calculateCostPerPerson(numOfSeniors);
        cout << "Total cost for the outing: $" << fixed << setprecision(2) << totalCost << std::endl;
        cout << "Cost per person: $" << costPerPerson <<endl;

        // Task 2
        string name;
        double payment;
        cout << " Please  enter name and payment for each participant:" << endl;
        for (int i = 0; i < numOfSeniors; ++i) 
        {
            cout << "Participant   " << i + 1 << ": ";
            cin >> name >> payment;
            outingManager.addParticipant(name, payment);
        }

        // Task 3 is done here
        double totalCollected = outingManager.calculateTotalCollected();
        cout << "Total amount ccollected is : $" << totalCollected << endl;
        outingManager.printParticipantList();

        // Checking if profit or break-even
        double profit = totalCollected - totalCost;
        if (profit >= 0)

            cout << "The outing hs   made a profit of $" << profit << endl;

        else
            cout << "The outing has broken even." << endl;
    }

    return 0;
}
