// MarshalCOMEvent.cpp : Implementation of CMarshalCOMEvent

#include "stdafx.h"
#include "MarshalCOMEvent.h"
#include <comutil.h>

// CMarshalCOMEvent
STDMETHODIMP CMarshalCOMEvent::ChangeStringValue(BSTR originalString)
{
	_bstr_t buffer;
	buffer.Assign(originalString);
	buffer += "_ChangedEvent";
	BSTR changedString = buffer.Detach();

	Fire_OnStringChanged(originalString, changedString);

	return S_OK;
}
