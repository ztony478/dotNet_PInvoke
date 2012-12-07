#include "stdafx.h"
#include <conio.h>
#include <objbase.h>
#include <atlbase.h>
#import "mscorlib.tlb"
#import "MarshalEvent.tlb" no_namespace named_guids

CComModule _Module;

// 定义Sink接口类
// 这里使用了保留关键字“interface”, 这样比使用“class”关键字更直观
// 当然使用class不会对程序产生任何影响
interface CSink:public IDispEventImpl<0, CSink, &DIID_IStockPriceBeeper, &LIBID_MarshalEvent, 1, 0>
{
public:

// 这里的第三个参数是定义在托管COM服务器中的[DispId(17)]的16进制表示
BEGIN_SINK_MAP(CSink)
	SINK_ENTRY_EX(0, DIID_IStockPriceBeeper, 0x11, OnPriceChanged)
END_SINK_MAP()

// 必须使用“HRESULT __stdcall”定义
	HRESULT __stdcall OnPriceChanged(double newPrice, double oldPrice)
	{
		wprintf(L"新股价：%.2f，前一交易日股价：%.2f\n", newPrice, oldPrice);
		return S_OK;
	}
};

void TestEvent()
{
	// 初始化ATL
	_Module.Init(NULL, GetModuleHandle(NULL));

	// 创建COM对象
	IStockPriceControlPtr comObj(__uuidof(StockPriceControlObj));
	if (comObj)
	{
		CSink sink;
		// 挂接事件
		sink.DispEventAdvise(comObj);

		// 触发事件
		comObj->ChangeStockPrice(18);
		comObj->ChangeStockPrice(38);
		comObj->ChangeStockPrice(28);
		comObj->ChangeStockPrice(58);

		// 取消事件订阅
		sink.DispEventUnadvise(comObj);

		// 释放COM对象
		comObj.Release();
	}

	// 终止ATL
	_Module.Term();
	
}
