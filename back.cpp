#include "back.h"
#include "base.h"
#include <QMessageBox>
#include <vector>

std::string alf = "abcdefghijklmnopqrstuvwxyz";
std::vector <std::string> text_array;
int curr = -1;
base *baza;
int cnt_of_bases = 0;

node* add(std::string str) {
    bool last_sign = 1;
    int i = 0;
    curr = 0;
    int multy = 1;
    int prev = 0;
    std::vector <int> pow(26, 0);
    node* first = nullptr;
    node* last = nullptr;
    int num = 0;
    while (i < str.size()) {
        try {
            while (i < str.size() && (str[i] == ' ')) {
                ++i;
            }
            if(i == str.size()){
                continue;
            }
            if (alf.find(str[i]) == -1) {
                if (i < str.size() && str[i] - '0' >= 0 && str[i] - '0' <= 9) {
                    if (curr == 5) {
                        throw(6);
                    }
                    if (curr == 1) {
                        throw(1);
                    }
                    int power = str[i] - '0';
                    ++i;
                    while (i < str.size() && str[i] - '0' >= 0 && str[i] - '0' <= 9) {
                        power *= 10;
                        power += str[i] - '0';
                        ++i;
                    }
                    multy = power;
                    curr = 1;
                }
                else if (str[i] == '+') {
                    if(curr == 0){
                        throw(4);
                    }
                    if(i == 0){
                        ++i;
                        continue;
                    }
                    if (curr == 2) {
                        throw(4);
                    }
                    if (curr == 4) {
                        throw(4);
                    }

                    if (first == nullptr) {
                        first = new node;
                        first->multiplier = multy;
                        first->power = pow;
                        first->next = nullptr;
                        first->sign = last_sign;
                        last = first;
                    }
                    else {
                        node* p = new node;
                        p->next = nullptr;
                        p->multiplier = multy;
                        p->power = pow;
                        p->sign = last_sign;
                        last->next = p;
                        last = last->next;
                    }
                    last_sign = 1;

                    curr = 2;
                    pow.clear();
                    pow.resize(26, 0);
                    multy = 1;
                    ++i;
                }
                else if (str[i] == '-') {
                    if(i == 0){
                        last_sign = 0;
                        ++i;
                        continue;
                    }
                    if (curr == 2) {
                        throw(4);
                    }
                    if (curr == 4) {
                        throw(4);
                    }
                    if (first == nullptr) {
                        first = new node;
                        first->multiplier = multy;
                        first->power = pow;
                        first->next = nullptr;
                        first->sign = last_sign;
                        last = first;
                    }
                    else {
                        node* p = new node;
                        p->next = nullptr;
                        p->multiplier = multy;
                        p->power = pow;
                        p->sign = last_sign;
                        last->next = p;
                        last = last->next;
                    }
                    last_sign = 0;
                    curr = 2;
                    pow.clear();
                    pow.resize(26, 0);
                    multy = 1;
                    ++i;
                }
                else if (str[i] == '^') {
                    if (curr == 4 || curr == 5 || curr == 2 || curr == 3) {
                        throw(6);
                    }
                    ++i;


                    if (curr == 0 || i >= str.size()) {
                        throw(1);
                    }
                    if (alf.find(str[i]) != -1) {
                        throw(2);
                    }
                    curr = 2;
                    int plov = 0;
                    while (i < str.size() && str[i] - '0' >= 0 && str[i] - '0' <= 9) {
                        plov += str[i] - '0';
                        plov *= 10;
                        curr = 5;
                        ++i;
                    }
                    plov /= 10;

                    if (curr == 2) {
                        throw(3);
                    }
                    curr = 5;
                    pow[num] += plov - 1;
                }
                else{
                    throw(3);
                }

            }
            else if(alf.find(str[i]) != -1) {
                curr = 1;
                num = alf.find(str[i]);
                prev = num;
                pow[num] += 1;
                ++i;
            }
            else {
                throw(3);
            }
        }
        catch (int a) {
            if (a == 0) {
                QMessageBox::about(nullptr, " incorrect", " there is double param\n");
                return nullptr;
            }
            else if (a == 1) {
                QMessageBox::about(nullptr, " incorrect", " ^ in wrong place");
                return nullptr;
            }
            else if (a == 2) {
                QMessageBox::about(nullptr, " incorrect", " param in wrong place");
                return nullptr;
            }
            else if (a == 3) {
                QMessageBox::about(nullptr, " incorrect", " incorrect input");
                return nullptr;
            }
            else if (a == 4) {
                QMessageBox::about(nullptr, " incorrect", " sign in wrong place");
                return nullptr;
            }
            else if (a == 5) {
                QMessageBox::about(nullptr, " incorrect", " mutiplier is in wrong place");
                return nullptr;
            }
            else if (a == 6) {
                QMessageBox::about(nullptr, " incorrect", " power is in cascade");
                return nullptr;
            }
        }
    }
    try {
        if (curr == 3 || curr == 2) {
            throw(0);
        }
    }
    catch (int a) {
        if (a == 0) {
            QMessageBox::about(nullptr, " incorrect", " sign in wrong place");
            return nullptr;
        }
    }
    if (first == nullptr) {
        first = new node;
        first->multiplier = multy;
        first->power = pow;
        first->next = nullptr;
        first->sign = last_sign;
        last = first;
    }
    else {
        node* p = new node;
        p->next = nullptr;
        p->multiplier = multy;
        p->power = pow;
        p->sign = last_sign;
        last->next = p;
        last = last->next;
    }
    return first;
}

