#include <iostream>
# include <string>
using namespace std;

template<typename T>
void print(T x) {
	cout << x << endl;
}

template<typename T, int size>
class myArray{
private:
		T m_array[size];
public: 
		int getSize() {
			return(size);
	}
};


int main(){

	const int maxage = 90;

	int*a = new int;
	*a = 5;
	a = (int*)&maxage;

	print(*a);

	cin.get();
}
