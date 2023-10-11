#include "LinkedList.h"
#include "Employee.h"

int main() { //code in main is used to test LinkedList class and Employee class + derived classes

	//test code for linked list:

	LinkedList list1;
	list1.insert(0, 1);
	list1.pop_front();
	list1.pop_back();

	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.print(); //list should be (1, 2, 3)

	list1.pop_front();
	list1.pop_front();
	list1.pop_front();

	if (list1.empty()) { //list should be empty
		cout << "List is empty." << endl;
	}
	else {
		cout << "List is not empty." << endl;
	}

	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3); //list should be (3, 2, 1)
	list1.print();

	if (list1.empty()) { //list should not be empty
		cout << "List is empty." << endl;
	}
	else {
		cout << "List is not empty." << endl;
	}

	list1.insert(1, 4); //list should be (3, 4, 2, 1)
	list1.print();
	list1.remove(1); //list should be (3, 2, 1)
	list1.print();
	cout << "The location of the number 2 in this list is position: " << list1.find(2) << endl;
	cout << "There is no 4 in this list, so the find function returns: " << list1.find(4) << " when a 4 is passed to it." << endl;

	cout << "Front of list: " << list1.front() << " Back of list: " << list1.back() << endl; //front of list should be 3, back of list should be 1

	//----------------------------------------------------------------------------------------------------------------------------------------------

	//test code for employee derived classes:

	Nonprofessional employee1;
	Professional employee2;

	cout << "The salary of an average professional employee at this company is $" << employee2.getSalary() << " while the average nonprofessional employee earns around $" << employee1.getHourlyRate() << " per hour." << endl;
	cout << "Professional employees earn " << employee2.getVacationDays() << " vacation days per year; nonprofessional employees earn only " << employee1.getVacationDays() << " days per year." << endl;
	cout << "Professional employees enjoy the benefit of a higher insurance converage. As such, professionals pay around $" << employee2.getHealthInsuranceCost() << " for insurance while nonprofessional employees pay $" << employee1.getHealthInsuranceCost() << " in insurance costs." << endl;
}