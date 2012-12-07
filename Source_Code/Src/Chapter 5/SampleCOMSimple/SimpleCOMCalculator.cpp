// SimpleCOMCalculator.cpp : Implementation of CSimpleCOMCalculator

#include "stdafx.h"
#include "SimpleCOMCalculator.h"


// CSimpleCOMCalculator


STDMETHODIMP CSimpleCOMCalculator::Add(int num0, int num1, int* result)
{
	*result = num0 + num1;
	return S_OK;
}

STDMETHODIMP CSimpleCOMCalculator::Subtract(int num0, int num1, int* result)
{
	*result = num0 - num1;
	return S_OK;
}

STDMETHODIMP CSimpleCOMCalculator::Multiply(int num0, int num1, int* result)
{
	*result = num0 * num1;
	return S_OK;
}

STDMETHODIMP CSimpleCOMCalculator::Divide(int num0, int num1, double* result)
{
	*result = (double)num0 / num1;
	return S_OK;
}

STDMETHODIMP CSimpleCOMCalculator::Factorial(int* n)
{
	int num = *n;
	int result = 1;
	while(num > 1)
	{
		result *= num;
		num--;
	}

	*n = result;
	return S_OK;
}
