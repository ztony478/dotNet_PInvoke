// MarshalCOMCollection.cpp : Implementation of CMarshalCOMCollection

#include "stdafx.h"
#include "MarshalCOMCollection.h"


// CMarshalCOMCollection
STDMETHODIMP CMarshalCOMCollection::AddElement(BSTR elem)
{
	m_coll.push_back(_bstr_t(elem));
	return S_OK;
}
