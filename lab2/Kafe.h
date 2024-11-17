#pragma once


struct Dish {
	int price;
	char name[20];
};
struct Employee {
	int salary;
	char job[20];
	char name[20];
};
struct Order {
	struct Dish Dishes[20];
};
struct Chef {
	struct Employee chef;
	struct Dish currentDish;
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
	char name[20];
	double discount;
	struct Order historyOForders[20];
};
struct Client {
	struct Order currentOrder;
	struct DiscountCard Card;
};
struct Waiter {
	struct Employee waiter;
	struct Client currentClient;
	struct Order currentOrder;
};
void initMenu(struct Menu *menu);
void addHotDish(struct Menu *menu, struct Dish dish);
void addDessert(struct Menu *menu, struct Dish dish);
void addDrink(struct Menu *menu, struct Dish dish);
void menuOut(struct Menu menu);