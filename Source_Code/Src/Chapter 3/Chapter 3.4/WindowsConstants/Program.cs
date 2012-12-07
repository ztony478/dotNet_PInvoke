using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace WindowsConstants
{
    class Program
    {
        static void Main(string[] args)
        {

            // 实际测试时，应该修改成你要获得的文件的路径，
            // 这里演示的文件，只是我机器上存在的文件
            string filePath = Path.Combine(Environment.CurrentDirectory, "Sample_Chapter_Bak.docx");

            string fileTypeName = ManagedSHGetFileInfoWrapper.GetFileTypeName(filePath);
            Console.WriteLine(fileTypeName);

            System.Drawing.Icon iconForMSWord = ManagedSHGetFileInfoWrapper.GetFileIcon(filePath, false, IconSize.Small);
            Console.WriteLine("Icon file handle:" + iconForMSWord.Handle);

            // More about how to save icons from C#, can be found at:
            //Icons in Win32
            //http://msdn.microsoft.com/library/en-us/dnwui/html/msdn_icons.asp 
            // How to save Icon using C#
            //http://www.kennyandkarin.com/Kenny/CodeCorner/Tools/IconBrowser/

            Console.Write("回收站的名称：");
            ManagedSHGetFileInfoTest.FetchProcDisplayName();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }

        

    }
}

