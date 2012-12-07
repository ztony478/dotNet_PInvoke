using System;
using System.Collections.Generic;
using System.Text;

namespace MarshalFullExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Test();

            Console.WriteLine("\r\n按任意键退出...");
            Console.Read();
        }

        private static void Test()
        {
            NameEntityType allType = NameEntityType.OrganizationName | NameEntityType.PersonName | NameEntityType.PlaceName;
            using (NameFinderWrapper nameFinder = new NameFinderWrapper(allType))
            {
                bool isInit = nameFinder.Initialize(@".\data");
                if (isInit)
                {
                    List<NameEntity> nameResults;
                    string text = @"今天，来自全国各地的优秀学子聚集北京。在微软亚洲研究院听取了洪小文院长、王坚院长和郭百宁院长的精彩演讲。";
                    Console.WriteLine("输入文本：{0}{1}", Environment.NewLine, text);
                    bool isSuccess = nameFinder.FindNames(text, out nameResults);
                    if (isSuccess)
                    {
                        Console.WriteLine("名字解析成功，结果如下：");
                        Console.WriteLine("\t     名字\t\t类型\t     起始位置\t长度\t模型概率");
                        Console.WriteLine("          -------------------------------------------------------------");
                        foreach (NameEntity name in nameResults)
                        {
                            Console.WriteLine("{0, 15}\t{1, 18}\t{2, -4}\t{3, 2}\t{4, -4}",
                                name.Name,
                                name.Type,
                                name.HighlightBegin,
                                name.HighlightLength,
                                name.Score);
                        }

                        Console.WriteLine();
                    }
                }
            }
        }

    }
}
