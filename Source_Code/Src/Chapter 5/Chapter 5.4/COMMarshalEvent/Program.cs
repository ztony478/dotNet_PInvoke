using System;
using System.Collections.Generic;
using System.Text;
using SampleCOMEvent.Interop;

namespace COMMarshalEvent
{
    class Program
    {
        static void Main(string[] args)
        {
            MarshalCOMEvent();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }

        private static void MarshalCOMEvent()
        {
            MarshalCOMEventClass comObj = new MarshalCOMEventClass();
            comObj.OnStringChanged += new _IMarshalCOMEventEvents_OnStringChangedEventHandler(comObj_OnStringChanged);
            comObj.ChangeStringValue("原始字符串");
        }

        static void comObj_OnStringChanged(string originalString, string changedString)
        {
            Console.WriteLine("COM event fired.");
            Console.WriteLine("The original string = {0}", originalString);
            Console.WriteLine("The changed string = {0}", changedString);
        }
    }
}
