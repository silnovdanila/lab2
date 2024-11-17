#include <stdio.h>
#include "Kafe.h"

int main()
{
    struct Menu menu {};
    initMenu(&menu);
    struct Dish hotdish1 = { 1200, "Chicken" };
    struct Dish hotdish2 = { 800, "Fish" };
    struct Dish dessert1 = { 500, "Cake" };
    struct Dish drink1 = { 120, "Tea" };
    addHotDish(&menu, hotdish1);
    addHotDish(&menu, hotdish2);
    addDessert(&menu, dessert1);
    addDrink(&menu, drink1);
    menuOut(menu);
}
