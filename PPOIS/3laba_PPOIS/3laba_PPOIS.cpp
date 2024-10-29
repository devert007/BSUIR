#include "Human.h"
#include "Operator.h"
#include "Course.h"
#include "Contact.h"
#include "Profession.h"
#include "Sale.h"
#include "Student.h"
#include "Teacher.h"
#include "OnlinePlatform.h"
#include <string>
#include <vector>
#include <iostream>

void getInfoAboutStudent(Student student) {
	cout << "Привет " << student.getNameandSurname() << '\n';
	cout << "Твой статус:\n";
	cout << "Название курса: " << student.getStudentCourse().getProfession().getProfessionName() << '\n';
	cout << "Цена твоего курса (со скидками): " << student.getStudentCourse().getPrice() << '\n';
	cout << "Твои скидки в BYN: ";
	for (int i = 0; i < student.getStudentCourse().getSales().size(); i++) {
		cout << student.getStudentCourse().getSales()[i].getSaleValue();
	}
	cout << "\n";
	cout<< "Твоя стадия курса: " << student.getStudentStage() << '\n';
	if (student.getStudentStage()!=student.getStudentCourse().getTeacher().getStageHomework()-1) {
		cout << "Возможно вам стоит сделать домашнее задание\n";
	}
	student.doHomework();
	cout << "Вы сделали домашнее задание...\n";
	
	cout << "Твоя стадия курса: " << student.getStudentStage()<<'\n';
	//добавить домашку и стадию
}
void getInfoAboutPlatform(OnlinePlatform platform) {
	cout << "\t\t\t" << platform.getName() << '\n';
	cout << "\t\t\t" << platform.getOrientation() << '\n';
	cout << "Телефон оператора: " << platform.getContact()[0].getContact() << '\n';
	cout << "Почта оператора: " << platform.getContact()[1].getContact() << '\n';
	cout << "Телефон менеджера: " << platform.getContact()[2].getContact() << '\n';
	cout << "Почта оператора: " << platform.getContact()[3].getContact() << '\n';
	cout << "Комментарии: \n";
	for (int i = 0; i < platform.getCommentsArray().size(); i++) {
		cout << "Кол-во звезд: " << platform.getCommentsArray()[i].getCommentStars() << '\n';
		cout << "Комментарий: " << platform.getCommentsArray()[i].getCommentInfo() << '\n';
	}
}


int main()
{
	setlocale(LC_ALL, "russian");
	OnlinePlatform platform("ITppois.bsuir", "we help with ppois in BSUIR");
	vector<string> contacts = { "3752912345","ppoisCourse@bsuir.by","375441234597","courseMan@bsuir.by" };
	platform.setContacts(contacts);
	Comment comment1(3,"its the best online platform that i ever seen, but they need money for advertisement");
	Comment comment2(4, "Empowering students to thrive in a digital world");
	Comment comment3(5, "Connecting BSUIR students to the world of IT and beyond");
	vector<Comment>comments = { comment1,comment2,comment3 };
	platform.setComments(comments);

	//
	//create courses and sales for them
	Course course1("AI profession",Teacher("Ivan","Ivanov"));
	Sale sale1(12);
	course1.addSale(sale1);
	course1.setPrice(120);
	
	std::string professionInfo1 = "Профессия AI (Искусственный интеллект, AI) - это специальность, связанная с разработкой, созданием и исследованием интеллектуальных систем, которые могут выполнять задачи, обычно сравнимые с человеческими, с использованием вычислительной техники и алгоритмов.\n\n"
		"Основные обязанности AI-специалиста включают:\n"
		"1. Разработка и создание алгоритмов и систем, позволяющих компьютерам учиться, улучшать и принимать решения, как люди.\n"
		"2. Исследование и изучение существующих технологий AI, а также их применение в различных областях, таких как медицина, экономика, образование, безопасность и технологии.\n"
		"3. Разработка и реализация решений AI для решения реальных проблем и улучшения человеческой жизни.\n"
		"4. Подготовка и обучение специалистов в области AI, включая студентов, молодых специалистов и практикующих.\n"
		"5. Сотрудничество с другими специалистами и организациями для разработки AI и применения его в практических ситуациях.\n\n"
		"Профессия AI предлагает высокие уровни свободы и конкуренции, поскольку новые идеи, технологии и решения могут быть быстро реализованы и использованы для создания более эффективных и удобных систем.\n"
		"Кроме того, профессия AI предоставляет возможности для профессионального роста и развития, поскольку специалисты могут учиться и применять новые знания и технологии для улучшения своей работы.";
	course1.getProfession().setProfessionInfo(professionInfo1);
	//
	Sale sale2(10);

	Course course2("PPOIS help course",Teacher("Davyd","Davydov"));
	string professionInfo2 = "Цель курса: Обучение студентов основам программирования и навыкам сдачи лабораторных работ в университетской среде.\n"
								"Общее описание:\n"
								"Этот курс предназначен для студентов, желающих научиться создавать и выполнять программы, а также узнать, как правильно оформлять и предоставлять лабораторные работы в университете.\n"
								"Курс включает в себя теоретические занятия, лабораторные работы и практические задания.\n";
	course2.addSale(sale2);
	course2.getProfession().setProfessionInfo(professionInfo2);
	//
	//create main student
	cout << "Хотите увидеть свой статус(1-да, 0-нет ) ";
	bool choose;
	cin >> choose;
	if (choose) {
		Student student(course1);
		student.setNameAndSurname("ivan", "kislitsyn");
		student.setSex('male');
		getInfoAboutStudent(student);
	}
	
	cout << "Хотите вывести информацию о компании?(1 - да, 0 - нет)\n";
	int choose_client_about_info_platform;
	cin >> choose_client_about_info_platform;
	if (choose_client_about_info_platform == 1) {
		getInfoAboutPlatform(platform);
	}

	cout << "\nХотите увидеть список курсов которые мы предлагаем? (1 - да, 0 - нет)\n";
	int choose_client_about_info_cources;
	cin >> choose_client_about_info_cources;
	if (choose_client_about_info_cources == 1) {
	//	getInfoAboutPlatform(platform);
	}
	



}

