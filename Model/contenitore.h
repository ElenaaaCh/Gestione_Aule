#ifndef CONTENITORE_H
#define CONTENITORE_H

#include<algorithm>

template <class T>
class contenitore{
    friend class iteratore;
    friend class iteratore_const;
private:
    class nodo{
    public:
        T info;
        nodo* next;
        nodo();
        ~nodo();
        nodo(const nodo&);
        nodo(const T&, nodo*);
    };
    nodo* head;
    static nodo* copia(nodo*);

public:
    class iteratore{
        friend class contenitore<T>;
    private:
        nodo* p;
        nodo* getNodo();
    public:
        iteratore();
        iteratore(nodo*);
        iteratore &operator++();
        iteratore &operator++(int);
        T &operator*();
        T *operator->();
        bool operator ==(const iteratore&)const;
        bool operator !=(const iteratore&)const;
    };
    class iteratore_const{
        friend class contenitore<T>;
    private:
        nodo* p;
        const nodo* getNodo() const;
    public:
        iteratore_const();
        iteratore_const(const iteratore&);
        iteratore_const(nodo*);
        iteratore_const& operator++();
        iteratore_const& operator++(int);
        const T& operator*() const;
        const T* operator->() const;
        bool operator==(const iteratore_const&)const;
        bool operator!=(const iteratore_const&)const;
    };
    contenitore();
    contenitore(const contenitore&);
    ~contenitore();

    bool operator==(const contenitore&)const;
    bool operator!=(const contenitore&)const;
    contenitore& operator=(const contenitore&);

    void push(const T&);
    int size() const;
    void clear();
    bool contains(const T&) const;
    T& value(int _pos);
    const T& value(int _pos) const;
    void remove(int _pos);
    void remove(const T& t);
    void replace(int _pos, const T&);
    void insertSorted(const T& item, std::function<bool(const T&, const T&)> compare);

    iteratore begin();
    iteratore end();
    iteratore_const begin()const;
    iteratore_const end()const;
};

#endif // CONTENITORE_H
