using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace Exception2HRESULT
{

    public class MyHResultException : ApplicationException
    {
        public MyHResultException(string msg)
            : base(msg)
        {
            this.HResult = unchecked((int)0x80051060);
        }
    }

    public interface IExceptions2HResult
    {
        void ThrowCommonException();
        void ThrowMyHResultException();
        void ThrowExceptionForHR(int errorCode);

        [PreserveSig]
        [return: MarshalAs(UnmanagedType.Error)]
        int ReturnHResult(int arg);
    }

    [ClassInterface(ClassInterfaceType.None)]
    public class Exceptions2HResultObj : IExceptions2HResult
    {

        #region IExceptions2HResult Members

        public void ThrowCommonException()
        {
            throw new NotImplementedException("抛出异常：NotImplementedException");
        }

        public void ThrowMyHResultException()
        {
            throw new MyHResultException("抛出异常：MyHResultException");
        }

        public void ThrowExceptionForHR(int errorCode)
        {
            Marshal.ThrowExceptionForHR(errorCode);
        }

        public int ReturnHResult(int arg)
        {
            if (arg < 0)
            {
                // 返回S_FALSE
                return 1;
            }

            // 返回S_OK
            return 0;
        }

        #endregion
    }
}
