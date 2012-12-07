VERSION 5.00
Begin VB.Form MainForm 
   Caption         =   "COMClientVBCollection - Demo"
   ClientHeight    =   3240
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4695
   LinkTopic       =   "Form1"
   ScaleHeight     =   3240
   ScaleWidth      =   4695
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox txt_Result 
      Height          =   3015
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
    Dim comCollectionObj As New MarshalCollection.MarshalCollectionObj
    Dim value As New MarshalCollection.DemoItemObj
    value.IntValue = 1
    value.StringValue = "黄际洲"
    comCollectionObj.Add value
    
    Dim value2 As New MarshalCollection.DemoItemObj
    value2.IntValue = 2
    value2.StringValue = "崔晓源"
    comCollectionObj.Add value2
    
    For Each value In comCollectionObj
      txt_Result.Text = txt_Result.Text + "作者" + CStr(value.IntValue) + _
      " 姓名：" + value.StringValue + vbCrLf
    Next
End Sub

