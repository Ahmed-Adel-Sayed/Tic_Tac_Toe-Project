object Form5: TForm5
  Left = 0
  Top = 0
  Caption = 'Form5'
  ClientHeight = 429
  ClientWidth = 523
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 212
    Top = 24
    Width = 111
    Height = 25
    Caption = 'It is your turn '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object WinnerLabel: TLabel
    Left = 144
    Top = 336
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
    Left = 144
    Top = 144
    Width = 75
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object Button2: TButton
    Left = 225
    Top = 144
    Width = 75
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object Button3: TButton
    Left = 306
    Top = 144
    Width = 75
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object Button4: TButton
    Left = 144
    Top = 200
    Width = 75
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object Button5: TButton
    Left = 225
    Top = 200
    Width = 75
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object Button6: TButton
    Left = 306
    Top = 200
    Width = 75
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object Button7: TButton
    Left = 144
    Top = 256
    Width = 75
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object Button8: TButton
    Left = 225
    Top = 256
    Width = 75
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
  object Button9: TButton
    Left = 306
    Top = 256
    Width = 75
    Height = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
  end
  object Button10: TButton
    Left = 272
    Top = 376
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
  object Button13: TButton
    Left = 32
    Top = 392
    Width = 89
    Height = 25
    Caption = 'Back to Home'
    TabOrder = 10
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 408
    Top = 376
    Width = 105
    Height = 41
    Caption = 'Show History'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = Button14Click
  end
  object Button15: TButton
    Left = 200
    Top = 88
    Width = 123
    Height = 41
    Caption = 'Play New Game'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    OnClick = Button15Click
  end
  object Button11: TButton
    Left = 306
    Top = 55
    Width = 127
    Height = 25
    Caption = 'Human Start Play X'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 88
    Top = 55
    Width = 131
    Height = 25
    Caption = 'Human Start Play O'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
    OnClick = Button12Click
  end
  object Button16: TButton
    Left = 88
    Top = 93
    Width = 83
    Height = 33
    Caption = 'AI Start Play O'
    TabOrder = 15
    OnClick = Button16Click
  end
  object Button17: TButton
    Left = 368
    Top = 93
    Width = 83
    Height = 33
    Caption = 'AI Start Play X'
    TabOrder = 16
    OnClick = Button17Click
  end
  object EmployeeConnection: TFDConnection
    Params.Strings = (
      'ConnectionDef=EMPLOYEE')
    LoginPrompt = False
    Left = 45
    Top = 142
  end
  object UsersTable: TFDQuery
    Connection = EmployeeConnection
    SQL.Strings = (
      'SELECT * FROM USERS')
    Left = 53
    Top = 198
  end
  object GameresultsTable: TFDQuery
    Connection = EmployeeConnection
    SQL.Strings = (
      'SELECT * FROM GAMERESULTS')
    Left = 59
    Top = 267
  end
end
