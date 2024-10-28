#pragma once
#include <iostream>
#include "Human.h"
#include "Course.h"

class Student : public Human {
private:
	Course course;
	int stageOfCourse;
public:
	Student(Course course){
		this->course=course;
	};
	void doHomework() {
		if(this->course.getTeacher().setHomework(1))
		this->stageOfCourse++;

	}
	int getStudentStage() {
		return this->stageOfCourse;
	}
	Course getStudentCourse() {
		return this->course;
	}
};