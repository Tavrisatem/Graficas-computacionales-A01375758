#include "Employee.h"

#include <sstream>

Employee::Employee(int id, std::string firstName, std::string lastName, int salary)
{
	_id = id;
	_firstName = firstName;
	_lastName = lastName;
	_salary = salary;
}

int Employee::GetID()
{
	return _id;
}

std::string Employee::GetFirstName()
{
	return _firstName;
}

std::string Employee::GetLastName()
{
	return _lastName;
}

std::string Employee::GetName()
{
	return _firstName + " " + _lastName;
}

int Employee::GetSalary()
{
	return _salary;
}

int Employee::GetAnualSalary()
{
	return 12 * _salary;
}

void Employee::SetSalary(int salary)
{
	_salary = salary;
}

int Employee::RaiseSalary(int percent)
{
	return _salary + ((_salary * percent) / 100);
}

std::string Employee::Print()
{
	std::ostringstream oss;
	oss << "Employee[" << _id << ", " << _firstName << " " << _lastName << ", " << _salary << "]";
	return oss.str();
}
