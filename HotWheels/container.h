#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include<QStringList>
#include<pointer.h>

using std::string;

template <class T>
class Container {
private:
    class nodo {
        friend class Container<T>;
    private:
        T info;
        nodo* next;
        nodo(const T&, nodo* = nullptr);
        nodo(const nodo&);
        void distruggi();
    };
    nodo* first, *last;
    static nodo* clone(nodo*, nodo*&);

public:
    Container();
    Container(const T&);
    Container(const Container&);
    ~Container();
    Container& operator=(const Container&);


    void addInOrder(const T&);
    void rimpiazzaFinale(unsigned int, const T&);
    void rimuoviIndice(const unsigned int);
    T prendiNodoIndice(const unsigned int) const;
    unsigned int trovaIndiceNodo(const T&);
    void clear();
    bool isEmpty() const;


    class constIteratore
    {
        friend class Container<T>;
    private:
        const nodo* punt;
        constIteratore(nodo*);
    public:
        constIteratore();
        constIteratore& operator=(const constIteratore&);
        constIteratore& operator++();
        constIteratore& operator++(int);
        const T& operator*() const;
        const T* operator->() const;
        bool operator==(const constIteratore&);
        bool operator!=(const constIteratore&);
    };


    class Iteratore{
        friend class Container<T>;
    private:
        nodo * punt;
        Iteratore(nodo *);
    public:
        Iteratore();
        Iteratore& operator=(const Iteratore&);
        Iteratore &operator++();
        Iteratore &operator++(int);
        T &operator*() const;
        T *operator->() const;
        bool operator==(const Iteratore &);
        bool operator!=(const Iteratore &);

    };
    constIteratore begin() const;
    constIteratore end() const;
    Iteratore begin();
    Iteratore end();
};

template <class T>
Container<T>::nodo::nodo(const T& obj, nodo* n) : info(obj), next(n) {}

template <class T>
Container<T>::nodo::nodo(const nodo& n):info(n.info), next(n.next){}

template<class T>
void Container<T>::nodo::distruggi()
{
    if (next) next->distruggi();
    delete this;
}

template<class T>
typename Container<T>::nodo* Container<T>::clone(nodo * pri, nodo *& ult)
{
    if (pri == nullptr)
    {
        ult = nullptr;
        return nullptr;
    }
    nodo* p = new nodo(pri->info, clone(pri->next, ult));
    if(pri->next == nullptr) ult = p;
    return p;
}

template<class T>
Container<T>::Container() : first(nullptr), last(nullptr) {}

template <class T>
Container<T>::Container(const T& obj): first(new nodo(obj)){ last=first;}

template<class T>
Container<T>::Container(const Container & q) : first(clone(q.first, last)) {}

template<class T>
Container<T>::~Container()
{
    if (first) first->distruggi();
}

template<class T>
Container<T>& Container<T>::operator=(const Container & q)
{
    if (this != &q)
    {
        if(first) delete first;
        first = clone(q.first, last);
    }
    return *this;
}

template<class T>
void Container<T>::addInOrder(const T& veicolo) {
    nodo* autoveicolo = new nodo(veicolo);
    if(first == nullptr)
        first = last = autoveicolo;
    else if(first->info > autoveicolo->info) {
        autoveicolo->next = first;
        first = autoveicolo;
    }
    else {
        nodo* tmp = first;
        while (tmp->next && tmp->next->info < autoveicolo->info)
            tmp = tmp->next;
        autoveicolo->next = tmp->next;
        tmp->next = autoveicolo;
        if (autoveicolo->next == nullptr)
            last = autoveicolo;
    }
}


template<class T>
void Container<T>::rimpiazzaFinale(unsigned int indice, const T& clienteModificato){
    rimuoviIndice(indice);
    addInOrder(clienteModificato);
}

template <class T>
void Container<T>::rimuoviIndice(const unsigned int i){
    if(isEmpty())
        return;

    if(!first->next){
        if(i==0){
            delete first;
            first=nullptr;
            return;
        }
    }
    else{
        nodo* prec=first;
        nodo* corr=first->next;

        if(i==0){
            first=first->next;
            prec->next=nullptr;
            delete prec;
            return;
        }

        for(unsigned int x=1; corr->next && x<i; x++){
            prec=prec->next;
            corr=corr->next;
        }

        if(corr){
            prec->next=corr->next;
            corr->next=nullptr;
            delete corr;
            return;
        }
    }

    return;
}

