#pragma once
#include <windows.h>
#include <String.h>
#include <stdexcept>
// ���������� �������� ���� std � System

using namespace System;
using namespace std;
// ���������� �����
ref class producer2 {
	//������ ���� ����� ��� ���������� �����
	int id;
	String^ Name;
	String^ Address;
	String^ Contacts;
	String^ Email;
public: // ������ ����� �����
	producer2() {}// ������� �����������
// ����������� ����������� ���� �ᒺ��� �����
	producer2(int i, String^ t, String^ nd, String^ n, String^ v) {
		this->Name = t;
		this->Address = nd;
		this->Contacts = n;
		this->Email = v;
		if (i > 0) {
			this->id = i;
		}
		else throw invalid_argument("Wrong id");
		// ������� ������� ��� ����� ������ ��� ������, ������ ��� ����� 0
	}

	void setName(String^ Name) {
		if (Name->Length != 0) {
			this->Name = Name;
		}
		else throw invalid_argument("Wrong price");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getName() {
		return this->Name;
	}

	void setAddress(String^ Address) {
		if (Address->Length != 0) {
			this->Address = Address;
		}
		else throw invalid_argument("Wrong price");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getAddress() {
		return this->Address;
	}

	void setContacts(String^ Contacts) {
		if (Contacts->Length != 0) {
			this->Contacts = Contacts;
		}
		else throw invalid_argument("Wrong price");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getContacts() {
		return this->Contacts;
	}

	void setEmail(String^ Email) {
		if (Email->Length != 0) {
			this->Email = Email;
		}
		else throw invalid_argument("Wrong price");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getEmail() {
		return this->Email;
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
