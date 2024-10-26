#include <iostream>

int main(){
    int x = 2;
	int* ptr = &x;
	// & адрес ячейки oxC0FEE
	// * тип для хранения адреса ячейка | модификатор типа, указатель на int
	*(ptr) = 3; // опервация разименования , под адресу вернуть ячейку.
	
	//Если в функцию передать указатель, то есть адрес передаваемой переменной, 
	//то она в итоге после функции измениться
	//если передать просто переменную, то значение функции вернется, 
	//но сама переменная не вернется.

	++ptr; //сместиться на соседнюю ячейку памяти. 
	//удаление указателя
	delete ptr;


	int arr[3] = {1, 2, 3};
	// arr[1] = 5 <=> *(arr+1) = 5;
	// => int arr[3] = {1, 5, 3};
	int c = 5;
	// char* ptr_c = &c;  - не работает тк с не char
	char* ptr_c = (char*) &c; //так работает
	ptr_c[0]; // первый байт записи числа с;
	int c_return = *(int*)ptr_c; // вернуть число зная адрес ячейки+ разные типы


	//создание динамического массива
	int* dyn_arr = new int[N];
	//удаление массива
	delete[] dyn_arr;

	std::cout << "array size = ";
	std:: cin >> sz;
	int* arr = new int[sz];
	std::cout << "array size = " << sizeof(arr) << std::endl;
	for (int idx = 0; idx < sz; ++idx) {
		// arr[idx] = idx;
		// *(arr + idx) = idx;
		id[arr] = idx;
	}
	for (int idx = 0; idx < sz; ++idx) {
		std::cout<< *(arr + idx)<< ' ';
	}
	
	std::cout<<'\n':
	delete[] arr;


	return 0;
}







