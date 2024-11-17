#define _CRT_SECURE_NO_WARNINGS
#include "Kafe.h"
#include <stdio.h>

int id = 0; //Discount card id

struct Dish;
struct Employee;
struct Order;
struct Chef;
struct Menu;
struct DiscountCard;
struct Waiter;
struct Client;

void initMenu(struct Menu *menu) {
	menu->dessertAmount = 0;
	menu->drinkAmount = 0;
	menu->hotDishAmount = 0;
}
void addHotDish(Menu *menu, Dish dish) {
	menu->hotDishes[menu->hotDishAmount] = dish;
	menu->hotDishAmount += 1;
}
void addDessert(Menu *menu, Dish dish) {
	menu->desserts[menu->dessertAmount] = dish;
	menu->dessertAmount += 1;
}
void addDrink(Menu *menu, Dish dish) {
	menu->drinks[menu->drinkAmount] = dish;
	menu->drinkAmount += 1;
}
void menuOut(Menu menu) {
	printf("\n\n   MENU");
	printf("\nHot Dishes:\n");
	for (int i = 0; i < menu.hotDishAmount; i++) {
		printf("%d - %s\n", i + 1, menu.hotDishes[i].name);
	}
	printf("\nDesserts:\n");
	for (int i = 0; i < menu.dessertAmount; i++) {
		printf("%d - %s\n", i + 1 + menu.hotDishAmount, menu.desserts[i].name);
	}
	printf("\nDrinks:\n");
	for (int i = 0; i < menu.drinkAmount; i++) {
		printf("%d - %s\n", i + 1 + menu.hotDishAmount + menu.dessertAmount, menu.drinks[i].name);
	}
}
struct DiscountCard getNewCard() {
	DiscountCard card = { id++, 0, NULL };
	return card;
}
void makeOrder(Client* client, Waiter* waiter, Chef* povar,Menu menu, int sp[]) {
	Dish dishes[20];
	int dish = 0;
	for (int i = 0; sp[i] != 0; i++) {
		if (sp[i] <= menu.hotDishAmount) {
			dishes[dish++] = menu.hotDishes[sp[i]];
		}
		else if (sp[i] <= menu.hotDishAmount + menu.dessertAmount) {
			dishes[dish++] = menu.desserts[sp[i] - menu.hotDishAmount];
		}
		else {
			dishes[dish++] = menu.drinks[sp[i] - menu.hotDishAmount - menu.dessertAmount];
		}
	}
	struct Order newOrder = {dishes};
	client->currentOrder = newOrder;
}
void getOrder(Client client, Waiter waiter, Chef povar, Menu menu, int order[]) {
	int num;
	printf("\nHello, %s", client.name);
	printf("\nYour waiter - %s", waiter.name);
	printf("\nYour chef - %s", povar.name);
	printf("\nHere is the menu");
	again:
	menuOut(menu);
	printf("\nHow many dishes ypu want to order. Enter number < 20 - ");
	scanf("%d", &num);
	if (num <= 0 || num >= 20) goto again;
	printf("\nTo place an order, enter the number of items you want to order - ");
	int i = 0;
	for (i; i < num; i++) {
		scanf("%d", &order[i]);
	}
	order[i] = 0;
}
void payClient(Client client) {

}
