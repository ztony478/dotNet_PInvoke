using System;
using System.Collections.Generic;
using System.Text;
using SampleCOMCollection.Interop;

namespace COMMarshalCollection
{
    class Program
    {
        static void Main(string[] args)
        {
            MarshalCOMCollection();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();	
        }

        private static void MarshalCOMCollection()
        {
            MarshalCOMCollectionClass comObj = new MarshalCOMCollectionClass();
            Console.WriteLine("初始图书数：{0}", comObj.Count);
            Console.WriteLine("图书列表：");
            foreach (string dinosaur in comObj)
            {
                Console.WriteLine("\t{0}", dinosaur);
            }

            string addedElement = "《精通.NET互操作性：P/Invoke，C++ Interop和COM Interop》";
            Console.WriteLine("\n新添加图书：{0}", addedElement);
            comObj.AddElement(addedElement);

            Console.WriteLine("\n添加后图书数：{0}", comObj.Count);
            Console.WriteLine("图书列表：");
            foreach (string dinosaur in comObj)
            {
                Console.WriteLine("\t{0}", dinosaur);
            }
        }
    }
}
