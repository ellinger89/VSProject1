#include <iostream>
# include <string>


template<typename T>
void print(T x) {
	std::cout << x << std::endl;
}

class Entity{
private:
	// since this variable will be changed from within a method that 
	// promised not to change anything (~ method() const {}), the
	// variable must be explicitly marked as mutable
	mutable std::string mystring;
public:
	// for a method to be called from a const object,
	// the method must "promise" that it is not going to change anything
	std::string& getX() const		
	{
		return mystring;
	}
	void setX(std::string someString) const
	{
		mystring = someString;
	}
};


int main(){

	const Entity obj;		// somehow you want an object that can not be changed
	obj.setX("hubuduboo");

	// so now, allthough all the methods involved promised that they
	// will not change any members of the Entity-Class, those methods
	// can still set and return the member "mystring", because it was
	// explicitly marked as mutable
	std::string a;
	a = obj.getX();
	print(a);

	std::cin.get();
}
