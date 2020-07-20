#ifndef VECTOR_HPP
#define VECTOR_HPP

template <class T>
class Vector_Supermercado {

private:
	int size_capacity;
	int size_vector;
	T* elements;

public:
	Vector_Supermercado(){
		this->size_capacity = 20;
		this->size_vector = 0;
		this->elements = new T[size_capacity];
	}
	~Vector_Supermercado(){
		delete[] elements;
	}
	void push_back(T element){

		this->elements[size_vector] = element;
		size_vector++;
		if(size_vector == size_capacity){
			size_capacity *=2;
			T* new_elements = new T[size_capacity];
			for (int i = 0; i < (size_capacity/2); ++i)
			{
				new_elements[i] = elements[i];
			}
			delete[] elements;
			elements = new_elements;
		}

	}
	void to_change(int i, T element){
		this->elements[i] = element;
	}
	T get_element(int i){
		return this->elements[i];
	}
	int size(){
		return size_vector;
	}	

};
#endif