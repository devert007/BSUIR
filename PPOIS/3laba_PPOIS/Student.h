#pragma once
#include <iostream>
#include "Human.h"
#include "Course.h"
#include "Certificate.h"
class Student : public Human {
private:
	Course course;
	int stageOfCourse;
	
public:
	Student() {};
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
	Certificate getCertificate() {
		if (this->stageOfCourse > 5) {
			Certificate certificate_stud(this->getNameandSurname(),this->getStudentCourse(),this->stageOfCourse);
			return certificate_stud;
		} 
	}
};