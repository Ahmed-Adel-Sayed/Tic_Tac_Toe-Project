object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 434
  ClientWidth = 516
  Color = clGradientActiveCaption
  CustomTitleBar.CaptionAlignment = taCenter
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clRed
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object currentLabel: TLabel
    Left = 313
    Top = 19
    Width = 85
    Height = 20
    Caption = 'currentLabel:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 126
    Top = 19
    Width = 134
    Height = 20
    Caption = 'It is your turn player:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object WinnerLabel: TLabel
    Left = 139
    Top = 345
    Width = 83
    Height = 20
    Caption = 'WinnerLabel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 139
    Top = 154
    Width = 75
    Height = 55
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = ButtonClick
  end
  object Button2: TButton
    Left = 220
    Top = 154
    Width = 75
    Height = 55
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = ButtonClick
  end
  object Button3: TButton
    Left = 301
    Top = 154
    Width = 75
    Height = 55
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonClick
  end
  object Button4: TButton
    Left = 139
    Top = 215
    Width = 75
    Height = 55
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = ButtonClick
  end
  object Button5: TButton
    Left = 220
    Top = 215
    Width = 75
    Height = 55
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = ButtonClick
  end
  object Button6: TButton
    Left = 301
    Top = 215
    Width = 75
    Height = 55
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = ButtonClick
  end
  object Button7: TButton
    Left = 139
    Top = 276
    Width = 75
    Height = 55
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = ButtonClick
  end
  object Button8: TButton
    Left = 220
    Top = 276
    Width = 75
    Height = 55
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = ButtonClick
  end
  object Button9: TButton
    Left = 301
    Top = 276
    Width = 75
    Height = 53
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = ButtonClick
  end
  object Button10: TButton
    Left = 239
    Top = 384
    Width = 121
    Height = 41
    Caption = 'Save The Game'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 152
    Top = 45
    Width = 46
    Height = 36
    Caption = 'X'
    TabOrder = 10
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 301
    Top = 45
    Width = 49
    Height = 36
    Caption = 'O'
    TabOrder = 11
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 24
    Top = 400
    Width = 89
    Height = 25
    Caption = 'Back to Home'
    TabOrder = 12
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 382
    Top = 384
    Width = 113
    Height = 41
    Caption = 'Show History'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = Button14Click
  end
  object Button15: TButton
    Left = 187
    Top = 95
    Width = 126
    Height = 38
    Caption = 'Play New Game'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
    OnClick = Button15Click
  end
  object EmployeeConnection: TFDConnection
    Params.Strings = (
      'ConnectionDef=EMPLOYEE')
    Connected = True
    LoginPrompt = False
    Left = 44
    Top = 186
  end
  object GameresultsTable: TFDQuery
    Active = True
    Connection = EmployeeConnection
    SQL.Strings = (
      'SELECT * FROM GAMERESULTS')
    Left = 57
    Top = 104
  end
  object UsersTable: TFDQuery
    Active = True
    Connection = EmployeeConnection
    SQL.Strings = (
      'SELECT * FROM USERS')
    Left = 61
    Top = 275
  end
end
