#include <iostream>
using std::string;

class AbstractEmployee {
	virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
private:
	string Company;
	int Age;
protected:
	string Name;
public:
	void setName(string name) {
		Name = name;
	}
	string getName() {
		return Name;
	}
	void setCompany(string company) {
		Company = company;
	}
	string getCompany() {
		return Company;
	}
	void setAge(int age) {
		Age = age;
	}
	int getAge() {
		return Age;
	}

	void IntroduceYourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
	void AskForPromotion() {
		if (Age > 30)
			std::cout << Name << " got promoted!" << std::endl;
		else
			std::cout << Name << " sorry NO promotion for you :(" << std::endl;
	}
	virtual void Work() {
		std::cout << Name << " is cheking email, task backlog, performing tasks..." << std::endl;
	}
};	

class Developer:public Employee {
public:
	string FavProgrammingLanguage;
	Developer(string name, string company, int age, string language)
	:Employee(name, company, age)
	{
		FavProgrammingLanguage = language;
	}
	void FixBug() {
		std::cout << getName() << "fixed bug using " << FavProgrammingLanguage << std::endl;
	}
	void Work() {
		std::cout << Name << " is writting " << FavProgrammingLanguage << " code" << std::endl;
	}
};

class Teacher :public Employee {
public:
	string Subject;
	void PrepareLesson() {
		std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;
	}
	Teacher(string name, string company, int age, string subject) :Employee(name, company, age){
		Subject = subject;
	}
	void Work() {
		std::cout << Name << " is teaching" << Subject << std::endl;
	}
};
int main()
{
	Developer d = Developer("Saldina", "YT-CodeBeaty", 25, "C++");
	Teacher t = Teacher("Jesus", "Platzi", 35, "Machine learning");

	Employee* e1 = &d;
	Employee* e2 = &t;
	
	e1->Work();
	e2->Work();
}