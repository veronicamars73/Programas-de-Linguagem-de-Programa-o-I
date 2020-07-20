#ifndef W5N_FILA_H
#define W5N_FILA_H

#include <iostream>


template <class Tipo_e> 
class Fila{
    private:
    int tamanho;
    int last;
    int first;
    Tipo_e* elements;

    public:
    Fila(int s){
        this->tamanho = s;
        this->last = 0;
        this->first = 0;
        this->elements = new Tipo_e[tamanho];
    }

    bool isEmpty(){
        if(first == last){
            return true;
        }else{
            return false;
        }
    }

    Tipo_e back(){
        return this->elements[last];
    }

    Tipo_e front(){
        return this->elements[first];
    }

    void add(Tipo_e element){
        if(tamanho == last){
            std::cout << "fila cheia" << std::endl;
        }else{
            this->elements[last] = element;
            last = last + 1;
        }
    }

    void remove(){
        if(first == last){
            std::cout << "fila vazia" << std::endl;
        }else{
            first = first + 1;
        }
    }

    Tipo_e printFila(){
        Tipo_e* element_to_ret = new Tipo_e[tamanho];
        int cont = 0;
        for (int i = first; i < last; ++i){
            element_to_ret[cont] = this->elements[i];
            cont = cont + 1;
        }
        return element_to_ret;
    }
    
};

#endif