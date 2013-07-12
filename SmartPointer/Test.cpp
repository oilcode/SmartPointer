#include "SoRefObject.h"
#include "SoSmartPointer.h"
using namespace GGUI;

class TestObj : public SoRefObject
{

};
typedef SoSmartPointer<TestObj> TestObjPtr;

void main()
{
	TestObjPtr spObj = new TestObj;
	TestObjPtr spObj2(spObj);
	TestObjPtr spObj3 = spObj;
	TestObj* pObj = spObj;
	TestObjPtr spObj4 = pObj;
	spObj = 0;
	spObj2 = 0;
	spObj3 = 0;
	spObj4 = 0;

}