#include <iostream>
using namespace std;
//struct Date {
//	unsigned int day, mounth, year;
//};
struct Person{
	char * name; // 4 bytes = pointer
	char * hobby;
	
	struct Date {
		unsigned int day, mounth, year;
	};
	Date  birth;// 12 bytes
};

struct Event {
	Person::Date dateE;
};

void Enter (Person * a);
void Show (const Person * a);
void Clear(Person * a);

int main()
{
	Person *p = new Person{};
	Enter(p);
	Show(p);
	Clear(p);
	delete p;

}
void EnterDate(Person::Date * date);

void Enter (Person * a){
	cout << "Enter name : ";
	delete[] a->name;
	delete[] a->hobby;
	a->name  = new char [20];
	cin >> a->name;
	cout << "Enter hobby : ";
	a->hobby  = new char [20];
	cin >> a->hobby;
	//cout << "Enter date(day, mounth and year) : ";
	//cin >> a->birth.day >> a->birth.mounth >>  a->birth.year;
	EnterDate(&(a->birth));
	
}
void EnterDate(Person::Date * date)
{
	cout << "Enter date(day, mounth and year) : ";
	cin >> date->day >>date->mounth >> date ->year;
	if (date->mounth > 12 || date->mounth < 1)
	{
		date->mounth = 1;
	}
	if (date->day > 31 || date->day < 1)
	{
		date->day = 1;
	}

}
void Show (const Person * a){
	cout << "\n\nName : " << a->name ;
	cout << "\thobby : " << a->hobby;
	cout << "\tbirth : "<<
	 a->birth.day <<"/"<< a->birth.mounth << "/" << a->birth.year<< "\n\n";
	
}
void Clear(Person * a)
{
	delete a->hobby;
	a->hobby = nullptr;
	delete a->name;
	a->name = nullptr;
}