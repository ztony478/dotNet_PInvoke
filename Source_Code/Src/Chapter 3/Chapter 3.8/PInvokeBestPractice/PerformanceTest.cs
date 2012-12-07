using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.ComponentModel;

namespace PInvokeBestPractice
{
    class PerformanceTest
    {
        // GetVersionEx的Win32 API定义
        //BOOL WINAPI GetVersionEx(
        //     __inout  LPOSVERSIONINFO lpVersionInfo);

        // Win32 definition of OSVERSIONINFOEX
        //typedef struct _OSVERSIONINFOEX {
        //     DWORD dwOSVersionInfoSize;
        //     DWORD dwMajorVersion;
        //     DWORD dwMinorVersion;
        //     DWORD dwBuildNumber;
        //     DWORD dwPlatformId;
        //     TCHAR szCSDVersion[128];
        //     WORD wServicePackMajor;
        //     WORD wServicePackMinor;
        //     WORD wSuiteMask;
        //     BYTE wProductType;
        //     BYTE wReserved;
        //} OSVERSIONINFOEX, *POSVERSIONINFOEX, *LPOSVERSIONINFOEX;

        #region Non-Blittalbe reference type
        // 使用non-blittable引用类型来定义用于获取系统版本信息的方法
        [DllImport("Kernel32", CharSet = CharSet.Auto, EntryPoint = "GetVersionEx")]
        private static extern Boolean GetVersionEx_Ref_NonBlit([In, Out] OSVersionInfoEx_Ref_NonBlit versionInfo);

