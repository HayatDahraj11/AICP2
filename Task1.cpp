#include <iostream>
#include <string>

using namespace std;

class PupilRecord 
{
private:
    static const int MAX_PUPILS = 30;
    string names[MAX_PUPILS];
    double weights[MAX_PUPILS];
    double weightDifference[MAX_PUPILS];

public:
    void inputWeightsAndNames() 
    {
        cout << "Enter the names and weights for the class of 30 pupils:" << endl;

        for (int i = 0; i < MAX_PUPILS; ++i) 
        {

            
            cout << "Enter name for pupil " << i + 1 << ": ";
            cin >> names[i];

            do 
            
            {
                cout << "Enter weight for pupil " << i + 1 << " in kilograms: ";
                cin >> weights[i];

                if (weights[i] <= 0) 
                {
                    cout << "Invalid weight! Weight must be greater than zero." << endl;
                }
            } while (weights[i] <= 0);
        }
    }

    void calculateWeightDifference() 
    {
        cout << "\nRecording weights on the last day of term:" << endl;

        for (int i = 0; i < MAX_PUPILS; ++i) 
        {
            double lastDayWeight;
            cout << "Enter weight for pupil " << i + 1 << " on the last day of term: ";
            cin >> lastDayWeight;

            weightDifference[i] = lastDayWeight - weights[i];
        }
    }

    void outputPupilData() 
    {
        cout << "\nNames and Weights of Pupils:" << endl;

        for (int i = 0; i < MAX_PUPILS; ++i) {
            cout << "Name: " << names[i] << ", Weight: " << weights[i] << " kg" << endl;
        }
    }

    void outputWeightDifference() 
    {
        cout << "\nWeight Differences:" << endl;

        for (int i = 0; i < MAX_PUPILS; ++i) {
            cout << "Name: " << names[i] << ", Difference: " << weightDifference[i] << " kg" << endl;
        }
    }

    void outputRiseOrFall()
    {
        cout << "\nPupils with a difference in weight more than 2.5 kilograms:" << endl;

        for (int i = 0; i < MAX_PUPILS; ++i) 
        {
            if (abs(weightDifference[i]) > 2.5) 
            {
                cout << "Name: " << names[i] << ", Difference: " << weightDifference[i] << " kg";
                cout << (weightDifference[i] > 0 ? " (Rise)" : " (Fall)") << endl;
            }
        }
    }
};

int main() 
{
    PupilRecord pupilRecord;

    pupilRecord.inputWeightsAndNames();
    pupilRecord.calculateWeightDifference();

    pupilRecord.outputPupilData();
    pupilRecord.outputWeightDifference();

    pupilRecord.outputRiseOrFall();

    return 0;
}
