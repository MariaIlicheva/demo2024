#include <iostream>

int main(){
	int x = 2;
	int* ptr = &x;
    int ** pptr = &ptr; //указатель на указатель типа инт

	//двумерный массив
    int ** pptr = new int*[3];
    for (int i=0; i<3; ++i) { //индексы строк, указатели на строки
    	pptr[i] = new int[n]; //в строки кладем новые массивы
    } 
    // как удалить: сначала delete[] ptr[i]
    // потом delete[] pptr;
    

	return 0;
}







