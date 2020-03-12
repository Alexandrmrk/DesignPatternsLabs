#include "stdafx.h"
#include"VectorS.h"

VectorS::VectorS(int size) {
	this->size = size;
}

int VectorS::GetSize() {
	return size;
}

int VectorS::GetValue(int pos) {
	//find(key) возвращает итератор, ссылающийся на расположение элемента
	//с указанным ключом или на расположение элемента после последнего
	//элемента в карте(map::end()), если для ключа не найдено совпадений.
	std::map<int, int>::iterator it = myVector.find(pos);
	if (it != myVector.end()) {
		return it->second;
	}
	else {
		return 0;
	}
}

void VectorS::SetValue(int pos, int value) {
	if (pos < size) {
		myVector[pos] = value;
	}
	else {
		std::cout << "\n позиция больше, чем размерность\n";
	}
}