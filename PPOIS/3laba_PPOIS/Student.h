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
		//если учитель курса задал задание то делаем домашку и стадия на следующую
		this->stageOfCourse++;
	}
	int getStudentStage() {
		return this->stageOfCourse;
	}
};