#pragma once
#include "Employee.h"
#include "Human.h"
class Teacher :public Employee {
private:
	string profile;
	string education;
	int stageHomework=0;
public:
	Teacher(string name,string surname) {
		setNameAndSurname(name, surname);
		this->setSalaryForEmployee(1800);
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
	bool setHomework(int stage) {
		if (stage != this->stageHomework) {
			this->stageHomework = stage;
			return true;
		}
		return false;
	}
	int getStageHomework() {
		return this->stageHomework;
	}
};