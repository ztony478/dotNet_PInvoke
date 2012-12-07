using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace LateBinding
{
    [ClassInterface(ClassInterfaceType.AutoDispatch)]
    public class WeatherManager
    {
        protected int _operationCount;

        public double GetTemperatureCELSIUS()
        {
            _operationCount++;
            return 28;
        }

        public double ConvertCelsius2Fahrenheit(double CelsiusDegree)
        {
            _operationCount++;
            return CelsiusDegree * 1.8 + 32;
        }

        public int OperationCount
        {
            get { return _operationCount; }
        }
    }
}
