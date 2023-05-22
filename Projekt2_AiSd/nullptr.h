#ifndef NULLPTR_H
#define NULLPTR_H

template<typename T>
T& return_null() {
	static T* null_ptr = nullptr;
	return *null_ptr;
}

#endif