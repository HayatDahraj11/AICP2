#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Enum to represent the status of an item
enum ItemStatus {
    UNSOLD,
    SOLD_BELOW_RESERVE,
    SOLD_ABOVE_RESERVE
};

// Class representing an item in the auction
class AuctionItem {
private:
    int itemNumber;
    string description;
    double reservePrice;
    double highestBid;
    int numBids;

public:
    AuctionItem(int number, string desc, double reserve) 
        : itemNumber(number), description(desc), reservePrice(reserve), highestBid(0.0), numBids(0) {}

    // Getters
    int getItemNumber() const { return itemNumber; }
    string getDescription() const { return description; }
    double getReservePrice() const { return reservePrice; }
    double getHighestBid() const { return highestBid; }
    int getNumBids() const { return numBids; }

    // Method to record a bid
    bool recordBid(double bid) {
        if (bid > highestBid) {
            highestBid = bid;
            numBids++;
            return true;
        }
        return false;
    }

    // Method to check if item has reached reserve price
    ItemStatus checkStatus() const {
        if (highestBid >= reservePrice)
            return SOLD_ABOVE_RESERVE;
        else if (numBids > 0)
            return SOLD_BELOW_RESERVE;
        else
            return UNSOLD;
    }
};

int main() {
    // Vector to store auction items
    vector<AuctionItem> items;

    // Task 1 - Auction setup
    cout << "Auction set up...\n";
    for (int i = 0; i < 10; ++i) {
        int itemNumber;
        string description;
        double reservePrice;

        cout << "Enter details for item " << i + 1 << ":\n";
        cout << "Item number: ";
        cin >> itemNumber;
        cout << "Description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Reserve price: ";
        cin >> reservePrice;

        AuctionItem item(itemNumber, description, reservePrice);
        items.push_back(item);
    }

    // Task 2 - Buyer bids
    cout << "\nBuyer bids...\n";
    while (true) {
        int itemNumber, buyerNumber;
        double bid;

        cout << "\nEnter item number (or -1 to exit): ";
        cin >> itemNumber;
        if (itemNumber == -1)
            break;

        // Find the item
        AuctionItem* currentItem = nullptr;
        for (auto& item : items) {
            if (item.getItemNumber() == itemNumber) {
                currentItem = &item;
                break;
            }
        }

        if (currentItem == nullptr) {
            cout << "Item not found.\n";
            continue;
        }

        cout << "Item description: " << currentItem->getDescription() << endl;
        cout << "Current highest bid: " << currentItem->getHighestBid() << endl;

        cout << "Enter your buyer number: ";
        cin >> buyerNumber;
        cout << "Enter your bid: ";
        cin >> bid;

        if (currentItem->recordBid(bid))
            cout << "Bid recorded successfully.\n";
        else
            cout << "Your bid must be higher than the current highest bid.\n";
    }

    // Task 3 - At the end of the auction
    cout << "\nEnd of auction...\n";
    double totalFee = 0.0;
    int soldItems = 0, itemsBelowReserve = 0, unsoldItems = 0;

    for (auto& item : items) {
        ItemStatus status = item.checkStatus();
        switch (status) {
            case SOLD_ABOVE_RESERVE:
                cout << "Item " << item.getItemNumber() << " sold for " << item.getHighestBid() << " (above reserve)\n";
                totalFee += 0.1 * item.getHighestBid();
                soldItems++;
                break;
            case SOLD_BELOW_RESERVE:
                cout << "Item " << item.getItemNumber() << " sold for " << item.getHighestBid() << " (below reserve)\n";
                itemsBelowReserve++;
                break;
            case UNSOLD:
                cout << "Item " << item.getItemNumber() << " received no bids.\n";
                unsoldItems++;
                break;
        }
    }

    cout << "Total fee for sold items: " << totalFee << endl;
    cout << "Number of items sold: " << soldItems << endl;
    cout << "Number of items sold below reserve: " << itemsBelowReserve << endl;
    cout << "Number of unsold items: " << unsoldItems << endl;

    return 0;
}
