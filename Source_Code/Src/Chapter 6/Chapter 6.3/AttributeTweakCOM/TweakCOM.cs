using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace AttributeTweakCOM
{
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    [Guid("8C391F9B-B859-498e-A849-894C60C58B79")]
    public interface ITweakCOM
    {
        void ExposedMethod();

        [ComVisible(false)]
        void PrivateMethod();

        int DemoProperty
        {
            get;

            [ComVisible(false)]
            set;
        }

    }


    [ClassInterface(ClassInterfaceType.None)]
    [Guid("254F8086-41EA-4f13-99CD-3DD278D978CD")]
    [ProgId("TweakCOMObj.CustomizedProgId")]
    public class TweakCOMObj : ITweakCOM
    {
        private int _intValue;

        #region ITweakCOM Members

        public void ExposedMethod()
        {
        }

        public void PrivateMethod()
        {
        }

        public int DemoProperty
        {
            get
            {
                return _intValue;
            }
            set
            {
                _intValue = value;
            }
        }

        #endregion
    }
}
