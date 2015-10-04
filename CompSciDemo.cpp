// CompSciDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct person 
{
	//char name[100];
	std::string name;
	int opinion1;
};

std::vector <person> personsList;
std::ofstream file;

int _tmain(int argc, _TCHAR* argv[])
{
	//char name[100];
	std::string name;
	
	while (true)
	{
		int opinion = 0;
		std::cout << "Hello! What is your name? \n";

		person newPerson;

		std::cin >> name;
		std::cout << "Hello, " << name << "! Do you prefer Android (1) or Apple(2)?\n";
		std::cin >> opinion;

		newPerson.name = name;
		newPerson.opinion1 = opinion;

		personsList.push_back(newPerson);
		
		int agree = 0;
		for (unsigned int i = 0; i < personsList.size(); i++)
		{
			if (personsList[i].opinion1 == opinion) 
			{
				agree++;
			}
		}
		std::cout << agree - 1 << " people agree with you!\n";

		file.open("data.txt");
		for (unsigned int i = 0; i < personsList.size(); i++)
		{
			file << i << ", " << personsList[i].name << ", " << personsList[i].opinion1 << std::endl;
		}
		file.close();

	}

	return 0;
}

