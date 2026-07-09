#include <iostream>
using namespace std;

class Box
{
public:
	static int objectCounter;
	// Constructor definition
	Box(double l=2.0, double h=2.0, double w=2.0)
	{
		cout << "Constructer called." << endl;
		length = l;
		height = h;
		width = w;
		// Increment objectCounter each time a nwe object is created
		objectCounter++;
	}
	// Static member function
	static int returnCounter()
	{
		return objectCounter;
	}
	// Member function for volume calculation
	double Volume()
	{
		return length * height * width;
	}
	// Member function for comparing volumes of two objects
	int compareTo(Box box)
	{
		return this->Volume() > box.Volume();
	}
protected:
	double length, height, width;
};

int Box::objectCounter = 0;

class SmallBox:public Box 
{
public:
	// Constructor of derived class
	SmallBox(double len, double hei, double wid)
	{
		cout << "Derived object constructed" << endl;
		length = len;
		height = hei;
		width = wid;
	}
	// Destructor of derived class
	~SmallBox()
	{
		cout << "Derived object deleted" << endl;
	}
	// Member function, returns perimeter of the object
	double Perimeter()
	{
		return length + height + width;
	}
};

int main()
{
	cout << "objectCounter: " << Box::returnCounter() << endl;
	// Instantiating two objects
	Box box1(3.0, 5.0, 2.0);
	Box box2(4.0, 6.0, 3.0);
	// Instantianting a object from derived class
	SmallBox smallb(1.0, 3.0, 0.8);
	// Define a pointer to class Box
	Box *ptr = NULL; 
	
	// Initialize pointer to first object
	ptr = &box1;
	cout << "Using pointer to a class, volume of box1 is: " << ptr->Volume() << endl;
	// Pointer to the second object
	ptr = &box2;
	cout << "Using pointer to a class, volume of box2 is: " << ptr->Volume() << endl;
	// Print first if volume of object one is greater than second object volume
	if(box1.compareTo(box2))
	{
		cout << "Volume of box1 is greater" << endl;
	} else {
		cout << "Volume of box2 is greater than box1" << endl;
	}

	cout << "objectCounter: " << Box::returnCounter() << endl;
	
	cout << "Perimet of smallb is: " << smallb.Perimeter() << endl;
	return 0;
}