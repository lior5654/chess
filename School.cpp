/* version 1.0 of my school*/

#include <iostream>
#include <string>

#define MAX_STUDENTS 10

#define MENU_STUDENT_DETAILS 1
#define MENU_AVERAGE 2
#define MENU_PRINT_COURSES 3
#define MENU_EXIT 4

using namespace std;

class Course
{
public:
	//Methods
	void init(string name, int test1, int test2, int exam);

	int* getGradesList();
	string getName();
	double getFinalGrade();


private:
	string _name;
	int _grades[3]; //array of size 3 => test1, test2, exam
	double _avg;
};

class Student
{
public:
	void init(string name, Course** courses, int crsCount);

	string getName();
	void setName(string name);
	int getCrsCount();
	Course** getCourses();
	double getAvg();


private:
	string _name;
	Course** _Courses;//array of pointers to Course
	int _crsCount;
};


void Student::init(string name, Course** courses, int crsCount)
{
	_name = name;
	_Courses = courses;
	_crsCount = crsCount;



}
string Student::getName()
{
	return _name;
}
void Student::setName(string name)
{
	_name = name;
}

double Student::getAvg()
{
	double sum = 0;
	for (int i = 0; i < _crsCount; i++)
	{
		sum += _Courses[i]->getFinalGrade();

	}

	return sum / _crsCount;
}

int Student::getCrsCount()
{
	return _crsCount;
}
Course** Student::getCourses()
{
	return _Courses;
}


void Course::init(string name, int test1, int test2, int exam)
{
	_name = name;
	_grades[0] = test1;
	_grades[1] = test2;
	_grades[2] = exam;
}

int* Course::getGradesList()
{
	return _grades;
}
string Course::getName()
{
	return _name;
}
double Course::getFinalGrade()
{
	return (_grades[0] * 0.25 + _grades[1] * 0.25 + _grades[2] * 0.5);
}


Student* newStudent()
{
	string name;
	int crsCount;

	cout << "Enter student's name: ";
	cin >> name;
	cout << "Enter number of courses for student: ";
	cin >> crsCount;

	Course* crs = NULL;

	// handle of courses list
	Course** courses = new Course*[crsCount];
	for (int i = 0; i < crsCount; i++)
	{
		//Create new course
		string crsName;
		int test1, test2, exam;
		cout << "Enter Course name: ";
		cin >> crsName;
		cout << "Enter first test grade: ";
		cin >> test1;
		cout << "Enter second test grade: ";
		cin >> test2;
		cout << "Enter exam grade: ";
		cin >> exam;
		cout << endl;

		// create course object
		// TO DO: should create new Course object and assign it to crs 
		crs = new Course();

		// call to init function of course object
		crs->init(crsName, test1, test2, exam);

		//Add course to list
		courses[i] = crs;
	}


	Student* student;

	// create student object
	// TO DO: create new student object
	student = new Student();

	// call to init function of student object
	// TO DO: call the init function of students object
	student->init(name, courses, crsCount);


	// return student object
	return student;

}

int showMenu()
{
	int option = 0;
	cout << "Welcome to Magshimim! You have the following options:" << endl;
	cout << "1. Enter student deatails and courses" << endl;
	cout << "2. Calculate average grade of all courses" << endl;
	cout << "3. Show details of courses" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> option;
	cout << endl;

	return option;

}

void printCourses(Course** list, int count)
{
	int i;
	Course* currCourse;
	int* gradesList;



	for (i = 0; i < count; ++i)
	{
		currCourse = list[i];

		// TO DO: shold get the course grades list into gradesList
		gradesList = currCourse->getGradesList();

		cout << "Name: " << currCourse->getName() << ", test1 = " << gradesList[0] << ", test2 = " << gradesList[1] << ", exam = " << gradesList[2] << ", Grade = " << currCourse->getFinalGrade() << endl;
	}
	cout << endl << endl;
}

int main()
{
	Student* student = NULL;
	double avg = 0;

	//Main Loop
	bool toExit = false;
	while (!toExit)
	{
		switch (showMenu())
		{
		case MENU_STUDENT_DETAILS:
			if (student)
			{
				delete student;
			}

			student = newStudent();

			break;
		case MENU_AVERAGE:
			if (!student)
				cout << "NO details were added" << endl;
			else
				cout << "The average grade of " << student->getCrsCount() << " courses is: " << student->getAvg() << endl << endl;
			break;
		case MENU_PRINT_COURSES:
			if (!student)
				cout << "NO details were added" << endl;
			else
			{
				cout << "Courses list for student " << student->getName() << endl;
				// TO DO: call the printCourses function (the function is implemented)
				printCourses(student->getCourses(), student->getCrsCount());
			}
			break;
		case MENU_EXIT:
			toExit = true;
			cout << "Goodbye!" << endl;
			break;
		default:
			cout << "No Such Option!" << endl << endl;
			break;
		}
	}

	if (student)
	{
		delete student;
	}
	system("pause");
	return 0;
}

