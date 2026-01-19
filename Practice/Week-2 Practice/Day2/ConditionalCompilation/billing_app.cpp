#include "feature_toggle.hpp"

int calculatePrice(int price) {
    return price;
}

#ifdef DISCOUNT_ON
int applyDiscount(int price) {
    return price - 50;
}
#endif

int main() {
    int bill = calculatePrice(500);
#ifdef DISCOUNT_ON
    bill = applyDiscount(bill);
#endif
    return 0;
}