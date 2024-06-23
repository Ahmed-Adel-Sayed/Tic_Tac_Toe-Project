object Form6: TForm6
  Left = 0
  Top = 0
  Caption = 'Form6'
  ClientHeight = 421
  ClientWidth = 492
  Color = clGradientActiveCaption
  CustomTitleBar.CaptionAlignment = taCenter
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 98
    Top = 27
    Width = 100
    Height = 20
    Caption = 'Game Number:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 98
    Top = 71
    Width = 70
    Height = 20
    Caption = 'Opponent:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 288
    Top = 27
    Width = 79
    Height = 20
    Caption = 'Played with:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 324
    Top = 71
    Width = 43
    Height = 20
    Caption = 'Status:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 233
    Top = 27
    Width = 3
    Height = 15
  end
  object Label6: TLabel
    Left = 400
    Top = 27
    Width = 3
    Height = 15
  end
  object Label7: TLabel
    Left = 201
    Top = 75
    Width = 3
    Height = 15
  end
  object Label8: TLabel
    Left = 379
    Top = 75
    Width = 3
    Height = 15
  end
  object Button1: TButton
    Left = 149
    Top = 125
    Width = 62
    Height = 44
    TabOrder = 0
  end
  object Button2: TButton
    Left = 217
    Top = 125
    Width = 62
    Height = 44
    TabOrder = 1
  end
  object Button3: TButton
    Left = 285
    Top = 125
    Width = 62
    Height = 44
    TabOrder = 2
  end
  object Button4: TButton
    Left = 149
    Top = 175
    Width = 62
    Height = 44
    TabOrder = 3
  end
  object Button5: TButton
    Left = 217
    Top = 175
    Width = 62
    Height = 44
    TabOrder = 4
  end
  object Button6: TButton
    Left = 285
    Top = 175
    Width = 62
    Height = 44
    TabOrder = 5
  end
  object Button7: TButton
    Left = 149
    Top = 225
    Width = 62
    Height = 44
    TabOrder = 6
  end
  object Button8: TButton
    Left = 217
    Top = 225
    Width = 62
    Height = 44
    TabOrder = 7
  end
  object Button9: TButton
    Left = 285
    Top = 225
    Width = 62
    Height = 44
    TabOrder = 8
  end
  object Button10: TButton
    Left = 201
    Top = 360
    Width = 95
    Height = 33
    Caption = 'Show '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = Button10Click
  end
  object ButtonPrevious: TButton
    Left = 103
    Top = 304
    Width = 108
    Height = 25
    Caption = 'Previous Move'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = ButtonPreviousClick
  end
  object ButtonNext: TButton
    Left = 285
    Top = 304
    Width = 109
    Height = 25
    Caption = 'Next Move'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = ButtonNextClick
  end
  object Button11: TButton
    Left = 24
    Top = 381
    Width = 99
    Height = 25
    Caption = 'Back to Home'
    TabOrder = 12
    OnClick = Button11Click
  end
  object EmployeeConnection: TFDConnection
    Params.Strings = (
      'ConnectionDef=EMPLOYEE')
    Connected = True
    LoginPrompt = False
    Left = 37
    Top = 264
  end
  object GameresultsTable: TFDQuery
    Active = True
    Connection = EmployeeConnection
    SQL.Strings = (
      'SELECT * FROM GAMERESULTS')
    Left = 45
    Top = 320
  end
  object UsersTable: TFDQuery
    Active = True
    Connection = EmployeeConnection
    SQL.Strings = (
      'SELECT * FROM USERS')
    Left = 36
    Top = 194
  end
end
