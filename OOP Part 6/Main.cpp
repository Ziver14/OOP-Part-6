#include <iostream>

//Конструкторы копирования и операторы классов


//Правила работы с операторами
/*
	1. Операторы можно перегружать только для классов, для встроенных типов данных(int,float и т.п.) операторы перегружать нельзя
	2. Оператор не может менять своего поведения в ходе перегрузки(если "+" принимает только два значения, он не может принять больше)
	3. Ряд операторов запрезено перегружать впринципе (".","?:","& - унарный амперсант","new","delete","::","->")
*/
	


class Integer {
public:
	Integer() : data_(0) {}
	Integer(int num):data_(num){}

	//Оператор перегружен как дружественная функция
	friend Integer operator + (Integer A,Integer B) {  // не метод класса, а дружественная функция
		Integer result;
		result.data_ = A.data_ + B.data_;
		return result;
	}

	friend std::ostream& operator <<(				   //дружественная функция
		std::ostream& out,
		const Integer& obj
		);
			
	int GetNum() {
		return data_;
	}

	//Оператор перегружен как метод класса
	Integer& operator = (const Integer& other) {
		this->data_ = other.data_;
			return *this;
	}

private:
	int data_;
	//====================================//
	//bool sign_;
	//unsigned long long units_;
	// такая реализыция полей лучше подойдет для 
	// математически достоверных чисел
 };

std::ostream& operator <<(						 //дружественная функция
	std::ostream& out,
	const Integer& obj
	) {
	return out << obj.data_;
}

//Оператор перегружен как независимая функция
Integer operator-(Integer a, Integer b) {
	return a.GetNum() - b.GetNum();
}

Integer operator * (Integer a, Integer b) {
	return a.GetNum() * b.GetNum();
}

int main() {
	setlocale(LC_ALL, "ru");
	Integer a{ 5 };
	Integer b{ 8 };

	operator+(a, b);
	std::cout << a + b << '\n';
	std::cout << a - b << '\n';
	std::cout << a * b << '\n';

//==================================//

	std::cout << a + 5 << '\n';
	std::cout << a - 5 << '\n';
	std::cout << a * 3 << '\n';

//==================================//

	std::cout << 4 + b << '\n';
	std::cout << 7 - b << '\n';
	std::cout << 1 * b << '\n';

	Integer c;
	c = a + b;

	return 0;
}