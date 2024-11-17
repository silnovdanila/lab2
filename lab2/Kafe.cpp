#include "Kafe.h"
#include <stdio.h>

struct Dish;
struct Employee;
struct Order;
struct Chef;
struct Menu;
struct DiscountCard;
struct Waiter;
struct Client;

void initMenu(struct Menu menu) {
	menu.dessertAmount = 0;
	menu.drinkAmount = 0;
	menu.hotDishAmount = 0;
}
void addHotDish(struct Menu menu, struct Dish dish) {
	menu.hotDishes[menu.hotDishAmount++] = dish;
}
void addDessert(struct Menu menu, struct Dish dish) {
	menu.desserts[menu.dessertAmount++] = dish;
}
void addDrink(struct Menu menu, struct Dish dish) {
	menu.drinks[menu.drinkAmount++] = dish;
}
void menuOut(struct Menu menu) {
	printf("\nHot Dishes:\n");
	for (int i = 0; i < menu.hotDishAmount; i++) {
		printf("%d - %s", i + 1, menu.hotDishes[i].name);
	}
	printf("\nDesserts:\n");
	for (int i = 0; i < menu.dessertAmount; i++) {
		printf("%d - %s", i + 1 + menu.hotDishAmount, menu.desserts[i].name);
	}
	printf("\nDrinks:\n");
	for (int i = 0; i < menu.drinkAmount; i++) {
		printf("%d - %s", i + 1 + menu.hotDishAmount + menu.dessertAmount, menu.drinks[i].name);
	}
}
