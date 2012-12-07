VERSION 5.00
Begin VB.Form MainForm 
   Caption         =   "COMClientVBOptionalParam - Demo"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox txt_Result 
      Height          =   2895
      Left            =   120
      MultiLine       =   -1  'True
      TabIndex        =   0
      Top             =   120
      Width           =   4455
   End
End
Attribute VB_Name = "MainForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private Sub Form_Load()
    Call TestOptionalParam
End Sub

Private Sub TestOptionalParam()

    ' 创建COM对象
    Dim comObj As New MarshalOptionalParam.MarshalOptionalObj
        
    '调用可选参数方法, 第二参数默认值为10
    txt_Result.Text = "(第二参数默认值为10)" + vbCrLf
    
    Dim result As Integer
    result = comObj.AddIntegerOptional(1)
    txt_Result.Text = txt_Result.Text + _
        "一个参数结果： " + CStr(result) + vbCrLf
    
    result = comObj.AddIntegerOptional(1, 2)
    txt_Result.Text = txt_Result.Text + _
        "两个参数结果： " + CStr(result) + vbCrLf
    
    ' 释放COM对象
    Set comObj = Nothing
End Sub


