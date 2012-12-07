VERSION 5.00
Begin VB.Form MainForm 
   Caption         =   "COMClientVBEvent - Demo"
   ClientHeight    =   2565
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4740
   LinkTopic       =   "Form1"
   ScaleHeight     =   2565
   ScaleWidth      =   4740
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox txt_Result 
      Height          =   2175
      Left            =   240
      MultiLine       =   -1  'True
      TabIndex        =   0
      Top             =   240
      Width           =   4335
   End
End
Attribute VB_Name = "MainForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public WithEvents comObj As MarshalEvent.StockPriceControlObj
Attribute comObj.VB_VarHelpID = -1

'事件处理函数
Private Sub comObj_OnPriceChanged( _
        ByVal newPrice As Double, ByVal oldPrice As Double)
     txt_Result.Text = txt_Result.Text + "新股价： " + _
        CStr(newPrice) + "  前一交易日股价： " + _
        CStr(oldPrice) + vbCrLf
End Sub

Private Sub Form_Load()
    '创建COM对象实例
    Set comObj = New MarshalEvent.StockPriceControlObj
    
    '触发事件
    comObj.ChangeStockPrice (18)
    comObj.ChangeStockPrice (38)
    comObj.ChangeStockPrice (28)
    comObj.ChangeStockPrice (58)
    
    
    '释放COM对象
    Set comObj = Nothing
End Sub


