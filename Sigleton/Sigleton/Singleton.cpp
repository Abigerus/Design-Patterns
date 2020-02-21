// 
#include <iostream>
#include <vector>
using namespace std;

// class hierarchy
class Profession
{
public:
	virtual void info() = 0;
	virtual ~Profession() {}
};

class Architect : public Profession
{
public:
	void info() {
		cout << "Architect created" << endl;
	};
};

class Doctor : public Profession
{
public:
	void info() {
		cout << "Doctor  created" << endl;
	};
};

class Programmer : public Profession
{
public:
	void info() {
		cout << "Programmer  created" << endl;
	};
};

//Factories of objects
class Factory
{
public:
	virtual Profession* createProfession() = 0;
	virtual ~Factory() {}
};


// Using Singleton for Three Factory Classes
class ArchitectFactory : public Factory
{
private:
	ArchitectFactory() {}
	ArchitectFactory(const ArchitectFactory&);
	ArchitectFactory& operator=(ArchitectFactory&);
public:
	static ArchitectFactory&  Instance() {
		static ArchitectFactory uniqueInstance;
		return uniqueInstance;
	}
	Profession* createProfession() {
		return new Architect;
	}
};


class DoctorsFactory : public Factory
{
private:
	DoctorsFactory() {}
	DoctorsFactory(const DoctorsFactory&);
	DoctorsFactory& operator=(DoctorsFactory&);
public:
	static DoctorsFactory&  Instance() {
		static DoctorsFactory uniqueInstance;
		return uniqueInstance;
	}
	Profession* createProfession() {
		return new Doctor;
	}
};

class ProgrammerFactory : public Factory
{
private:
	ProgrammerFactory() {}
	ProgrammerFactory(const ProgrammerFactory&);
	ProgrammerFactory& operator=(ProgrammerFactory&);
public:
	static ProgrammerFactory&  Instance() {
		static ProgrammerFactory uniqueInstance;
		return uniqueInstance;
	}
	Profession* createProfession() {
		return new Programmer;
	}
};

// Creating Objects Using Object Factories
void main()
{
	ArchitectFactory& architect = ArchitectFactory::Instance();
	DoctorsFactory&  doctor = DoctorsFactory::Instance();
	ProgrammerFactory&  programmer = ProgrammerFactory::Instance();
	DoctorsFactory&  doctor_2 = DoctorsFactory::Instance();

	vector<Profession*> v;
	v.push_back(architect.createProfession());
	v.push_back(doctor.createProfession());
	v.push_back(programmer.createProfession());
	v.push_back(doctor_2.createProfession());


	for (int i = 0; i < v.size(); i++)
		v[i]->info();
	getchar();
}