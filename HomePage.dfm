object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 395
  ClientWidth = 567
  Color = clGradientActiveCaption
  CustomTitleBar.CaptionAlignment = taCenter
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 136
    Top = 40
    Width = 274
    Height = 35
    Caption = 'Welcome_To_Tic_Tac_Toe'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object player: TButton
    Left = 208
    Top = 128
    Width = 137
    Height = 42
    Caption = 'Player VS Player'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = playerClick
  end
  object AI: TButton
    Left = 208
    Top = 216
    Width = 137
    Height = 42
    Caption = 'Player VS AI'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = AIClick
  end
  object history: TButton
    Left = 208
    Top = 304
    Width = 137
    Height = 42
    Caption = 'Game History'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = historyClick
  end
  object exit: TButton
    Left = 56
    Top = 304
    Width = 75
    Height = 33
    Caption = 'Exit'
    TabOrder = 3
    OnClick = exitClick
  end
  object EmployeeConnection: TFDConnection
    Params.Strings = (
      'ConnectionDef=EMPLOYEE')
    Connected = True
    LoginPrompt = False
    Left = 437
    Top = 261
  end
  object UsersTable: TFDQuery
    Connection = EmployeeConnection
    SQL.Strings = (
      'SELECT * FROM USERS')
    Left = 439
    Top = 159
  end
  object GameresultsTable: TFDQuery
    Connection = EmployeeConnection
    SQL.Strings = (
      'SELECT * FROM GAMERESULTS')
    Left = 95
    Top = 141
  end
end
