template<class T,class D=Delete<T>>
class Shared_ptr
{
public:
	Shared_ptr(T *ptr)
		:use_count(new int(1))
		, _ptr(ptr)
	{}
	Shared_Ptr(const Shared_Ptr<T, D>& sp)
		:_ptr(sp._ptr)
		, use_count(sp._use_count)
	{
		++(*use_count);
	}
	inline void Release()
	{
       if (--(*use_count) == 0)
		{
			delete use_count;
			_del(_ptr);
		}
	}
	SharedPtr<T, D>& operator=(const SharedPtr<T, D>& sp)
	{
		// 
		//this->Release();
		if (_ptr != sp._ptr)
		{
			Release();
			_ptr = sp._ptr;
			use_count = sp.use_count;
			++(*use_count);
		}
		return *this;
	}
	~shared_ptr()
	{
		Release();
	}
protected:
	int * use_count;
	T *_ptr;
	D _del;
};
int main()
{
	Shared_ptr<int> sp1(new int(2));
	return 0;
}
