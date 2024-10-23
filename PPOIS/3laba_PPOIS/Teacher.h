#pragma once
#include "Employee.h"
#include "Human.h"
class Teacher :public Employee {
private:
	string profile;
	string education;
public:
	Teacher(string name,string surname) {
		setNameAndSurname(name, surname);
	}
	Teacher(){}
	void setProfile(string profile) {
		this->profile = profile;
	}
	void setEducation(string education) {
		this->education = education;
	}
	string getProf() {
		return this->profile;
	}
	string getEdu() {
		return this->education;
	}


};