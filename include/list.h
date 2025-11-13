#pragma once

template<typename T> class TSinglyList
{
	struct TNode
	{
		T value;
		TNode* pNext;
		TNode(T data, TNode* n)
		{
			value = data;
			pNext = n;
		}
		TNode& operator=(const TNode& node)
		{
			value = node.value;
			pNext = node.pNext;
		}
	};
	TNode* pFirst;
	TNode* pEnd;
	size_t sz;
public:
	TSinglyList()
	{
		pFirst = nullptr;
		pEnd = nullptr;
		sz = 0;
	}
	TSinglyList(const vector<T>& v)
	{
		sz = 0;
		pFirst = nullptr;
		pEnd = nullptr;
		for (size_t i = 0; i < v.size(); i++)
		{
			PushBack(v[i]);
		}
	}
	TSinglyList(const TSinglyList& list)
	{
		sz = 0;
		pFirst = nullptr;
		pEnd = nullptr;
		for (int i = 0; i < list.sz; i++)
		{
			pushBack(list[i].value);
		}
	}
	TSinglyList(TSinglyList&& list) noexcept
	{
		pFirst = nullptr;
		pEnd = nullptr;
		sz = 0;
		swap(*this, list);
	}
	TSinglyList& operator=(const TSinglyList& list)
	{
		Clean();
		for (int i = 0; i < list.sz; i++)
		{
			pushBack(list[i].value);
		}
		return *this;
	}
	void Clean()
	{
		TNode *pCurrent = pFirst;
		while (pCurrent != pEnd)
		{
			TNode* tmp = pCurrent->pNext;
			delete pCurrent;
			pCurrent = tmp;
		}
		
		pFirst = nullptr;
		pEnd = nullptr;
		sz = 0;
	}
	void swap(TSinglyList& 1hs, TSinglyList& 2hs)
	{
		std::swap(1hs.sz, 2hs.sz);
		std::swap(1hs.pFirst, 2hs.pFirst);
		std::swap(1hs.pEnd, 2hs.pEnd);
	}
	TSinglyList& operator=(const TSinglyList&& list)noexcept
	{
		Clean();
		swap(*this, list);
		return *this;
	}
	~TSinglyList()
	{
		Clean();
	}
	size_t size() const noexcept;
	{
		return sz;
	}
	bool IsEmpty() const noexcept;
	{
		return(sz == 0);
	}
	T& Front()noexcept
	{
		return pFirst->value;
	}
	void PushFront(const T& val)
	{
		TNode* t = new TNode(val, pFirst);
		pFirst = t;
		if (pEnd == nullptr)// если 1 элемент в цепочке
		{
			pEnd = t;
		}
		sz++;
	}
	void PushBack(const T& val)
	{
		TNode* t = new TNode(val, nullptr);
		pEnd->pNext = t;
		pEnd = t;
		if (pFirst == nullptr)// если 1 элемент в цепочке ( сначала 0)
		{
			pFirst = t;
		}
		sz++;
	}
	void PopFront()noexcept
	{
		if (sz = 0)
		{
			return;
		}
		TNode* tmp = pFirst->pNext;
		delete pFirst;
		pFirst = tmp;
		if (sz == 1)
		{
			pEnd = nullptr;
		}
		sz--;
	}
	T& operator[](size_t pos)
	{
		TNode* tmp = pFirst;
		if (sz == 0 || pos>=sz || pos<0)
		{
			throw 1;
		}
		if (pos ==0)
		{
			return tmp->value;
		}
		for (int i = 0; i < pos; i++)
		{
			tmp = tmp->pNext;
		}
		return tmp->value;
	}
	void PushAfter(size_t pos, const T& val)
	{
		TNode* tmp = pFirst;
		if (pos < 0 || pos >= sz || sz ==0)
		{
			throw 1;
		}
		else
		{

			for (int i = 0; i < pos; i++)
			{
				tmp = tmp->pNext;
			}
			TNode* t = new TNode(val, tmp->pNext);
			tmp->pNext = t;
			if (pos == sz - 1) // последний
			{
				pEnd = t;
			}
			sz++;
		}
		
	void EraseAfter(size_t pos)
	{
		TNode* tmp = pFirst;
		if (pos < 0 || pos >= sz || sz == 0)
		{
			throw 1;
		}
		else
		{

			for (int i = 0; i < pos; i++)
			{
				tmp = tmp->pNext;
			}
			TNode* t = tmp->pNext->pNext;
			delete tmp->pNext;
			tmp->pNext = t;
			if (pos == sz - 2)// предпоследний
			{
				pEnd = tmp;
			}
			sz--;
		}	
};