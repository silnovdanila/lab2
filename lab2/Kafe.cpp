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
	printf("\n\n\tMENU");
	printf("\nHot Dishes:\n");
	for (int i = 0; i < menu.hotDishAmount; i++) {
		printf("%d - %s\t%d\n", i + 1, menu.hotDishes[i].name, menu.hotDishes[i].price);
	}
	printf("\nDesserts:\n");
	for (int i = 0; i < menu.dessertAmount; i++) {
		printf("%d - %s\t%d\n", i + 1 + menu.hotDishAmount, menu.desserts[i].name, menu.desserts[i].price);
	}
	printf("\nDrinks:\n");
	for (int i = 0; i < menu.drinkAmount; i++) {
		printf("%d - %s \t%d\n", i + 1 + menu.hotDishAmount + menu.dessertAmount, menu.drinks[i].name, menu.drinks[i].price);
	}
}
struct DiscountCard getNewCard() {
	DiscountCard card = { id++, 0, NULL, 0 };
	return card;
}
int madeOrder(Client* client, Waiter* waiter, Chef* povar, Menu menu, int sp[]) {
	struct Dish dishes[20];
	int dish = 0;
	for (int i = 0; sp[i] != 0; i++) {
		if (sp[i] <= menu.hotDishAmount) {
			dishes[dish] = menu.hotDishes[sp[i] - 1];
		}
		else if (sp[i] <= menu.hotDishAmount + menu.dessertAmount) {
			dishes[dish] = menu.desserts[sp[i] - menu.hotDishAmount - 1];
		}
		else {
			dishes[dish] = menu.drinks[sp[i] - menu.hotDishAmount - menu.dessertAmount - 1];
		}
		dish += 1;
	}
	struct Order newOrder = { NULL };
	int i = 0;
	while (i != dish) {
		newOrder.Dishes[i] = &dishes[i];
		i++;
	}
	client->currentOrder = newOrder;
	waiter->currentOrder = newOrder;
	povar->currentOrder = newOrder;
	return dish;
}
void getOrder(Client client, Waiter waiter, Chef povar, Menu menu, int order[]) {
	int num;
	printf("\nHello, %s", client.name);
	printf("\nYour waiter - %s", waiter.name);
	printf("\nYour chef - %s", povar.name);
	printf("\nHere is the menu");
	menuOut(menu);
	printf("\nHow many dishes ypu want to order. Enter number < 20 - ");
	scanf("%d", &num);
	printf("\nTo place an order, enter the number of items you want to order - ");
	int i = 0;
	for (i; i < num; i++) {
		scanf("%d", &order[i]);
	}
	order[i] = 0;
}
int orderSum(Client *client, int dish) {
	int sum = 0;
	struct Client *client1 = client;
	printf("\nYour order: ");
	for (int i = 0; i < dish; i++) {
		printf("%s ", &client1->currentOrder.Dishes[i]->name);
		sum += client1->currentOrder.Dishes[i]->price;
	}
	return sum;
}
void payClient(Client *client, int dish) {
	int sum;
	sum = orderSum(client, dish);
	printf("\nThe price of order is %.2lf rub, your discount is %.2lf\%", sum * (1 - client->Card.discount), client->Card.discount);
	printf("\nEnter the card details for the payment: ");
	scanf("%d", &sum);
	printf("\nThe payment was successful");
}
struct Client getNewClient() {
	struct Client client;
	printf("\nWelcome to the cafe ");
	printf("\nPlease, enter your name - ");
	scanf("%s", client.name);
	client.Card = getNewCard();
	return client;
}
double getDiscount(double discount) {
	if (discount >= 0.089) {
		return 0.1;
	}
	else {
		return discount += 0.01;
	}
}
void addHistory(Client *client) {
	client->Card.discount = getDiscount(client->Card.discount);
	client->Card.historyOForders[client->Card.orders] = client->currentOrder;
	client->Card.orders += 1;
}