template <class T>
T Container<T>::prendiNodoIndice(const unsigned int i) const{
    if(!first->next){
        if(i==0){
            return first->info;
        }
    }
    else{
        nodo* corr=first->next;

        if(i==0){
            return first->info;
        }

        for(unsigned int x=1; corr->next && x<i; x++){
            corr=corr->next;
        }

        if(corr){
            return corr->info;
        }
    }
    T temp;
    return temp;
}

template<class T>
unsigned int Container<T>::trovaIndiceNodo(const T& nodoDaTrovare) {
    unsigned int i=0;
    nodo* corr = first;
    bool trovato = false;
    while (trovato == false && corr->next){
        if (corr->info == nodoDaTrovare) trovato = true;
        else {
            corr = corr->next;
            i=i+1;
        }
    }
    return i;
}

template<class T>
void Container<T>::clear()
{
    if (first){
        first->distruggi();
        first = nullptr;
    }
}

template<class T>
bool Container<T>::isEmpty() const
{
    return (first==nullptr);
}

template<class T>
Container<T>::constIteratore::constIteratore(nodo * p) : punt(p) {}

template<class T>
Container<T>::constIteratore::constIteratore() : punt(nullptr) {}

template<class T>
typename Container<T>::constIteratore & Container<T>::constIteratore::operator=(const constIteratore & cit)
{
    punt=cit.punt;
    return *this;
}

template<class T>
typename Container<T>::constIteratore& Container<T>::constIteratore::operator++()
{
    if(punt) punt=punt->next;
    return *this;

}
template<class T>
typename Container<T>::constIteratore& Container<T>::constIteratore::operator++(int)
{
    Iteratore aux=*this;
    if(punt) punt=punt->next;
    return aux;

}

template<class T>
const T & Container<T>::constIteratore::operator*() const
{
    return punt->info;
}

template<class T>
const T * Container<T>::constIteratore::operator->() const
{
    return &(punt->info);
}

template<class T>
bool Container<T>::constIteratore::operator==(const constIteratore& cit)
{
    return punt == cit.punt;
}

template<class T>
bool Container<T>::constIteratore::operator!=(const constIteratore& cit)
{
    return punt != cit.punt;
}

template<class T>
Container<T>::Iteratore::Iteratore(nodo * p) : punt(p) {}

template<class T>
Container<T>::Iteratore::Iteratore() : punt(nullptr) {}

template<class T>
typename Container<T>::Iteratore & Container<T>::Iteratore::operator=(const Iteratore & it)
{
    punt=it.punt;
    return *this;
}

template<class T>
typename Container<T>::Iteratore& Container<T>::Iteratore::operator++()
{
    if(punt) punt=punt->next;
    return *this;

}
template<class T>
typename Container<T>::Iteratore& Container<T>::Iteratore::operator++(int)
{
    Iteratore aux=*this;
    if(punt) punt=punt->next;
    return aux;

}

template<class T>
T & Container<T>::Iteratore::operator*() const
{
    return punt->info;
}

template<class T>
T * Container<T>::Iteratore::operator->() const
{
    return &(punt->info);
}

template<class T>
bool Container<T>::Iteratore::operator==(const Iteratore& it)
{
    return punt == it.punt;
}

template<class T>
bool Container<T>::Iteratore::operator!=(const Iteratore& it)
{
    return punt != it.punt;
}


template<class T>
typename Container<T>::constIteratore Container<T>::begin() const
{
    return constIteratore(first);
}

template<class T>
typename Container<T>::constIteratore Container<T>::end() const
{
    return constIteratore(nullptr);
}

template<class T>
typename Container<T>::Iteratore Container<T>::begin()
{
    return Iteratore(first);
}

template<class T>
typename Container<T>::Iteratore Container<T>::end()
{
    return Iteratore(nullptr);
}

#endif

