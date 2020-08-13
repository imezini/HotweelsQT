#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
    friend class iterator;
private:
    class nodo {
    public:
        T info;
        nodo* next;
        nodo(const T&, nodo* = nullptr);
        nodo(const nodo&);
        ~nodo();
    };

    nodo* first;
    nodo* last;
    unsigned int dim; //
public:
    Container(nodo* = nullptr, nodo* = nullptr);
    Container(const T&);
    ~Container();
    const T& operator[](int);

    void addInOrder(const T&);
    bool esiste();

    class iterator {
        friend class Container;
    private:
        nodo* punt;
    public:
        iterator(nodo* = nullptr);
        //bool operator==(const iterator&);
        //bool operator!=(const iterator&);
        iterator& operator++();
        //iterator operator++(int);
        T& operator*();
        nodo* operator->();
    };

    iterator begin();
    iterator end();

};

//Costruttori nodo

template <class T>
Container<T>::nodo::nodo(const T& veicolo, nodo* n) : info(veicolo), next(n) {}

template <class T>
Container<T>::nodo::nodo(const nodo& n) : info(n.info), next(n.next) {}

//costruttore iteratore
template<class T>
Container<T>::iterator::iterator(nodo *it) : punt(it) {}


//Costruttori Container

template<class T>
Container<T>::Container(nodo *f, nodo *l) : first(f), last(l) {}

template<class T>
Container<T>::Container(const T& x) : first(new nodo(x)) {last = first;}

//Metodi Container

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




//metodi iteratore

template<class T>
typename Container<T>::iterator Container<T>::begin() {
    return iterator(first);
}

template<class T>
typename Container<T>::iterator Container<T>::end(){
    return iterator(last); //o nullptr
}

#endif // CONTAINER_H


