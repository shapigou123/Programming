#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Student
{
	string name;
	int score;
	friend ostream& operator<<(ostream &os, const struct Student &std)
	{
		os << "student: " << std.name << " " << std.score << endl;
		return os;
	}

	bool operator<(const struct Student &std)
	{
		return this->score != std.score ? this->score < std.score : this->name < std.name;
		//return this->score < std.score;
	}
};