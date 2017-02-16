#ifndef SCOPED_PTR_H
#define SCOPED_PTR_H

template <typename T>
struct ScopedPtr
{
    explicit ScopedPtr(T *ptr = 0):ptr_(ptr){}
     ~ScopedPtr();

    T* get() const;
    T* release();
    void reset(T *ptr = 0);

    T& operator*() const;
    T* operator->() const;

private:
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    T *ptr_;
};

template <typename T>
ScopedPtr<T>::~ScopedPtr()
{
    delete ptr_;
}

template <typename T>
T* ScopedPtr<T>::get() const
{
    return ptr_;
}

template <typename T>
T* ScopedPtr<T>::release()
{
    T* temp = ptr_;
    ptr_ = 0;
    return temp;
}

template <typename T>
void ScopedPtr<T>::reset(T *ptr)
{
    delete ptr_;
    ptr_ = ptr;
}

template <typename T>
T& ScopedPtr<T>::operator*() const
{
    return *ptr_;
}

template <typename T>
T* ScopedPtr<T>::operator->() const
{
    return ptr_;
}

#endif // SCOPED_PTR_H
