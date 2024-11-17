#pragma once


struct Dish {
	int price;
	char name[20];
};
struct Employee {
	int salary;
	char job[20];
};
struct Order {
	struct Dish *Dishes[20];
};
struct Chef {
	char name[20];
	struct Employee chef;
	struct Order currentOrder;
};
struct Menu {
	struct Dish hotDishes[10];
	struct Dish desserts[10];
	struct Dish drinks[10];
	int hotDishAmount;
	int dessertAmount;
	int drinkAmount;
};
struct DiscountCard {
	int id;
	double discount;
	struct Order historyOForders[20];
};
struct Client {
	char name[20];
	struct DiscountCard Card;
	struct Order currentOrder;
};
struct Waiter {
	char name[20];
	struct Employee waiter;
	struct Client currentClient;
	struct Order currentOrder;
};
void initMenu(struct Menu *menu);
void addHotDish(struct Menu *menu, struct Dish dish);
void addDessert(struct Menu *menu, struct Dish dish);
void addDrink(struct Menu *menu, struct Dish dish);
void menuOut(struct Menu menu);
struct DiscountCard getNewCard();
int madeOrder(Client* client, Waiter* waiter, Chef* povar, Menu menu, int sp[]);
void getOrder(Client client, Waiter waiter, Chef povar, Menu menu, int order[]);
void payClient(Client *client, int dish);
int orderSum(Client *client, int dish);