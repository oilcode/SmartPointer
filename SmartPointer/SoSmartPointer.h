//-----------------------------------------------------------------------------
// SoSmartPointer
// (C) oil
// 2013-07-12
//-----------------------------------------------------------------------------
#ifndef _SoSmartPointer_h_
#define _SoSmartPointer_h_
//-----------------------------------------------------------------------------
namespace GGUI
{
	template <class T>
	class SoSmartPointer
	{
	public:
		SoSmartPointer();
		SoSmartPointer(T* pT);
		SoSmartPointer(const SoSmartPointer& spT);
		~SoSmartPointer();

		operator T*() const;
		T& operator *() const;
		T* operator ->() const;

		SoSmartPointer& operator = (const SoSmartPointer& spT);
		SoSmartPointer& operator = (T* pT);

		bool operator == (const T* pT) const;
		bool operator != (const T* pT) const;
		bool operator == (const SoSmartPointer& spT) const;
		bool operator != (const SoSmartPointer& spT) const;

	private:
		T* m_pObject;
	};
	//-----------------------------------------------------------------------------
	template <class T>
	inline SoSmartPointer<T>::SoSmartPointer()
	{
		m_pObject = 0;
	}
	//-----------------------------------------------------------------------------
	template <class T>
	inline SoSmartPointer<T>::SoSmartPointer(T* pT)
	{
		m_pObject = pT;
		if (m_pObject)
		{
			m_pObject->IncRefCount();
		}
	}
	//-----------------------------------------------------------------------------
	template <class T>
	inline SoSmartPointer<T>::SoSmartPointer(const SoSmartPointer& spT)
	{
		m_pObject = spT.m_pObject;
		if (m_pObject)
		{
			m_pObject->IncRefCount();
		}
	}
	//-----------------------------------------------------------------------------
	template <class T>
	inline SoSmartPointer<T>::~SoSmartPointer()
	{
		if (m_pObject)
		{
			m_pObject->DecRefCount();
		}
	}
	//-----------------------------------------------------------------------------
	template <class T>
	inline SoSmartPointer<T>::operator T*() const
	{
		return m_pObject;
	}
	//-----------------------------------------------------------------------------
	template <class T>
	T& SoSmartPointer<T>::operator *() const
	{
		return *m_pObject;
	}
	//-----------------------------------------------------------------------------
	template <class T>
	T* SoSmartPointer<T>::operator ->() const
	{
		return m_pObject;
	}
	//-----------------------------------------------------------------------------
	template <class T>
	SoSmartPointer<T>& SoSmartPointer<T>::operator = (const SoSmartPointer& spT)
	{
		if (m_pObject != spT.m_pObject)
		{
			if (m_pObject)
			{
				m_pObject->DecRefCount();
			}
			m_pObject = spT.m_pObject;
			if (m_pObject)
			{
				m_pObject->IncRefCount();
			}
		}
		return *this;
	}
	//-----------------------------------------------------------------------------
	template <class T>
	SoSmartPointer<T>& SoSmartPointer<T>::operator = (T* pT)
	{
		if (m_pObject != pT)
		{
			if (m_pObject)
			{
				m_pObject->DecRefCount();
			}
			m_pObject = pT;
			if (m_pObject)
			{
				m_pObject->IncRefCount();
			}
		}
		return *this;
	}
	//-----------------------------------------------------------------------------
	template <class T>
	bool SoSmartPointer<T>::operator == (const T* pT) const
	{
		return (m_pObject == pT);
	}
	//-----------------------------------------------------------------------------
	template <class T>
	bool SoSmartPointer<T>::operator != (const T* pT) const
	{
		return (m_pObject != pT);
	}
	//-----------------------------------------------------------------------------
	template <class T>
	bool SoSmartPointer<T>::operator == (const SoSmartPointer& spT) const
	{
		return (m_pObject == spT.m_pObject);
	}
	//-----------------------------------------------------------------------------
	template <class T>
	bool SoSmartPointer<T>::operator != (const SoSmartPointer& spT) const
	{
		return (m_pObject != spT.m_pObject);
	}
}
//-----------------------------------------------------------------------------
#endif //_SoSmartPointer_h_
//-----------------------------------------------------------------------------
