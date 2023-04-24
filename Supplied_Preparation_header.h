#pragma once
#include <windows.h>
#include <String.h>
#include <stdexcept>
// підключення просторів імен std і System

using namespace System;
using namespace std;
// оголошення класу
ref class supplied_Preparation2 {
	//закриті поля класу для збереження даних
	String^ Amount;
	String^ Price;
	String^ Address_of_Delivery;
	String^ Paid;
	String^ preparation;
	int id;
public: // відкриті члени класу
	supplied_Preparation2() {}// порожній конструктор
// конструктор ініціалізаціі полів об’єктів класу
	supplied_Preparation2(String^ t, String^ m, String^ c, String^ r, String^ p, int i) {
		this->Amount = t;
		this->Price = m;
		this->Address_of_Delivery = c;
		this->Paid = r;
		this->preparation = p;
		if (i > 0) {
			this->id = i;
		}
		else throw invalid_argument("Wrong id");
		// обробка помилки при спробі ввести код запису, менший або рівний 0
	}

	void setAmount(String^ Amount) {
		if (Amount->Length != 0) {
			this->Amount = Amount;
		}
		else throw invalid_argument("Wrong nazva");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getAmount() {
		return this->Amount;
	}

	void setPrice(String^ Price) {
		if (Price->Length != 0) {
			this->Price = Price;
		}
		else throw invalid_argument("Wrong forma");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getPrice() {
		return this->Price;
	}
	void setAddress_of_Delivery(String^ Address_of_Delivery) {
		if (Address_of_Delivery->Length != 0) {
			this->Address_of_Delivery = Address_of_Delivery;
		}
		else throw invalid_argument("Wrong price");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getAddress_of_Delivery() {
		return this->Address_of_Delivery;
	}
	void setPaid(String^ Paid) {
		if (Paid->Length != 0) {
			this->Paid = Paid;
		}
		else throw invalid_argument("Wrong data");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getPaid() {
		return this->Paid;
	}

	void setpreparation(String^ preparation) {
		if (preparation->Length != 0) {
			this->preparation = preparation;
		}
		else throw invalid_argument("Wrong data");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getpreparation() {
		return this->preparation;
	}

	void setId(int id) {
		if (id > 0) {
			this->id = id;
		}
		else throw invalid_argument("Wrong id");
		// обробка помилки при спробі ввести код запису, менший або рівний 0
	}
	int getId() {
		return this->id;
	}

};

