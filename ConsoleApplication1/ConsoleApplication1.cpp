

#include <iostream>
#include <string>


class Int_s {
public:
	int* array_num;
	int sizeof_array_num;
public:
	std::string string_number;
	Int_s() {};
	Int_s(std::string string_number): string_number(string_number) {
		this->sizeof_array_num = string_number.length(); // calcualte size of array to mad
		this->array_num = new int[this->sizeof_array_num]; // initialize array and store each number in it 

		for (int i = (this->sizeof_array_num - 1); i >= 0; i--) {
			this->array_num[i] = this->string_number[( this->sizeof_array_num - 1 - i)] - 48;
			
		}
	}

	void set_string_number(std::string) {
		this->sizeof_array_num = string_number.length(); // calcualte size of array to mad
		this->array_num = new int[this->sizeof_array_num]; // initialize array and store each number in it 

		for (int i = (this->sizeof_array_num - 1); i >= 0; i--) {
			this->array_num[i] = this->string_number[(this->sizeof_array_num - 1 - i)] - 48;

		}
	}

	void printArray() {
		for (int i = 0; i < this->sizeof_array_num; i++) {
			std::cout << array_num[i];
		}
	}

	int* getArray() {
		return this->array_num;
	}
public:
	Int_s operator+(const Int_s& obj) {
		int size_of_new_array = (this->sizeof_array_num >= obj.sizeof_array_num) ? (this->sizeof_array_num + 1) : (obj.sizeof_array_num + 1);
		int* newArray = new int[size_of_new_array];
		int carrier = 0;
		int sum , result , first , second;

		for (int i = 0; i < size_of_new_array; i++) {
			if (i > this->sizeof_array_num - 1) {
				first = 0;
			}
			else {
				first = this->array_num[i];
			}
			if (i > obj.sizeof_array_num - 1) {
				second = 0;
			}
			else {
				second = obj.array_num[i];
			}

			sum = first + second + carrier;
			result = sum % 10;
			carrier = (sum - result) / 10;
			newArray[i] = result;
		}
		std::string string_result = "";
		std::string string_to_concat;
		for (int i = size_of_new_array - 1; i >= 0; --i) {
			string_to_concat = std::to_string(newArray[i]);
			if (string_to_concat == "0" && i == size_of_new_array - 1) {
				continue;
			}
			else {
				string_result += string_to_concat;
			}
		}
		Int_s res(string_result);
		return res;
	}
	

};

void fibo(int n) {
	if (n == 1 || n == 2) {
		Int_s("1").printArray();
	}
	Int_s a("1");
	Int_s b("1");
	Int_s c;
	for (int i = 2; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	
	std::cout << c.string_number;
}

int main()
{
	fibo(5000);
}


