using System;
using System.Collections.Generic;
using System.Text;


namespace DotNetVersionOfWin32
{
    class Program
    {
        static void Main(string[] args)
        {

            //此文件存在
            string srcFileExist = "srcXMLFile.xml";
            //此文件存在且它的文件属性为只读
            string destFileReadOnly = "destXMLFileReadOnly.xml";

            //源文件不存在
            string srcFileNotExist = "srcXMLFile1.xml";
            string destFile = "destXMLFile.xml";

            // 测试对Win32 API函数进行平台调用的方法
            //CopyFileWin32.Test(srcFileExist, destFileReadOnly, true);
            //CopyFileWin32.Test(srcFileNotExist, destFile, true);

            // 测试托管方法
            CopyFileManaged.Test(srcFileExist, destFileReadOnly, true);
            CopyFileManaged.Test(srcFileNotExist, destFile, true);


            // 测试对Win32 API函数进行平台调用的方法
            //try
            //{
            //    CopyFileWin32.Test(srcFile, destFile, true);
            //}
            //catch (Exception exc)
            //{
            //    Console.WriteLine("Copying file using Win32 P/Invoke, error message: {0}", exc.Message);
            //}

            //// 测试托管方法
            //try
            //{
            //    CopyFileManaged.Test(srcFile, destFile, true);
            //}
            //catch (Exception exc)
            //{
            //    Console.WriteLine("Copying file using managed fuction, error message: {0}", exc.Message);
            //}

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }
    }
}
