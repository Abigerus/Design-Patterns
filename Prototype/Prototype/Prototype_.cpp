#include <iostream>
#include <vector>
using namespace std;


//Prototype interface with a single clone () method
class Prototype
{
public:
	virtual Prototype* clone() = 0;
};


//Specific prototypes with self cloning
class Prototype_Architect : public Prototype
{
public:
	Prototype * clone()
	{
		cout << "\n Architect copy successfully created" << endl; 
		return new Prototype_Architect;
	};
};

class Prototype_Doctor : public Prototype
{
public:
	Prototype * clone() 
	{
		cout << "\n Doctor copy successfully created" << endl;
		return new Prototype_Doctor;
	};
};

class Prototype_Programmer : public Prototype
{
public:
	Prototype * clone() 
	{
		cout << "\n Programmer copy successfully created" << endl; 
		return new Prototype_Programmer;
	};
};

//Prototyping and Cloning
void main()
{
	vector<Prototype*> copies;
	int choice;
	Prototype_Architect* Arhitect = new Prototype_Architect; 
	Prototype_Doctor* Doctor = new Prototype_Doctor;
	Prototype_Programmer* Programmer = new Prototype_Programmer;

	Prototype* all_prototypes[] = { 0, Arhitect, Doctor, Programmer };
	cout << "What copy do you want to make?\n";
	while (true) 
	{
		cout << "Architect- '1' Doctor- '2' Programmer- '3' Exit- '0': ";
		cin >> choice;
		if (choice == 0)
			break;
		if (choice <0 || choice>3)
				cout << "Enter the correct value\n";
		else
			copies.push_back(all_prototypes[choice]->clone());
	}
}

