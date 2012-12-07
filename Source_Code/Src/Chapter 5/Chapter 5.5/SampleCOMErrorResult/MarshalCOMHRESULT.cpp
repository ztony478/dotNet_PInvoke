// MarshalCOMHRESULT.cpp : Implementation of CMarshalCOMHRESULT

#include "stdafx.h"
#include "MarshalCOMHRESULT.h"


// CMarshalCOMHRESULT


STDMETHODIMP CMarshalCOMHRESULT::GenerateHRESULTs(int type)
{
	HRESULT hr = S_OK;
	switch(type)
	{
	case 1:
		hr = E_POINTER;
		break;
	case 2:
		hr = E_NOTIMPL;
		break;
	case 3:
		hr = E_ACCESSDENIED;
		break;
	case 4:
		hr = E_OUTOFMEMORY;
		break;
	case 5:
		hr = CO_E_CLRNOTAVAILABLE;
		break;
	case 6:
		hr = CO_E_THREADPOOL_CONFIG;
		break;
	case 7:
		hr = 0x12345678L;
		break;
	default:
		break;
	}

	return hr;
}

STDMETHODIMP CMarshalCOMHRESULT::ReturnHRESULTs(int type, HRESULT* hResult)
{
	HRESULT hr = S_OK;
	switch(type)
	{
	case 1:
		hr = E_POINTER;
		break;
	case 2:
		hr = E_NOTIMPL;
		break;
	case 3:
		hr = E_ACCESSDENIED;
		break;
	case 4:
		hr = E_OUTOFMEMORY;
		break;
	case 5:
		hr = CO_E_CLRNOTAVAILABLE;
		break;
	case 6:
		hr = CO_E_THREADPOOL_CONFIG;
		break;
	case 7:
		hr = 0x12345678L;
		break;
	default:
		break;
	}

	*hResult = hr;

	return hr;
}
