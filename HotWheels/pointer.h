#ifndef POINTER_H
#define POINTER_H


template <class T>
class pointer{
private:
    T* pted;
public:
    pointer(T* =nullptr);
    pointer(const pointer&);
    pointer& operator=(const pointer&);
    T* operator->() const;
    ~pointer();
    bool operator==(const pointer&) const;
    bool operator!=(const pointer&) const;
    bool operator>(const pointer&) const;
    bool operator<(const pointer&) const;
    operator T*() const;

};

template <class T>
pointer<T>::pointer(T* itm): pted(itm){}

template <class T>
pointer<T>::pointer(const pointer& dptr){
      if(!dptr)
          pted=nullptr;
      else
          pted=dptr.pted->clone();
}

template <class T>
pointer<T>& pointer<T>::operator=(const pointer& dptr){
        if(this != &dptr){
            if(pted)
                delete pted;
            pted = dptr.pted->clone();
    }
    return *this;
}

template <class T>
T* pointer<T>::operator->() const{
       return pted;
}

template <class T>
pointer<T>::~pointer(){
    if(pted)
        delete pted;
}

template <class T>
bool pointer<T>::operator==(const pointer& dptr) const{
    return *pted==*(dptr.pted);
}

template <class T>
bool pointer<T>::operator!=(const pointer& dptr) const{
    return *pted!=*(dptr.pted);
}

template<class T>
bool pointer<T>::operator<(const pointer& dptr) const{
    return *pted<*(dptr.pted);
}

template<class T>
bool pointer<T>::operator>(const pointer& dptr) const{
    return *pted>*(dptr.pted);
}

template<class T>
pointer<T>::operator T *() const
{
    return pted;
}


#endif // POINTER_H
