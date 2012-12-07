using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.ComponentModel;

namespace PInvokeBestPractice
{
    /// <summary>
    /// 使用C#中的枚举来声明宏定义
    /// </summary>
    enum BeepTypes
    {
        MB_SIMPLE = -1,                                               // Simple beep.
        MB_OK = 0x00000000,                                     // SystemDefault
        MB_ICONHAND = 0x00000010,                     // SystemHand
        MB_ICONQUESTION = 0x00000020,            // SystemQuestion
        MB_ICONEXCLAMATION = 0x00000030,   // SystemExclamation
        MB_ICONASTERISK = 0x00000040              // SystemAsterisk
    }

    /// <summary>
    /// 将非托管方法封装到一个静态包装类中
    /// </summary>
    static class NativeSound
    {
        /// <summary>
        /// 这是对Win32 API函数MessageBeep的一个包装方法
        /// </summary>
        /// <param name="type"></param>
        public static void MessageBeep(BeepTypes type)
        {
            if (!Enum.IsDefined(typeof(BeepTypes), type))
            {
                throw new ArgumentException("BeepType can not be recognized!");
            }

            if (!MessageBeep((UInt32)type))
            {
                // 如果失败，获得最后的错误码，
                // 并抛出相应的Win32异常
                Int32 err = Marshal.GetLastWin32Error();
                throw new Win32Exception(err);
            }
        }

        // 将非托管函数的托管定义声明为一个私有方法
        [DllImport("User32.dll", SetLastError = true)]
        private static extern Boolean MessageBeep(UInt32 beepType);

    }
   
}
