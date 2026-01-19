# 1 "billing_app.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "billing_app.cpp"
# 1 "feature_toggle.hpp" 1
       



int calculatePrice(int price);


int applyDiscount(int price);
# 2 "billing_app.cpp" 2

int calculatePrice(int price) {
    return price;
}


int applyDiscount(int price) {
    return price - 50;
}


int main() {
    int bill = calculatePrice(500);

    bill = applyDiscount(bill);

    return 0;
}
