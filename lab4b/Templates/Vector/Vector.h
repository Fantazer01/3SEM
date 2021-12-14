//
// Created by oleg on 10.12.2021.
//

#ifndef LAB4B_VECTOR_H
#define LAB4B_VECTOR_H

template <typename T>
class Vector {
public:
    class iterator{
    private:
        T *ptr;
    public:
        iterator(): ptr(nullptr) {}
        iterator(const T *&_ptr): ptr(_ptr) {}

        T& operator *() { return *ptr; }

    };
private:
    static const uint step = 10;
    T *ptr;
    uint SZ;
    uint SZ_arr;

    void increaseMemory()
    { T *ptr2 = new T[SZ_arr+step]; for (int i = 0; i < SZ_arr; ++i) ptr2[i] = ptr[i]; delete[] ptr; ptr = ptr2; SZ_arr += step; }
    void rewriteOnOneStep()
    {
        T temp;
        if (SZ == 0) return;
        if (SZ == 1) { ptr[1] = ptr[0]; return; }
        temp = ptr[0];
        for (int i = 1; i < SZ+1; ++i) { swap(temp, ptr[i]); }
    }
public:
    Vector(): ptr(new T[step]), SZ(0), SZ_arr(step) {}
    Vector(uint _size): SZ(_size), SZ_arr(_size) { if (SZ > 0) ptr = new T[SZ]; else ptr = nullptr; }
    Vector(const Vector<T> &_vector_): SZ(_vector_.SZ), SZ_arr(_vector_.SZ_arr), ptr(new T[SZ_arr])
    { for (int i = 0; i < SZ; ++i) *(ptr+i) = *(_vector_.ptr+i); }
    ~Vector() { delete [] ptr; }

    bool empty() const { return SZ == 0; }
    uint size() const { return SZ; }
    void resize(uint _size)
    {
        if (SZ_arr == _size) return;
        T *ptr2 = new T[_size];
        if (SZ > _size) SZ = _size;
        for (int i = 0; i < SZ; ++i) ptr2[i] = ptr[i];
        delete[] ptr;
        ptr = ptr2;
        SZ_arr = _size;
    }

    T& operator [] (const uint &index) { if (index < SZ) return *(ptr+index); throw std::invalid_argument("invalid value!"); }
    const T& operator [] (const uint &index) const { if (index < SZ) return *(ptr+index); throw std::invalid_argument("invalid value!"); }

    void push_back(const T &temp)
    { if (SZ >= SZ_arr) { resize(SZ_arr+step); } *(ptr+SZ) = temp; ++SZ; }
    void push_front(const T &temp)
    { if (SZ >= SZ_arr) { resize(SZ_arr+step); } rewriteOnOneStep(); ptr[0] = temp; }


};

#endif //LAB4B_VECTOR_H
