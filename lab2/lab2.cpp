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
    struct Employee povar = { 31000, "Povar" };
    struct Chef povar1 = { "Vasiliy", povar, NULL };
    struct Chef povar2 = { "Gregory", povar, NULL };
    struct Employee waiter = { 22000, "Waiter" };
    struct Waiter waiter1 = { "Anna", waiter, NULL, NULL};

    int order[20], dish;

    struct Client client1 = getNewClient();
    getOrder(client1, waiter1, povar1, menu, order);
    dish = madeOrder(&client1, &waiter1, &povar1, menu, order);
    payClient(&client1, dish);
    addHistory(&client1);

    struct Client client2 = getNewClient();
    getOrder(client2, waiter1, povar2, menu, order);
    dish = madeOrder(&client2, &waiter1, &povar2, menu, order);
    payClient(&client2, dish);
    addHistory(&client2);

    getOrder(client1, waiter1, povar1, menu, order);
    dish = madeOrder(&client1, &waiter1, &povar1, menu, order);
    payClient(&client1, dish);
    addHistory(&client1);
}
