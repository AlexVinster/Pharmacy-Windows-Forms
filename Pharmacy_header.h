#pragma once
#include <windows.h>
#include <String.h>
#include <stdexcept>
#include <list>
// підключення просторів імен std і System

using namespace System;
using namespace std;
// оголошення класу
ref class pharmacy2 {
	//закриті поля класу для збереження даних країну, місце та глибину ареалу
	String^ Name;
	String^ Address;
	String^ Contact_number;
	String^ Open_24_hours;
	String^ Work_time;
	int id;
public: // відкриті члени класу
	pharmacy2() {}// порожній конструктор
// конструктор ініціалізаціі полів об’єктів класу
	pharmacy2(String^ n, String^ t, String^ a, String^ w, String^ s, int i) {
		this->Name = n;
		this->Address = t;
		this->Contact_number = a;
		this->Open_24_hours = w;
		this->Work_time = s;
		if (i > 0) {
			this->id = i;
		}
		else throw invalid_argument("Wrong id");
		// обробка помилки при спробі ввести код запису, менший або рівний 0
	}

	void setName(String^ Name) {
		if (Name->Length != 0) {
			this->Name = Name;
		}
		else throw invalid_argument("Wrong nazva");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getName() {
		return this->Name;
	}

	void setAddress(String^ Address) {
		if (Address->Length != 0) {
			this->Address = Address;
		}
		else throw invalid_argument("Wrong phone");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getAddress() {
		return this->Address;
	}

	void setContact_number(String^ Contact_number) {
		if (Contact_number->Length != 0) {
			this->Contact_number = Contact_number;
		}
		else throw invalid_argument("Wrong phone");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getContact_number() {
		return this->Contact_number;
	}

	void setOpen_24_hours(String^ Open_24_hours) {
		if (Open_24_hours->Length != 0) {
			this->Open_24_hours = Open_24_hours;
		}
		else throw invalid_argument("Wrong phone");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getOpen_24_hours() {
		return this->Open_24_hours;
	}

	void setWork_time(String^ Work_time) {
		if (Work_time->Length != 0) {
			this->Work_time = Work_time;
		}
		else throw invalid_argument("Wrong phone");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getWork_time() {
		return this->Work_time;
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