node* solve(std::string str ){
    node* first = add(str);
    if(first == nullptr){
        return nullptr;
    }
    std::string a;
    node* elem = first;
    std::map <std::vector <int>, int> map_of_polynomal;
    std::vector <std::vector <int>> arr;
    while (elem != nullptr) {
        bool is = false;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == elem->get_powers()) {
                is = true;
                break;
            }
        }
        if (!is) {
            arr.push_back(elem->get_powers());
        }
        if (elem->get_sign() == 1) {
            map_of_polynomal[elem->get_powers()] += elem->get_multiplier();
        }else{
            map_of_polynomal[elem->get_powers()] -= elem->get_multiplier();
        }
        elem = elem->get_next();
    }

    node* norm_polynom = new node;
    node* f = norm_polynom;
    for (int i = 0; i < arr.size(); ++i) {
        int m = map_of_polynomal[arr[i]];
        node* p = new node;
        f->set_sign(1);
        if (m < 0) {
            m = -m;
            f->set_sign(0);
        }
        f->set_multiplier(m);
        f->set_power(arr[i]);
        if (i != arr.size() - 1) {
            f->set_next(p);
            f = f->get_next();

        }
        else {
            delete p;
        }
    }
    while (first != nullptr) {
        node* p = first->get_next();
        delete first;
        first = p;
    }
    return norm_polynom;
}

node* addition(node* y, node* x) {
    node* first = y;
    node* f2 = x;
    node* elem = first;
    if (elem != nullptr) {
        while (elem->get_next() != nullptr) {
            elem = elem->get_next();
        }
        int n = 0;
        for(node* elem = x; elem != nullptr; elem = elem->get_next()){
            ++n;
        }
        elem->set_next(f2);
        for(int i = 0; i<n;++i){
            elem= elem->get_next();
        }
        node*ss = nullptr;
        elem->set_next(ss);
    }
    else {
        first = f2;
    }
    std::string a;
    elem = first;
    std::map <std::vector <int>, int> map_of_polynomal;
    std::vector <std::vector <int>> arr;
    while (elem != nullptr) {
        bool is = false;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == elem->get_powers()) {
                is = true;
                break;
            }
        }
        if (!is) {
            arr.push_back(elem->get_powers());
        }
        if (elem->get_sign() == 1) {
            map_of_polynomal[elem->get_powers()] += elem->get_multiplier();
        }
        else {
            map_of_polynomal[elem->get_powers()] -= elem->get_multiplier();
        }
        elem = elem->get_next();
    }
    node* norm_polynom = new node;
    node* f = norm_polynom;
    for (int i = 0; i < arr.size(); ++i) {
        int m = map_of_polynomal[arr[i]];
        node* p = new node;
        f->set_sign(1);
        if (m < 0) {
            m = -m;
            f->set_sign(0);
        }
        f->set_multiplier(m);
        f->set_power(arr[i]);
        if (i != arr.size() - 1) {
            f->set_next(p);
            f = f->get_next();

        }
        else {
            delete p;
        }
    }
    while (first != nullptr) {
        node* p = first->get_next();
        delete first;
        first = p;
    }
    return norm_polynom;
}

