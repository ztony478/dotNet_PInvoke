using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace EarlyBinding
{
    [ClassInterface(ClassInterfaceType.AutoDual)]
    public class WeatherManager
    {
        protected int _operationCount;

        public double GetTemperatureCELSIUS()
        {
            _operationCount++;
            return 28;
        }

        // 在ClassInterfaceType为AutoDual时，如果在新版本
        // 的WeatherManager类中加入了GetWindSpeed()新方法，
        // 这样会导致原有的COM客户端调用错误，因为新的方法
        // 改变了COM接口定义的布局。
        //public double GetWindSpeed()
        //{
        //    _operationCount++;
        //    return 10;
        //}

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