        /// <summary>
        /// 这是对Win32 API函数GetVersionEx进行封装后的包装方法
        /// </summary>
        /// <param name="type"></param>
        public void WrapperGetVersionEx_Ref_NonBlit(OSVersionInfoEx_Ref_NonBlit versionInfo)
        {
            if (!GetVersionEx_Ref_NonBlit(versionInfo))
            {
                // 如果失败，获得最后的错误码，并抛出相应的Win32异常
                Int32 err = Marshal.GetLastWin32Error();
                throw new Win32Exception(err);
            }
        }

        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
        public class OSVersionInfoEx_Ref_NonBlit
        {
            public UInt32 OSVersionInfoSize =
                (UInt32)Marshal.SizeOf(typeof(OSVersionInfoEx_Ref_NonBlit));
            public UInt32 MajorVersion = 0;
            public UInt32 MinorVersion = 0;
            public UInt32 BuildNumber = 0;
            public UInt32 PlatformId = 0;
            // 此属性用于表明将其封送成内联数组
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 128)]
            public String CSDVersion = null;
            public UInt16 ServicePackMajor = 0;
            public UInt16 ServicePackMinor = 0;
            public UInt16 SuiteMask = 0;
            public Byte ProductType = 0;
            public Byte Reserved;
        }
        #endregion

        #region Blittable reference type
        // 使用blittable引用类型来定义用于获取系统版本信息的方法
        [DllImport("Kernel32", CharSet = CharSet.Auto, EntryPoint = "GetVersionEx")]
        private static extern Boolean GetVersionEx_Ref_Blit(OSVersionInfoEx_Ref_Blit versionInfor);

        /// <summary>
        /// 这是对Win32 API函数GetVersionEx进行封装后的包装方法
        /// </summary>
        /// <param name="type"></param>
        public void WrapperGetVersionEx_Ref_Blit(OSVersionInfoEx_Ref_Blit versionInfo)
        {
            if (!GetVersionEx_Ref_Blit(versionInfo))
            {
                // 如果失败，获得最后的错误码，并抛出相应的Win32异常 
                Int32 err = Marshal.GetLastWin32Error();
                throw new Win32Exception(err);
            }
        }

        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
        internal class OSVersionInfoEx_Ref_Blit
        {
            public UInt32 OSVersionInfoSize = (UInt32)Marshal.SizeOf(typeof(OSVersionInfoEx_Ref_Blit));
            public UInt32 MajorVersion;
            public UInt32 MinorVersion;
            public UInt32 BuildNumber;
            public UInt32 PlatformId;

            // 使用不安全代码将字符块作为字符串返回
            unsafe public String CSDVersion
            {
                get
                {
                    fixed (Char* str = &CSDVersion0)
                    {
                        return new String(str);
                    }
                }
            }

            // 手动地为内联数组(inline array)定义每一个字符
            Char CSDVersion0; Char CSDVersion1; Char CSDVersion2;
            Char CSDVersion3; Char CSDVersion4; Char CSDVersion5;
            Char CSDVersion6; Char CSDVersion7; Char CSDVersion8;
            Char CSDVersion9; Char CSDVersionA; Char CSDVersionB;
            Char CSDVersionC; Char CSDVersionD; Char CSDVersionE;
            Char CSDVersionF;

            Char CSDVersion10; Char CSDVersion11; Char CSDVersion12;
            Char CSDVersion13; Char CSDVersion14; Char CSDVersion15;
            Char CSDVersion16; Char CSDVersion17; Char CSDVersion18;
            Char CSDVersion19; Char CSDVersion1A; Char CSDVersion1B;
            Char CSDVersion1C; Char CSDVersion1D; Char CSDVersion1E;
            Char CSDVersion1F;

            Char CSDVersion20; Char CSDVersion21; Char CSDVersion22;
            Char CSDVersion23; Char CSDVersion24; Char CSDVersion25;
            Char CSDVersion26; Char CSDVersion27; Char CSDVersion28;
            Char CSDVersion29; Char CSDVersion2A; Char CSDVersion2B;
            Char CSDVersion2C; Char CSDVersion2D; Char CSDVersion2E;
            Char CSDVersion2F;

            Char CSDVersion30; Char CSDVersion31; Char CSDVersion32;
            Char CSDVersion33; Char CSDVersion34; Char CSDVersion35;
            Char CSDVersion36; Char CSDVersion37; Char CSDVersion38;
            Char CSDVersion39; Char CSDVersion3A; Char CSDVersion3B;
            Char CSDVersion3C; Char CSDVersion3D; Char CSDVersion3E;
            Char CSDVersion3F;

            Char CSDVersion40; Char CSDVersion41; Char CSDVersion42;
            Char CSDVersion43; Char CSDVersion44; Char CSDVersion45;
            Char CSDVersion46; Char CSDVersion47; Char CSDVersion48;
            Char CSDVersion49; Char CSDVersion4A; Char CSDVersion4B;
            Char CSDVersion4C; Char CSDVersion4D; Char CSDVersion4E;
            Char CSDVersion4F;

            Char CSDVersion50; Char CSDVersion51; Char CSDVersion52;
            Char CSDVersion53; Char CSDVersion54; Char CSDVersion55;
            Char CSDVersion56; Char CSDVersion57; Char CSDVersion58;
            Char CSDVersion59; Char CSDVersion5A; Char CSDVersion5B;
            Char CSDVersion5C; Char CSDVersion5D; Char CSDVersion5E;
            Char CSDVersion5F;

            Char CSDVersion60; Char CSDVersion61; Char CSDVersion62;
            Char CSDVersion63; Char CSDVersion64; Char CSDVersion65;
            Char CSDVersion66; Char CSDVersion67; Char CSDVersion68;
            Char CSDVersion69; Char CSDVersion6A; Char CSDVersion6B;
            Char CSDVersion6C; Char CSDVersion6D; Char CSDVersion6E;
            Char CSDVersion6F;

            Char CSDVersion70; Char CSDVersion71; Char CSDVersion72;
            Char CSDVersion73; Char CSDVersion74; Char CSDVersion75;
            Char CSDVersion76; Char CSDVersion77; Char CSDVersion78;
            Char CSDVersion79; Char CSDVersion7A; Char CSDVersion7B;
            Char CSDVersion7C; Char CSDVersion7D; Char CSDVersion7E;
            Char CSDVersion7F;

            public UInt16 ServicePackMajor = 0;
            public UInt16 ServicePackMinor = 0;
            public UInt16 SuiteMask = 0;
            public Byte ProductType = 0;
            public Byte Reserved;
        }
        #endregion

        #region Non-Blittalbe value type
        // 使用non-blittable值类型来定义用于获取系统版本信息的方法
        [DllImport("Kernel32", CharSet = CharSet.Auto, EntryPoint = "GetVersionEx")]
        private static extern Boolean GetVersionEx_Val_NonBlit(ref OSVersionInfoEx_Val_NonBlit versionInfo);

        /// <summary>
        /// 这是对Win32 API函数GetVersionEx进行封装后的包装方法
        /// </summary>
        /// <param name="type"></param>
        public void WrapperGetVersionEx_Val_NonBlit(out OSVersionInfoEx_Val_NonBlit versionInfo)
        {
            versionInfo = new OSVersionInfoEx_Val_NonBlit();
            versionInfo.OSVersionInfoSize = (UInt32)Marshal.SizeOf(typeof(OSVersionInfoEx_Val_NonBlit));
            if (!GetVersionEx_Val_NonBlit(ref versionInfo))
            {
                // 如果失败，获得最后的错误码，并抛出相应的Win32异常 
                Int32 err = Marshal.GetLastWin32Error();
                throw new Win32Exception(err);
            }
        }

        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
        internal struct OSVersionInfoEx_Val_NonBlit
        {
            public UInt32 OSVersionInfoSize;
            public UInt32 MajorVersion;
            public UInt32 MinorVersion;
            public UInt32 BuildNumber;
            public UInt32 PlatformId;
            // 此属性用于表明将其封送成内联数组
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 128)]
            public String CSDVersion;
            public UInt16 ServicePackMajor;
            public UInt16 ServicePackMinor;
            public UInt16 SuiteMask;
            public Byte ProductType;
            public Byte Reserved;
        }
        #endregion

        #region Blittable value type
        // 使用blittable值类型来定义用于获取系统版本信息的方法
        [DllImport("Kernel32", CharSet = CharSet.Auto, EntryPoint = "GetVersionEx")]
        private static extern Boolean GetVersionEx_Val_Blit(ref OSVersionInfoEx_Val_Blit versionInfor);

        /// <summary>
        /// 这是对Win32 API函数GetVersionEx进行封装后的包装方法
        /// </summary>
        /// <param name="type"></param>
        public void WrapperGetVersionEx_Val_Blit(out OSVersionInfoEx_Val_Blit versionInfo)
        {
            versionInfo = new OSVersionInfoEx_Val_Blit();
            versionInfo.OSVersionInfoSize = (UInt32)Marshal.SizeOf(typeof(OSVersionInfoEx_Val_Blit));
            if (!GetVersionEx_Val_Blit(ref versionInfo))
            {
                // 如果失败，获得最后的错误码，并抛出相应的Win32异常 
                Int32 err = Marshal.GetLastWin32Error();
                throw new Win32Exception(err);
            }
        }

        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
        internal struct OSVersionInfoEx_Val_Blit
        {
            public UInt32 OSVersionInfoSize;
            public UInt32 MajorVersion;
            public UInt32 MinorVersion;
            public UInt32 BuildNumber;
            public UInt32 PlatformId;

            // 使用不安全代码将字符块作为字符串返回
            unsafe public String CSDVersion
            {
                get
                {
                    fixed (Char* str = &CSDVersion0)
                    {
                        return new String(str);
                    }
                }
            }

            // 手动地为内联数组(inline array)定义每一个字符
            Char CSDVersion0; Char CSDVersion1; Char CSDVersion2;
            Char CSDVersion3; Char CSDVersion4; Char CSDVersion5;
            Char CSDVersion6; Char CSDVersion7; Char CSDVersion8;
            Char CSDVersion9; Char CSDVersionA; Char CSDVersionB;
            Char CSDVersionC; Char CSDVersionD; Char CSDVersionE;
            Char CSDVersionF;

            Char CSDVersion10; Char CSDVersion11; Char CSDVersion12;
            Char CSDVersion13; Char CSDVersion14; Char CSDVersion15;
            Char CSDVersion16; Char CSDVersion17; Char CSDVersion18;
            Char CSDVersion19; Char CSDVersion1A; Char CSDVersion1B;
            Char CSDVersion1C; Char CSDVersion1D; Char CSDVersion1E;
            Char CSDVersion1F;

            Char CSDVersion20; Char CSDVersion21; Char CSDVersion22;
            Char CSDVersion23; Char CSDVersion24; Char CSDVersion25;
            Char CSDVersion26; Char CSDVersion27; Char CSDVersion28;
            Char CSDVersion29; Char CSDVersion2A; Char CSDVersion2B;
            Char CSDVersion2C; Char CSDVersion2D; Char CSDVersion2E;
            Char CSDVersion2F;

            Char CSDVersion30; Char CSDVersion31; Char CSDVersion32;
            Char CSDVersion33; Char CSDVersion34; Char CSDVersion35;
            Char CSDVersion36; Char CSDVersion37; Char CSDVersion38;
            Char CSDVersion39; Char CSDVersion3A; Char CSDVersion3B;
            Char CSDVersion3C; Char CSDVersion3D; Char CSDVersion3E;
            Char CSDVersion3F;

            Char CSDVersion40; Char CSDVersion41; Char CSDVersion42;
            Char CSDVersion43; Char CSDVersion44; Char CSDVersion45;
            Char CSDVersion46; Char CSDVersion47; Char CSDVersion48;
            Char CSDVersion49; Char CSDVersion4A; Char CSDVersion4B;
            Char CSDVersion4C; Char CSDVersion4D; Char CSDVersion4E;
            Char CSDVersion4F;

            Char CSDVersion50; Char CSDVersion51; Char CSDVersion52;
            Char CSDVersion53; Char CSDVersion54; Char CSDVersion55;
            Char CSDVersion56; Char CSDVersion57; Char CSDVersion58;
            Char CSDVersion59; Char CSDVersion5A; Char CSDVersion5B;
            Char CSDVersion5C; Char CSDVersion5D; Char CSDVersion5E;
            Char CSDVersion5F;

            Char CSDVersion60; Char CSDVersion61; Char CSDVersion62;
            Char CSDVersion63; Char CSDVersion64; Char CSDVersion65;
            Char CSDVersion66; Char CSDVersion67; Char CSDVersion68;
            Char CSDVersion69; Char CSDVersion6A; Char CSDVersion6B;
            Char CSDVersion6C; Char CSDVersion6D; Char CSDVersion6E;
            Char CSDVersion6F;

            Char CSDVersion70; Char CSDVersion71; Char CSDVersion72;
            Char CSDVersion73; Char CSDVersion74; Char CSDVersion75;
            Char CSDVersion76; Char CSDVersion77; Char CSDVersion78;
            Char CSDVersion79; Char CSDVersion7A; Char CSDVersion7B;
            Char CSDVersion7C; Char CSDVersion7D; Char CSDVersion7E;
            Char CSDVersion7F;

            public UInt16 ServicePackMajor;
            public UInt16 ServicePackMinor;
            public UInt16 SuiteMask;
            public Byte ProductType;
            public Byte Reserved;
        }
        #endregion

        #region Blittable type that does not contain inline array
        // 使用blittable值类型来定义用于获取系统版本信息的方法
        [DllImport("Kernel32", CharSet = CharSet.Unicode, EntryPoint = "GetVersionEx")]
        private static extern Boolean GetVersionEx_Layout_Explicit(OSVersionInfoEx_Layout_Explicit versionInfor);

        /// <summary>
        /// 这是对Win32 API函数GetVersionEx进行封装后的包装方法
        /// </summary>
        /// <param name="type"></param>
        public void WrapperGetVersionEx_Layout_Explicit(OSVersionInfoEx_Layout_Explicit versionInfo)
        {
            if (!GetVersionEx_Layout_Explicit(versionInfo))
            {
                // 如果失败，获得最后的错误码，并抛出相应的Win32异常 
                Int32 err = Marshal.GetLastWin32Error();
                throw new Win32Exception(err);
            }
        }

        [StructLayout(LayoutKind.Explicit, CharSet = CharSet.Unicode, Size=284)]
        internal class OSVersionInfoEx_Layout_Explicit
        {
            [FieldOffset(0)]
            public UInt32 OSVersionInfoSize = (UInt32)Marshal.SizeOf(typeof(OSVersionInfoEx_Layout_Explicit));
            [FieldOffset(4)]
            public UInt32 MajorVersion;
            [FieldOffset(8)]
            public UInt32 MinorVersion;
            [FieldOffset(12)]
            public UInt32 BuildNumber;
            [FieldOffset(16)]
            public UInt32 PlatformId;
            // 这里省略掉内联数组CHAR szCSDVersion[128]
            [FieldOffset(276)]
            public UInt16 ServicePackMajor = 0;
            [FieldOffset(278)]
            public UInt16 ServicePackMinor = 0;
            [FieldOffset(280)]
            public UInt16 SuiteMask = 0;
            [FieldOffset(282)]
            public Byte ProductType = 0;
            [FieldOffset(283)]
            public Byte Reserved;
        }
        #endregion

        public void PerfTest(Int32 testIterations)
        {
            Console.WriteLine("Test Iteration for each type: {0}", testIterations);
            // 1. Non-blittable reference type
            // Start with a fresh managed heap
            GC.Collect(); 
            GC.WaitForPendingFinalizers(); 
            GC.Collect();

            // Start time
            DateTime start = DateTime.Now;

            // Create the marshalled instance and perform calls
            OSVersionInfoEx_Ref_NonBlit info_ref_nonblit = new OSVersionInfoEx_Ref_NonBlit();
            for (Int32 index = 0; index < testIterations; index++)
            {
                // We will not user wrapper method so that we can test on pure performance 
                // WrapperGetVersionEx_Ref_NonBlit(info_ref_nonblit);
                GetVersionEx_Ref_NonBlit(info_ref_nonblit);
            }

            // End time
            TimeSpan span = DateTime.Now - start;

            // Output results
            Console.WriteLine("Non-blittable reference type marshalling took: \t{0} secs", span.TotalSeconds);

            // 2. Blittalbe reference type
            // Start with a fresh managed heap
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();

            // Start time
            start = DateTime.Now;

            // Create the marshalled instance and perform calls
            OSVersionInfoEx_Ref_Blit info_ref_blit = new OSVersionInfoEx_Ref_Blit();
            for (Int32 index = 0; index < testIterations; index++)
            {
                // We will not user wrapper method so that we can test on pure performance 
                // WrapperGetVersionEx_Ref_Blit(info_ref_blit);
                GetVersionEx_Ref_Blit(info_ref_blit);
            }

            // End time
            span = DateTime.Now - start;

            // Output results
            Console.WriteLine("Blittable reference type marshalling took: \t{0} secs", span.TotalSeconds);
                       
            // 3. Non-blittalbe value type
            // Start with a fresh managed heap
            GC.Collect(); 
            GC.WaitForPendingFinalizers();
            GC.Collect();

            // Start time
            start = DateTime.Now;

            // Create the marshalled instance and perform calls
            OSVersionInfoEx_Val_NonBlit info_val_nonblit = new OSVersionInfoEx_Val_NonBlit();
            
            // If we use the wrapper method, the next statement is not necessary, since the wrapper method will do the stuff.
            info_val_nonblit.OSVersionInfoSize = (UInt32)Marshal.SizeOf(typeof(OSVersionInfoEx_Val_NonBlit));
            for (Int32 index = 0; index < testIterations; index++)
            {
                // We will not user wrapper method so that we can test on pure performance 
                // WrapperGetVersionEx_Val_NonBlit(out info_val_nonblit);
                GetVersionEx_Val_NonBlit(ref info_val_nonblit);
            }

            // End time
            span = DateTime.Now - start;

            // Output results
            Console.WriteLine("Non-blittable value type marshalling took : \t{0} secs", span.TotalSeconds);

            // 4. Blittalbe value type
            // Start with a fresh managed heap
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();

            // Start time
            start = DateTime.Now;

            // Create the marshalled instance and perform calls
            OSVersionInfoEx_Val_Blit info_val_blit = new OSVersionInfoEx_Val_Blit();
            
            // If we use the wrapper method, the next statement is not necessary, since the wrapper method will do the stuff.
            info_val_blit.OSVersionInfoSize = (UInt32)Marshal.SizeOf(typeof(OSVersionInfoEx_Val_Blit));
            for (Int32 index = 0; index < testIterations; index++)
            {
                // We will not user wrapper method so that we can test on pure performance 
                // WrapperGetVersionEx_Val_Blit(out info_val_blit);
                GetVersionEx_Val_Blit(ref info_val_blit);
            }

            // End time
            span = DateTime.Now - start;


            // Output results
            Console.WriteLine("Blittable value type marshalling took : \t{0} secs", span.TotalSeconds);

            // Dump version info
            Console.WriteLine("{0}Current system version information:", Environment.NewLine);
            Console.WriteLine("OSVersionInfoSize: \t{0}", info_val_blit.OSVersionInfoSize);
            Console.WriteLine("MajorVersion: \t\t{0}", info_val_blit.MajorVersion);
            Console.WriteLine("MinorVersion: \t\t{0}", info_val_blit.MinorVersion);
            Console.WriteLine("BuildNumber: \t\t{0}", info_val_blit.BuildNumber);
            Console.WriteLine("PlatformId: \t\t{0}", info_val_blit.PlatformId);
            Console.WriteLine("CSDVersion: \t\t{0}", info_val_blit.CSDVersion);
            Console.WriteLine("ServicePackMajor: \t{0}", info_val_blit.ServicePackMajor);
            Console.WriteLine("ServicePackMinor: \t{0}", info_val_blit.ServicePackMinor);
            Console.WriteLine("SuiteMask: \t\t{0}", info_val_blit.SuiteMask);
            Console.WriteLine("ProductType: \t\t{0}", info_val_blit.ProductType);
            Console.WriteLine("Reserved: \t\t{0}", info_val_blit.Reserved);
            Console.WriteLine();
        }

        public void ExplicitLayoutTest(Int32 testIterations)
        {
            Console.WriteLine("Test Iteration for each type: {0}", testIterations);
            // Blittable reference type with explicit struct layout
            // Start with a fresh managed heap
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();

            // Start time
            DateTime start = DateTime.Now;

            // Create the marshalled instance and perform calls
            OSVersionInfoEx_Layout_Explicit info_explicit_layout = new OSVersionInfoEx_Layout_Explicit();

            for (Int32 index = 0; index < testIterations; index++)
            {
                // We will not user wrapper method so that we can test on pure performance 
                // WrapperGetVersionEx_Layout_Explicit(out info_explicit_layout);
                GetVersionEx_Layout_Explicit(info_explicit_layout);
            }

            // End time
            TimeSpan span = DateTime.Now - start;

            // Output results
            Console.WriteLine("Explicit layout blittable type marshalling took : \t{0} secs", span.TotalSeconds);

            // Dump version info
            Console.WriteLine("{0}Current system version information:", Environment.NewLine);
            Console.WriteLine("OSVersionInfoSize: \t{0}", info_explicit_layout.OSVersionInfoSize);
            Console.WriteLine("MajorVersion: \t\t{0}", info_explicit_layout.MajorVersion);
            Console.WriteLine("MinorVersion: \t\t{0}", info_explicit_layout.MinorVersion);
            Console.WriteLine("BuildNumber: \t\t{0}", info_explicit_layout.BuildNumber);
            Console.WriteLine("PlatformId: \t\t{0}", info_explicit_layout.PlatformId);
            Console.WriteLine("ServicePackMajor: \t{0}", info_explicit_layout.ServicePackMajor);
            Console.WriteLine("ServicePackMinor: \t{0}", info_explicit_layout.ServicePackMinor);
            Console.WriteLine("SuiteMask: \t\t{0}", info_explicit_layout.SuiteMask);
            Console.WriteLine("ProductType: \t\t{0}", info_explicit_layout.ProductType);
            Console.WriteLine("Reserved: \t\t{0}", info_explicit_layout.Reserved);
            Console.WriteLine();
 
        }

    }
}
