using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using SampleCOMSimple.Interop;

namespace CreateInstanceByPInvoke
{
    public class CreateInstanceByPInvokeClass
    {

        //STDAPI CoCreateInstance(
        //  REFCLSID rclsid,
        //  LPUNKNOWN pUnkOuter,
        //  DWORD dwClsContext,
        //  REFIID riid,
        //  LPVOID * ppv
        //);
        [DllImport("ole32.dll", ExactSpelling = true)]
        private static extern int CoCreateInstance(
            [In] ref Guid clsid,
            IntPtr pUnkOuter,
            uint context,
            [In] ref Guid iid,
            [Out] out IntPtr ppv);

        //HRESULT CLSIDFromProgID(
        //  LPCOLESTR lpszProgID,
        //  LPCLSID pclsid
        //);
        [DllImport("ole32.dll", ExactSpelling = true)]
        private static extern int CLSIDFromProgID(
            [MarshalAs(UnmanagedType.LPWStr)] string progid,
            ref Guid clsid);

        public static void DoTest()
        {
            Guid clsid = new Guid();
            int hr = CLSIDFromProgID("SampleCOMSimple.SimpleCOMCalculator.1", ref clsid);
            if (0 == hr) // S_OK
            {
                Guid idispatch_id = new Guid("00020400-0000-0000-C000-000000000046");
                IntPtr pIDispatch;
                hr = CoCreateInstance(
                    ref clsid,
                    IntPtr.Zero,
                    1, // CLSCTX_INPROC_SERVER
                    ref idispatch_id,
                    out pIDispatch);

                if (0 == hr)
                {
                    object obj = Marshal.GetObjectForIUnknown(pIDispatch);
                    if (null != obj)
                    {
                        ISimpleCOMCalculator intf = obj as ISimpleCOMCalculator;
                        int result = intf.Add(1, 2);
                        Console.WriteLine("用PInvoke创建COM对象。计算器：1 + 2 = {1}",
                            obj.GetType().Name, result);
                    }
                }
            }
        }

    }
}
