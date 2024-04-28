#pragma once

#ifndef BASE_H
#define BASE_H
#include "polynomal.h"

class base
{
public:
    base();
    ~base() = default;
    base(polynomal *a){
        this->polynom = a;
        this->next = nullptr;
    }

    void set_next(base *a){
        this->next = a;
    }

    void del_n_elem(int n){
        base* a = this;
        for(int i = 1; i < n; ++i){
            if(a == 0){
                return;
            }
            a = a->next;
        }
        base* p  = a->next;
        *a = *a->next;
        delete p;
    }

    polynomal *get_polynom(){
        return this->polynom;
    }

    void set_polynom(polynomal* y){
        this->polynom = y;
    }
    polynomal* get_n_elem(int n){
        base * elem = this;
        for(int i = 0;i < n; ++i){
            elem = elem->get_next();
        }
        return elem->polynom;
    }
    base* get_next(){
        return this->next;
    }
private:
    polynomal *polynom;
    base* next;
};

#endif // BASE_H
