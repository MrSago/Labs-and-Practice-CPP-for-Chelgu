#ifndef AUTO_PTR
#define AUTO_PTR

template<class OperationType>
class auto_ptr
{
private:
	OperationType* ptr;

public:
	auto_ptr(OperationType* obj) : ptr(obj) { }
	auto_ptr(auto_ptr& obj)
	{
		ptr = obj.ptr;
		obj.ptr = nullptr;
	}
	~auto_ptr()
	{
		if (ptr != nullptr)
			delete ptr;
	}

	OperationType& operator*() const { return *ptr; }
	OperationType& operator->() const { return ptr; }
	OperationType& operator[](size_t i) const { return ptr[i]; }
	auto_ptr& operator=(auto_ptr& obj)
	{
		if (this != &obj)
		{
			if (ptr != nullptr)
				delete ptr;

			ptr = obj.ptr;
			obj.ptr = 0;
		}
		return *this;
	}

	bool isNull() const { return ptr == nullptr; }
};

#endif //AUTO_PTR