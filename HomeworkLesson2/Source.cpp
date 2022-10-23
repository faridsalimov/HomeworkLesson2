#include <iostream>

using namespace std;

// ======================================================
//														|
// Kechilenlerin her biri istifade olunsun              |
// Initializer list, Delegate, getter setter            |
//                                                      |
// class : Product                                      |
//	 fields : id, name, description, price, discount    |
//	 methods : ShowProduct(), GetPriceWithDiscount()    |
//                                                      |
// ======================================================

class Product {
	int id = 0;
	char* name = nullptr;
	char* description = nullptr;
	int price = 0;
	int discount = 0;
	
public:
	Product() : id(0), name(nullptr), description(nullptr), price(0), discount(0) {}

	Product(int id, const char* name, const char* description, int price, int discount) {
		SetId(id);
		SetName(name);
		SetDescription(description);
		SetPrice(price);
		SetDiscount(discount);
	}

#pragma region Setters
	void SetId(int id) {
		id = 0 < id ? id : 0;
		this->id = id;
	}

	void SetName(const char* name) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void SetDescription(const char* description) {
		delete[] this->description;
		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}

	void SetPrice(int price) {
		price = 0 < price ? price : 0;
		this->price = price;
	}

	void SetDiscount(int discount) {
		discount = 0 < discount ? discount : 0;
		this->discount = discount;
	}
#pragma endregion

#pragma region Getters
	int GetId() { return id; }
	const char* GetName() { return name; }
	const char* GetDescription() { return description; }
	int GetPrice() { return price; }
	int GetDiscount() { return discount; }
#pragma endregion

	void ShowProduct() {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Description: " << description << endl;
		cout << "Price: " << price << " AZN" << endl;
		cout << "Discount: " << discount << "%" << endl;
	}

	void GetPriceWithDiscount() {
		int resultPrice = price - (price * discount / 100);

		cout << "\n>> Price With Discount:" << endl;
		cout << "Name: " << name << endl;
		cout << "Price: " << resultPrice << " AZN" << endl;
	}

	~Product()
	{
		delete[] name;
		delete[] description;
	}
};

void main() {
	Product* product = new Product(1, "IPhone X", "A smartphone.", 1500, 50);
	product->ShowProduct();
	product->GetPriceWithDiscount();
}