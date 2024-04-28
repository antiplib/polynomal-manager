#pragma once

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

class node
{
public:
    ~node() = default;
    node() {
        this->multiplier = 1;
        this->next = nullptr;
        this->power.resize(26, 0);
    }

    node(std::vector <int> pow, int m) {
        this->power = pow;
        this->multiplier = m;
        this->next = nullptr;
    }

    node(int m, std::vector <int> pow, bool s) {
        this->multiplier = m;
        this->power = pow;
        this->sign = s;
    }

    node* get_next() {
        return this->next;
    }

    void set_next(node*& n) {
        this->next = n;
    }

    void set_next_two(node* n) {
        this->next = n;
    }

    std::vector <int> get_powers() {
        return this->power;
    }
    void set_next_nullptr(){
        this->next=nullptr;
    }
    void set_power(std::vector <int> pow) {
        this->power = pow;
    }

    int get_multiplier() {
        return this->multiplier;
    }

    void set_multiplier(int m) {
        this->multiplier = m;
    }

    bool get_sign() {
        return this->sign;
    }
    void set_sign(bool a) {
        this->sign = a;
    }

    bool is_only_variable() {
        int ans = 0;
        for (int i = 0; i < this->power.size(); ++i) {
            if (power[i] != 0) {
                ans += 1;
            }
        }
        if (ans == 1) {
            return 1;
        }
        return 0;
    }

    void push_back(std::vector <int> p, bool sign, int m) {
        node* nn = new node;
        nn->power = p;
        nn->sign = sign;
        nn->multiplier = m;
        this->next = nn;
    }

    bool is_equal(node* p) {
        for (int i = 0; i < this->power.size(); ++i) {
            if (p->power[i] != this->power[i]) {
                return 0;
            }
        }
        return 1;
    }

    friend node* add(std::string);

private:
    std::vector <int> power;
    node* next;
    bool sign;
    int multiplier;
};

#endif // NODE_H
