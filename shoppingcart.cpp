#include <iostream>
#include <vector>
#include <algorithm>

struct Product {
    std::string name;
    int up;
    int gstpercent;
    int quantity;
};

int main() {
    std::vector<Product> basket = {
        {"leather wallet", 1100, 18, 1},
        {"umbrella", 900, 12, 4},
        {"cigarette", 200, 28, 3},
        {"honey", 100, 0, 2}
    };

    auto maxgstproduct = std::max_element(basket.begin(), basket.end(),
        [](const Product& a, const Product& b) {
            return (a.up * a.gstpercent) < (b.up * b.gstpercent);
        });

    std::cout << "The product with maximum GST amount is " << maxgstproduct->name << std::endl;


    double totalamt = 0;

    for (const auto& item : basket) {
        double totalproduct = item.up * item.quantity;
        double gstamt = (totalproduct * item.gstpercent) / 100;
        totalamt += totalproduct + gstamt;

        if (item.up >= 500) {
            totalamt -= (item.up * item.quantity * 5) / 100;
        }
    }

    std::cout << "The total amount to be paid to the shopkeeper is Rs " << totalamt << std::endl;

    return 0;
}
