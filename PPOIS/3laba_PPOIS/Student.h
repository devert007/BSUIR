#pragma once
#include <iostream>
#include "Human.h"
#include "Course.h"

class Student : public Human {
private:
	Course course;
	int stageOfCourse;
public:
	void doHomework() {
		//���� ������� ����� ����� ������� �� ������ ������� � ������ �� ���������
		this->stageOfCourse++;
	}
	int getStudentStage() {
		return this->stageOfCourse;
	}
};