#pragma once
#include <windows.h>
#include <String.h>
#include <stdexcept>
// підключення просторів імен std і System

using namespace System;
using namespace std;
// оголошення класу
ref class producer2 {
	//закриті поля класу для збереження даних
	int id;
	String^ Name;
	String^ Address;
	String^ Contacts;
	String^ Email;
public: // відкриті члени класу
	producer2() {}// порожній конструктор
// конструктор ініціалізаціі полів об’єктів класу
	producer2(int i, String^ t, String^ nd, String^ n, String^ v) {
		this->Name = t;
		this->Address = nd;
		this->Contacts = n;
		this->Email = v;
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
		else throw invalid_argument("Wrong price");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getName() {
		return this->Name;
	}

	void setAddress(String^ Address) {
		if (Address->Length != 0) {
			this->Address = Address;
		}
		else throw invalid_argument("Wrong price");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getAddress() {
		return this->Address;
	}

	void setContacts(String^ Contacts) {
		if (Contacts->Length != 0) {
			this->Contacts = Contacts;
		}
		else throw invalid_argument("Wrong price");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getContacts() {
		return this->Contacts;
	}

	void setEmail(String^ Email) {
		if (Email->Length != 0) {
			this->Email = Email;
		}
		else throw invalid_argument("Wrong price");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getEmail() {
		return this->Email;
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
