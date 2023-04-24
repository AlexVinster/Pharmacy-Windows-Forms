#pragma once
#include <windows.h>
#include <String.h>
#include <stdexcept>
// підключення просторів імен std і System

using namespace System;
using namespace std;
// оголошення класу
ref class preparation2 {
	//закриті поля класу для збереження даних країну, місце та глибину ареалу
	int id;
	String^ preparation;
	String^ model;
	String^ active_Substances;
	String^ application;
	String^ contraindication;
	String^ side_Reactions;
	String^ termin;
	String^ dates;
	String^ producer;
	String^ pharmacy;
public: // відкриті члени класу
	preparation2() {}// порожній конструктор
// конструктор ініціалізаціі полів об’єктів класу
	preparation2(int i, String^ dt, String^ v, String^ d, String^ cr, String^ c, String^ dtc, String^ vv, String^ dd, String^ crr, String^ cc) {
		this->id = i;
		this->preparation = dt;
		this->model = v;
		this->active_Substances = d;
		this->application = cr;
		this->contraindication = c;
		this->side_Reactions = dtc;
		this->termin = vv;
		this->dates = dd;
		this->producer = crr;
		this->pharmacy = cc;
		if (i > 0) {
			this->id = i;
		}
		else throw invalid_argument("Wrong id");
		// обробка помилки при спробі ввести код запису, менший або рівний 0
	}

	void setPreparation(String^ preparation) {
		if (preparation->Length != 0) {
			this->preparation = preparation;
		}
		else throw invalid_argument("Wrong price");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getPreparation() {
		return this->preparation;
	}

	void setModel(String^ model) {
		if (model->Length != 0) {
			this->model = model;
		}
		else throw invalid_argument("Wrong station");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getModel() {
		return this->model;
	}

	void setActive_Substances(String^ active_Substances) {
		if (active_Substances->Length != 0) {
			this->active_Substances = active_Substances;
		}
		else throw invalid_argument("Wrong vidpravlennya");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getActive_Substances() {
		return this->active_Substances;
	}


	void setApplication(String^ application) {
		if (application->Length != 0) {
			this->application = application;
		}
		else throw invalid_argument("Wrong vidpravlennya");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getApplication() {
		return this->application;
	}

	void setContraindication(String^ contraindication) {
		if (contraindication->Length != 0) {
			this->contraindication = contraindication;
		}
		else throw invalid_argument("Wrong vidpravlennya");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getContraindication() {
		return this->contraindication;
	}

	void setSide_Reactions(String^ side_Reactions) {
		if (side_Reactions->Length != 0) {
			this->side_Reactions = side_Reactions;
		}
		else throw invalid_argument("Wrong price");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getSide_Reactions() {
		return this->side_Reactions;
	}

	void setTermin(String^ termin) {
		if (termin->Length != 0) {
			this->termin = termin;
		}
		else throw invalid_argument("Wrong station");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getTermin() {
		return this->termin;
	}

	void setDates(String^ dates) {
		if (dates->Length != 0) {
			this->dates = dates;
		}
		else throw invalid_argument("Wrong vidpravlennya");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getDates() {
		return this->dates;
	}


	void setProducer(String^ producer) {
		if (producer->Length != 0) {
			this->producer = producer;
		}
		else throw invalid_argument("Wrong vidpravlennya");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getProducer() {
		return this->producer;
	}

	void setPharmacy(String^ pharmacy) {
		if (pharmacy->Length != 0) {
			this->pharmacy = pharmacy;
		}
		else throw invalid_argument("Wrong vidpravlennya");
		// обробка помилки при спробі залишити поле порожнім
	}
	String^ getPharmacy() {
		return this->pharmacy;
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