node* multiplicate(node*y, node *x) {
    node* first = x;
    node* second = y;
    if (x == nullptr) {
        return y;
    }
    if(y == nullptr){
        return x;
    }
    node* ans = new node;
    node* e = ans;
    while (first != nullptr) {
        node* elem = y;
        std::vector <int> arr;
        while (elem != nullptr) {
            int m = first->get_multiplier();
            m *= elem->get_multiplier();
            arr = first->get_powers();
            std::vector <int> arrtwo = elem->get_powers();
            for (int i = 0; i < arrtwo.size(); ++i) {
                arr[i] += arrtwo[i];
            }
            e->set_power(arr);
            e->set_multiplier(m);
            e->set_sign(elem->get_sign() * first->get_sign());
            if(!elem->get_sign() && !first->get_sign()){
                e->set_sign(1);
            }
            if ((first->get_next() != nullptr) || elem->get_next() != nullptr) {
                node* k = new node;
                e->set_next(k);
                e = e->get_next();
                elem = elem->get_next();
            }
            else {
                elem = elem->get_next();
            }
        }
        first = first->get_next();
    }
    /*node* elem = ans;
    std::string a;
    while (elem != nullptr) {
        if (elem->get_multiplier() == 0) {
            std::vector <int> lllll(26, 0);
            elem->set_power(lllll);
            elem = elem->get_next();
            continue;
        }
        if (elem->get_sign() == 1) {
            a += "+";
        }
        if (elem->get_sign() == 0) {
            a += "-";
        }
        if (elem->get_multiplier() > 1) {
            a += std::to_string(elem->get_multiplier());
        }
        for (int i = 0; i < elem->get_powers().size(); ++i) {
            if (elem->get_powers()[i] != 0) {
                a += alf[i];
                if (elem->get_powers()[i] != 1) {
                    a += '^';
                    a += std::to_string(elem->get_powers()[i]);
                }
            }
        }
        elem = elem->get_next();
    }
    std::cout << a;*/
    return ans;
}

int n_of_powers(std::vector <int> array) {
    int ans = 0;
    for (int i = 0; i < array.size(); ++i) {
        ans += array[i];
    }
    return ans;
}

std::string cout_node(node* n) {
    node* elem = n;
    std::string a;
    bool null = false;
    while (elem != nullptr) {
        if(elem->get_multiplier() == 0) {
            null = 1;
            elem = elem->get_next();
            continue;
        }

        if (elem->get_sign() == 1) {
            if(a.size() != 0){
                 a += "+";
            }

        }
        if (elem->get_sign() == 0) {
            a += "-";
        }
        if (elem->get_multiplier() != 0) {
            a += std::to_string(elem->get_multiplier());
        }
        for (int i = 0; i < elem->get_powers().size(); ++i) {
            if (elem->get_powers()[i] != 0) {
                a += alf[i];
                if (elem->get_powers()[i] != 1) {
                    a += '^';
                    a += std::to_string(elem->get_powers()[i]);
                }
            }
        }
        elem = elem->get_next();
    }
    if(a.size() == 0) {
        a+='0';
    }
    return a;
}

void bubble_sort(node*& a) {
    node* elem = a;


    while (elem != nullptr) {
        node* elem_two = a;
        while (elem_two) {
            if (elem_two->get_next() != nullptr) {
                if (n_of_powers(elem_two->get_powers()) >
                    n_of_powers(elem_two->get_next()->get_powers())) {
                    node* res;
                    res = new node();
                    *res = *elem_two->get_next();
                    node* rez;
                    rez = new node();
                    *rez = *elem_two;
                    node* help = res->get_next();
                    rez->set_next(help);
                    res->set_next(rez);
                    *elem_two = *res;
                    elem_two = elem_two->get_next();

                }
                else {
                    elem_two = elem_two->get_next();

                }
            }
            else {
                elem_two = elem_two->get_next();

            }
        }
        elem = elem->get_next();
    }

}

std::vector <int> search_an_solution(polynomal &first) {
    node* a = first.get_first();
    if (a == nullptr) {
        return { };
    }
    std::vector < int> result;
    std::vector <int> den;

    //bool osteosarcoma = false;
    node* raccoon = first.get_first();
    while (a->get_next()) {
        a = a->get_next();
    }
    /*for (int i = 0; i < alf.size(); ++i) {
        if (a->get_powers()[i] != 0) {
            osteosarcoma = true;
        }
    }*/
    den.push_back(0);
    for (int i = 1; i <= raccoon->get_multiplier(); ++i) {
        if (raccoon->get_multiplier() % i == 0) {
            den.push_back(i);
            den.push_back(-i);
        }
    }

    for (int i = 0; i < den.size(); ++i) {
        node* b = first.get_first();
        long long ans = 0;
        while (b) {
            int power = 0;
            for (int j = 0; j < alf.size(); ++j) {
                if (b->get_powers()[j] != 0) {
                    power = b->get_powers()[j];
                }
            }
            int anne = b->get_multiplier();
            while (power != 0) {
                anne *= den[i];
                --power;
            }
            if (b->get_sign() == 0) {
                anne = - anne;
            }
            ans += anne;
            b = b->get_next();
        }
        if (ans == 0) {
            result.push_back(den[i]);
        }
    }
    return result;
}

