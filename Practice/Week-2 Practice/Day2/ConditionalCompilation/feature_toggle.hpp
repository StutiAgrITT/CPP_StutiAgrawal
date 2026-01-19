#pragma once

//#define DISCOUNT_ON //commented / uncommented for different outcomes

int calculatePrice(int price);

#ifdef DISCOUNT_ON 
int applyDiscount(int price);
#endif