#pragma once
#include <windows.h>
#include <String.h>
#include <stdexcept>
#include <list>
// ���������� �������� ���� std � System

using namespace System;
using namespace std;
// ���������� �����
ref class pharmacy2 {
	//������ ���� ����� ��� ���������� ����� �����, ���� �� ������� ������
	String^ Name;
	String^ Address;
	String^ Contact_number;
	String^ Open_24_hours;
	String^ Work_time;
	int id;
public: // ������ ����� �����
	pharmacy2() {}// ������� �����������
// ����������� ����������� ���� �ᒺ��� �����
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
		// ������� ������� ��� ����� ������ ��� ������, ������ ��� ����� 0
	}

	void setName(String^ Name) {
		if (Name->Length != 0) {
			this->Name = Name;
		}
		else throw invalid_argument("Wrong nazva");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getName() {
		return this->Name;
	}

	void setAddress(String^ Address) {
		if (Address->Length != 0) {
			this->Address = Address;
		}
		else throw invalid_argument("Wrong phone");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getAddress() {
		return this->Address;
	}

	void setContact_number(String^ Contact_number) {
		if (Contact_number->Length != 0) {
			this->Contact_number = Contact_number;
		}
		else throw invalid_argument("Wrong phone");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getContact_number() {
		return this->Contact_number;
	}

	void setOpen_24_hours(String^ Open_24_hours) {
		if (Open_24_hours->Length != 0) {
			this->Open_24_hours = Open_24_hours;
		}
		else throw invalid_argument("Wrong phone");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getOpen_24_hours() {
		return this->Open_24_hours;
	}

	void setWork_time(String^ Work_time) {
		if (Work_time->Length != 0) {
			this->Work_time = Work_time;
		}
		else throw invalid_argument("Wrong phone");
		// ������� ������� ��� ����� �������� ���� �������
	}
	String^ getWork_time() {
		return this->Work_time;
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
