//-----------------------------------------------------------------------------
// SoRefObject
// (C) oil
// 2013-07-12
//-----------------------------------------------------------------------------
#ifndef _SoRefObject_h_
#define _SoRefObject_h_
//-----------------------------------------------------------------------------
namespace GGUI
{
	class SoRefObject
	{
	public:
		SoRefObject();
		virtual ~SoRefObject();

		void IncRefCount();
		void DecRefCount();
		int GetRefCount() const;
		static int GetTotalObjectCount();

	protected:
		virtual void DeleteThis();

	protected:
		int m_nRefCount;
	private:
		static int ms_nTotalObjectCount;
	};
}
//-----------------------------------------------------------------------------
#endif //_SoRefObject_h_
//-----------------------------------------------------------------------------
