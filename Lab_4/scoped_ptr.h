#ifndef SCOPED_PTR
#define SCOPED_PTR

template<class OperationType>
class scoped_ptr
{
	private:
		OperationType* ptr;

	public:
		scoped_ptr(OperationType* obj) : ptr(obj) { }
		~scoped_ptr()
		{
			if (ptr != nullptr)
				delete ptr;
		}

		OperationType& operator*() const { return *ptr; }
		OperationType& operator->() const { return ptr; }
		OperationType& operator[](size_t i) const { return ptr[i]; }

		bool isNull() const { return ptr == nullptr; }

	private:
		scoped_ptr(const OperationType&);
		const OperationType& operator=(const OperationType&) const;
};

#endif //SCOPED_PTR