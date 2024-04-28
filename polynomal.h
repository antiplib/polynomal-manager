#pragma once
#ifndef POLYNOMAL_H
#define POLYNOMAL_H
#include "node.h"

class polynomal {
public:
    polynomal() = default;
    polynomal(node* first) {
        this->first = first;
    }
    ~polynomal() {
        node* p = this->first;
        while (p != nullptr) {
            node* q = p->get_next();
            delete p;
            p = q;
        }
    }
    polynomal *make_copy() {
        if(this->get_first() == nullptr) {
            return nullptr;
        }
        node* elem = this->get_first();
        node* p = new node;
        *p = *elem;
        elem = elem->get_next();
        node* ans = p;
        while(elem) {
            node * q = new node();
            *q = *elem;
            p->set_next(q);
            p = p->get_next();
            elem = elem->get_next();
        }
        polynomal *f = new polynomal(ans);
        return f;
    }
    node* get_first() {
        return this->first;
    }

    node* set_first(node* f) {
        this->first = f;
    }
    bool is_only_variable() {
        node* a = this->get_first();
        int ans = -1;
        while (a) {
            for (int i = 0; i < a->get_powers().size(); ++i) {
                if (a->get_powers()[i] != 0) {
                    if (ans != i) {
                        if (ans == -1) {
                            ans = i;
                        }
                        else {
                            return 0;
                        }
                    }

                }
            }
            a = a->get_next();
        }
        if (ans == 1) {
            return 0;
        }
        return 1;
    }

private:
    node *first;
};
#endif // POLYNOMAL_H
