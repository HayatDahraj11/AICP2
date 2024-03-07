#include <iostream>
#include <string>
#include <map>

enum DayOfWeek { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

class ParkingRate {
public:
    double dayRate;
    double nightRate;
    int maxHours;

    ParkingRate(double dayRate = 0.0, double nightRate = 0.0, int maxHours = 0) 
    : dayRate(dayRate), nightRate(nightRate), maxHours(maxHours) {}
};

class CarPark {
private:
    std::map<DayOfWeek, ParkingRate> rates;
    double dailyTotal = 0;

    bool isValidFrequentNumber(int number) {
        return (number % 11) == 0; // Placeholder validation logic
    }

public:
    CarPark() {
        // Initialize parking rates for each day
        rates[Sunday] = ParkingRate(2.00, 2.00, 8);
        rates[Monday] = ParkingRate(10.00, 2.00, 2);
        rates[Tuesday] = ParkingRate(10.00, 2.00, 2);
        rates[Wednesday] = ParkingRate(10.00, 2.00, 2);
        rates[Thursday] = ParkingRate(10.00, 2.00, 2);
        rates[Friday] = ParkingRate(10.00, 2.00, 2);
        rates[Saturday] = ParkingRate(3.00, 2.00, 4);
    }

    double calculateCharge(DayOfWeek day, int arrivalHour, int parkingHours, int frequentNumber) {
        const ParkingRate& rate = rates[day];
        double charge = 0.0;
        int discount = (arrivalHour >= 16) ? 50 : 10;

        if (!isValidFrequentNumber(frequentNumber)) {
            discount = 0; // No discount if the frequent number is invalid
        }

        // Calculate charge based on the arrival time and the parking duration
        if (arrivalHour < 16) {
            int dayHours = std::min(parkingHours, 16 - arrivalHour);
            int nightHours = parkingHours - dayHours;
            charge = (dayHours * rate.dayRate) + (nightHours * rate.nightRate);
        } else {
            charge = parkingHours * rate.nightRate;
        }

        // Apply discount
        charge -= charge * discount / 100.0;

        return charge;
    }

    void processPayment(double amount) {
        // Update the daily total with the received amount
        dailyTotal += amount;
    }

    void resetDailyTotal() {
        dailyTotal = 0;
    }

    double getDailyTotal() const {
        return dailyTotal;
    }
};

int main() {
    CarPark carPark;
    int day, hour, hours, frequentNumber;
    std::cout << "Enter day of week (0=Sunday, 6=Saturday), arrival hour (0-23), parking hours, and frequent parking number: ";
    std::cin >> day >> hour >> hours >> frequentNumber;

    double charge = carPark.calculateCharge(static_cast<DayOfWeek>(day), hour, hours, frequentNumber);
    std::cout << "Parking charge: $" << charge << std::endl;

    carPark.processPayment(charge);
    std::cout << "Daily total: $" << carPark.getDailyTotal() << std::endl;

    return 0;
}
