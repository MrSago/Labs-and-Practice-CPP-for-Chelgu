#ifndef SHARED_PTR
#define SHARED_PTR

#include <vector>

template<class OperationType>
class shared_ptr
{
	struct Storage {
		OperationType *ptr;
		size_t count = 0;
	};

	private: static inline std::vector<Storage> setOfPointers;
			 size_t index;

	public:
		shared_ptr(OperationType *obj)
		{
			bool finded = false;

			for (size_t i = 0; setOfPointers.size(); ++i)
			{
				if (setOfPointers.at(i).ptr == obj)
				{
					finded = true;
					index = i;
					setOfPointers.at(i).count++;
				}
			}

			if (!finded)
			{
				Storage tmp;
				tmp.count = 1;
				tmp.ptr = obj;
				setOfPointers.push_back(tmp);
				index = setOfPointers.size() - 1;
			}
		}
		shared_ptr(const shared_ptr &obj)
		{
			index = obj.index;
			setOfPointers.at(index).count++;
		}
		~shared_ptr()
		{
			setOfPointers.at(index).count--;
			if (setOfPointers.at(index).count == 0)
			{
				delete setOfPointers.at(index).ptr;
				setOfPointers.erase(setOfPointers.begin() + index);
			}
		}

		shared_ptr& operator=(const shared_ptr& obj)
		{
			if (index == obj.index)
				return *this;

			if (setOfPointers.at(index).count == 1)
				delete setOfPointers.at(index).ptr;

			index = obj.index;
			return *this;
		}

		OperationType& operator*() const { return *(setOfPointers.at(index).ptr); }
		OperationType& operator->() const { return setOfPointers.at(index).ptr; }
		OperationType& operator[](size_t i) const { return setOfPointers.at(index).ptr[i]; }
};

#endif //SHARED_PTR