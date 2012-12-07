using System;
using System.Collections.Generic;
using System.Text;
using SampleCOMDataType.Interop;

namespace COMMarshalStructure
{
    class Program
    {
        static void Main(string[] args)
        {
            MarshalCOMStructure();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }

        private static void MarshalCOMStructure()
        {
            MarshalCOMDataTypeClass comObj = new MarshalCOMDataTypeClass();

            SampleStruct sampleStruct = new SampleStruct();
            sampleStruct.ID = 1;
            sampleStruct.stringName = "TestString";

            Console.WriteLine("初始结构体数据：\n\tSampleStruct.ID = {0}\n\tSampleStruct.stringName = {1}",
                sampleStruct.ID, sampleStruct.stringName);

            comObj.MarshalStructure(ref sampleStruct);

            Console.WriteLine("更新后结构体数据：\n\tSampleStruct.ID = {0}\n\tSampleStruct.stringName = {1}",
                sampleStruct.ID, sampleStruct.stringName);
        }
    }
}
