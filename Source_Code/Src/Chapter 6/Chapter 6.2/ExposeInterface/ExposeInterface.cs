using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace ExposeInterface
{
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    public interface IWeatherManager
    {
        double GetTemperatureCELSIUS();
        double ConvertCelsius2Fahrenheit(double CelsiusDegree);
        int OperationCount { get; }
    }

    [ClassInterface(ClassInterfaceType.None)]
    public class WeatherManagerObj : IWeatherManager
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

    // 对接口的扩展
    public interface IWeatherManagerEx : IWeatherManager
    {
        double GetWindSpeed();
    }

    [ClassInterface(ClassInterfaceType.None)]
    [ComDefaultInterface(typeof(IWeatherManager))]
    public class WeatherManagerExObj : IWeatherManagerEx
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


        public double GetWindSpeed()
        {
            return 10;
        }

    }

}
