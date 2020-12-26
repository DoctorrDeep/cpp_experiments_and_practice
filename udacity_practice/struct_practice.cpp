#include <iostream>
#include <cassert>
#include <string>

struct Date {
	int day{1};
	std::string month{"January"};
	int year = 2000;
};

int main(){

	Date a_date;

	assert(a_date.day == 1);
	assert(a_date.month == "January");
	assert(a_date.year == 2000);

	std::cout << "The date was checked to be " << a_date.day << "/" << a_date.month << "/" << a_date.year  << "\n";
}
