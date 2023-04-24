#pragma once
#include <windows.h>
#include <String.h>
#include <stdexcept>
// ���������� �������� ���� std � System

using namespace System;
using namespace std;
// ���������� �����
ref class supplied_Preparation2 {
	//������ ���� ����� ��� ���������� �����
	String^ Amount;
	String^ Price;
	String^ Address_of_Delivery;
	String^ Paid;
	String^ preparation;
	int id;
public: // ������ ����� �����
	supplied_Preparation2() {}// ������� �����������
// ����������� ����������� ���� �ᒺ��� �����
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
		// ������� ������� ��� ����� ������ ��� ������, ������ ��� ����� 0
	}

	void setAmount(String^ Amount) {
		if (Amount->Length != 0) {
			this->Amount = Amount;
		}
		else throw invalid_argument("Wrong nazva");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getAmount() {
		return this->Amount;
	}

	void setPrice(String^ Price) {
		if (Price->Length != 0) {
			this->Price = Price;
		}
		else throw invalid_argument("Wrong forma");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getPrice() {
		return this->Price;
	}
	void setAddress_of_Delivery(String^ Address_of_Delivery) {
		if (Address_of_Delivery->Length != 0) {
			this->Address_of_Delivery = Address_of_Delivery;
		}
		else throw invalid_argument("Wrong price");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getAddress_of_Delivery() {
		return this->Address_of_Delivery;
	}
	void setPaid(String^ Paid) {
		if (Paid->Length != 0) {
			this->Paid = Paid;
		}
		else throw invalid_argument("Wrong data");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getPaid() {
		return this->Paid;
	}

	void setpreparation(String^ preparation) {
		if (preparation->Length != 0) {
			this->preparation = preparation;
		}
		else throw invalid_argument("Wrong data");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getpreparation() {
		return this->preparation;
	}

	void setId(int id) {
		if (id > 0) {
			this->id = id;
		}
		else throw invalid_argument("Wrong id");
		// ������� ������� ��� ����� ������ ��� ������, ������ ��� ����� 0
	}
	int getId() {
		return this->id;
	}

};