void search_derivative(polynomal &f, int number) {
    node * a = f.get_first();
    node * p;
    while(a) {
        std::vector <int> array = a->get_powers();
        int pow = array[number];
        if(pow >=1){
            array[number]-=1;
            a->set_multiplier(a->get_multiplier()*pow);
            pow-=1;

        }
        else {
            a->set_multiplier(0);
        }
        a->set_power(array);
        a = a->get_next();
    }
}

node* un_multiplicate(node* b){
    node * elem = b;
    while(elem){
        elem->set_sign(!elem->get_sign());
        elem = elem->get_next();
    }
    return b;
}

int get_pow(node*a){
    if(!a){
        return 0;
    }
    for(int i = 0; i < alf.size(); ++i){
        if(a->get_powers()[i] != 0){
            return a->get_powers()[i];
        }
    }
    return 0;
}

void un_bubble_sort(node*& a) {
    node* elem = a;
    while (elem != nullptr) {
        node* elem_two = a;
        while (elem_two) {
            if (elem_two->get_next() != nullptr) {
                if (n_of_powers(elem_two->get_powers()) <
                    n_of_powers(elem_two->get_next()->get_powers())) {
                    node* res;
                    res = new node();
                    *res = *elem_two->get_next();
                    node* rez;
                    rez = new node();
                    *rez = *elem_two;
                    node* help = res->get_next();
                    rez->set_next(help);
                    res->set_next(rez);
                    *elem_two = *res;
                    elem_two = elem_two->get_next();

                }
                else {
                    elem_two = elem_two->get_next();

                }
            }
            else {
                elem_two = elem_two->get_next();

            }
        }
        elem = elem->get_next();
    }

}

int find_letter(node*a){
    for(int i = 0; i < a->get_powers().size(); ++i){
        if(a->get_powers()[i] != 0){
            return i;
        }
    }
}

node* den_mono
    (node*&a, node* b){

    node *ans;
    int powera = get_pow(a);
    int powerb = get_pow(b);
    if(powera < powerb){
        return nullptr;
    }
    int multi = a->get_multiplier() / b->get_multiplier();
    if(multi == 0){
        return a;
    }
    std::vector  <int> array(26, 0);
    array[find_letter(b)] = powera-powerb;
    node * den = new node(multi, array, !a->get_sign());
    node* devops = multiplicate(den, b);
    a = addition(a, devops);
    return den;
}

node *den(node *aa, node* bb){
    node * ans = new node;
    if(bb->get_multiplier() == 0){
        QMessageBox::about(nullptr, "incorrect", "den on 0");
        return nullptr;
    }
    node *a = new node;
    node *helper = aa;
    node *a_elem = a;
    while(helper){
        *a_elem = *helper;
        if(helper->get_next()){
            node* q = new node;
            a_elem->set_next(q);
            a_elem = a_elem->get_next();

        }
        helper = helper->get_next();
    }
    un_bubble_sort(a);
    un_bubble_sort(bb);
    node * e = ans;
    while(a){
        node *qqq = den_mono(a, bb);
        if(qqq == nullptr){
            node * elem = ans;
            if(elem == e){
                ans = nullptr;
            }
            while(elem->get_next() != e){
                elem = elem->get_next();
            }
            elem->set_next_nullptr();
            break;
        }
        *e = *qqq;
        if(a->get_next()){
            node * q = new node;
            e->set_next(q);
            e = e->get_next();
        }
        a = a->get_next();
    }
    node* elem = ans;
    std::map <std::vector <int>, int> map_of_polynomal;
    std::vector <std::vector <int>> arr;
    while (elem != nullptr) {
        bool is = false;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == elem->get_powers()) {
                is = true;
                break;
            }
        }
        if (!is) {
            arr.push_back(elem->get_powers());
        }
        if (elem->get_sign() == 1) {
            map_of_polynomal[elem->get_powers()] += elem->get_multiplier();
        }else{
            map_of_polynomal[elem->get_powers()] -= elem->get_multiplier();
        }
        elem = elem->get_next();
    }

    node* norm_polynom = new node;
    node* f = norm_polynom;
    for (int i = 0; i < arr.size(); ++i) {
        int m = map_of_polynomal[arr[i]];
        node* p = new node;
        f->set_sign(1);
        if (m < 0) {
            m = -m;
            f->set_sign(0);
        }
        f->set_multiplier(m);
        f->set_power(arr[i]);
        if (i != arr.size() - 1) {
            f->set_next(p);
            f = f->get_next();

        }
        else {
            delete p;
        }
    }

    return norm_polynom;
}

