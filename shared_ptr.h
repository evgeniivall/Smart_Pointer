#ifndef SHARED_PTR_H
#define SHARED_PTR_H

template <typename T>
struct SharedPtrData
{
  SharedPtrData(T* ptr):pointer_(ptr), counter(1){}
  T* pointer_;
  int counter;
  ~SharedPtrData()
  {
    delete pointer_;
  }
};

template <typename T>
struct SharedPtr
{
    explicit SharedPtr(T *ptr = 0);
    ~SharedPtr();
    SharedPtr(const SharedPtr &other);
    SharedPtr& operator=(const SharedPtr &other);
    T* get() const;
    void reset(T *ptr = 0);
    T& operator*() const;
    T* operator->() const;
private:
    SharedPtrData<T>* ptr_;
};


template <typename T>
SharedPtr<T>::SharedPtr(T *ptr)
{
    if(ptr)
    {
        ptr_ = new SharedPtrData<T>(ptr);
    }
    else
    {
        ptr_ = 0;
    }
}


template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if(ptr_)
    {
        ptr_->counter--;
        if(!ptr_->counter)
        {
            delete ptr_;
        }
    }
}


template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &other)
{
    if(other.ptr_)
    {
        ptr_ = other.ptr_;
        ptr_-> counter++;
    }
    else
    {
        ptr_ = other.ptr_;
    }
}


template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T> &other)
{
    if(this != &other)
    {
        if(ptr_)
        {
            ptr_->counter--;
            if(!ptr_->counter)
            {
                delete ptr_;
            }
        }
    if(other.ptr_)
    {
        other.ptr_->counter++;
    }
    ptr_ = other.ptr_;
    }
    return *this;
}


template <typename T>
T* SharedPtr<T>::get() const
{
  return (ptr_->pointer_);
}


template <typename T>
void SharedPtr<T>::reset(T *ptr)
{
    if(ptr_)
    {
        if(ptr_->counter > 1)
        {
            ptr_->counter--;
        }
        else
        {
            delete ptr_;
        }
    }
    if(ptr)
    {
        ptr_ = new SharedPtrData<T>(ptr);
    }
    else
    {
        ptr_ = 0;
    }

}

template <typename T>
T& SharedPtr<T>::operator*() const
{
    return *(ptr_->pointer_);
}

template <typename T>
T* SharedPtr<T>::operator->() const
{
    return ptr_->pointer_;
}

#endif // SHARED_PTR_H
