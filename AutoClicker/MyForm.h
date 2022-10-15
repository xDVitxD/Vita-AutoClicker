#pragma once
#include "CustomSelection.h"
#include "CustomNumericUpDown.h"
#include <Windows.h>
#pragma comment(lib,"user32.lib")
#include <winuser.rh>
#define KEYEVENTF_KEYDOWN 0
#ifdef _WIN32
#include <io.h> 
#define access    _access_s
#else
#include <unistd.h>
#endif


int CurrentScreen = 0;
bool SelectionsAdded = false;
bool WaitingNewKey = false;
bool WaitingNewKeyButton = false;
bool NewKeyButtonIsKeyboard = false;
bool ChangingMousePosition = false;
bool ChangingEventsPositions = false;
HCURSOR OldSytemCursor;
int NewKey;
int NewKeyButton;
bool AlgorithmLaunched = false;

//For settings
bool Settings_TopMost = true;
bool Settings_Hide = true;
char Settings_Type = 'S';
int Settings_LaunchHotKey = 115;

//For algorithm event//

struct AlgorithmEvent {
	char Type;
	char SubType;
	DWORD KeyOrButton;
	long long Microsecond;
	System::Drawing::Point Position;
};
/*
Types:
Mouse: M
Pause: P
Keyboard: K
-----------
SubTypes:
Click: C
Hold: H
UnHold:U
Move: M
Wait: W
Press: P
*/

int SelectedAlgorithmIndex = -1;
int RadiusOfAlgorithmSphere = 13;
int AlgorithmStartOffset = 3;
int AlgorithmMiddleOffset = 7;
int AlgorithmScrolledX = 0;
struct AlgorithmEvent Algorithm[9999] = {'M','P',VK_LBUTTON,0,System::Drawing::Point(0,0)};
int MouseEvents[5][2] = {};

namespace AutoClicker {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			ChangeCursorToClientStandart();
		}
	private: System::Windows::Forms::Button^ Button1;
	private: System::Windows::Forms::Button^ Button2;
	private: System::Windows::Forms::Button^ Button3;



	private: System::Windows::Forms::Button^ Settings;
	private: System::Windows::Forms::Label^ Version;
	private: System::Windows::Forms::Button^ Back;
	private: System::Windows::Forms::Label^ Label1;
	private: System::Windows::Forms::Label^ AddEventLabel;
	protected:

	private: System::Windows::Forms::Button^ AddEventMouse;
	private: System::Windows::Forms::Button^ AddEventPause;
	private: System::Windows::Forms::Button^ AddEventKeyboard;
	private: System::Windows::Forms::Label^ TypeEventLabel;
	private: System::Windows::Forms::Label^ SubTypeEventLabel;



	private: System::Windows::Forms::Label^ EventsContainer;
	private: System::Windows::Forms::Label^ EventsContainerMiddleLine;
	private: System::Windows::Forms::Label^ KeyToPressLabel;
	private: System::Windows::Forms::Button^ KeyToPress;
	private: System::Windows::Forms::Button^ MoveEventSphere;
	private: System::Windows::Forms::Button^ DeleteEventSphere;
	private: System::Windows::Forms::Label^ PressKeyLabel;
	private: System::Windows::Forms::Label^ PauseWaitLabel;
	private: System::Windows::Forms::Label^ MousePositionLabel;
	private: System::Windows::Forms::Button^ ChangePositionButton;



	private: System::Windows::Forms::Label^ PauseWaitUpDown;
	private: System::Windows::Forms::TextBox^ PauseWaitUpDownTextBox;
	private: System::Windows::Forms::Label^ MousePositionXUpDown;
	private: System::Windows::Forms::Label^ MousePositionYUpDown;
	private: System::Windows::Forms::TextBox^ MousePositionXTextBox;
	private: System::Windows::Forms::TextBox^ MousePositionYTextBox;
	private: System::Windows::Forms::Button^ TypeSelectionMain;
	private: System::Windows::Forms::Button^ SubTypeSelectionMain;
	private: System::Windows::Forms::Label^ TypeSelectionSetItems;
	private: System::Windows::Forms::Label^ SubTypeSelectionSetItems;




	protected:

	protected:

	protected:

	protected:
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Button1 = (gcnew System::Windows::Forms::Button());
			this->Button2 = (gcnew System::Windows::Forms::Button());
			this->Version = (gcnew System::Windows::Forms::Label());
			this->Button3 = (gcnew System::Windows::Forms::Button());
			this->Label1 = (gcnew System::Windows::Forms::Label());
			this->AddEventMouse = (gcnew System::Windows::Forms::Button());
			this->AddEventPause = (gcnew System::Windows::Forms::Button());
			this->AddEventKeyboard = (gcnew System::Windows::Forms::Button());
			this->AddEventLabel = (gcnew System::Windows::Forms::Label());
			this->TypeEventLabel = (gcnew System::Windows::Forms::Label());
			this->SubTypeEventLabel = (gcnew System::Windows::Forms::Label());
			this->EventsContainer = (gcnew System::Windows::Forms::Label());
			this->KeyToPressLabel = (gcnew System::Windows::Forms::Label());
			this->KeyToPress = (gcnew System::Windows::Forms::Button());
			this->MoveEventSphere = (gcnew System::Windows::Forms::Button());
			this->DeleteEventSphere = (gcnew System::Windows::Forms::Button());
			this->PressKeyLabel = (gcnew System::Windows::Forms::Label());
			this->PauseWaitLabel = (gcnew System::Windows::Forms::Label());
			this->MousePositionLabel = (gcnew System::Windows::Forms::Label());
			this->ChangePositionButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Button1
			// 
			this->Button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Button1->FlatAppearance->BorderSize = 0;
			this->Button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold));
			this->Button1->ForeColor = System::Drawing::Color::White;
			this->Button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button1->Location = System::Drawing::Point(5, 5);
			this->Button1->Name = L"Button1";
			this->Button1->Size = System::Drawing::Size(219, 35);
			this->Button1->TabIndex = 0;
			this->Button1->Text = L"Нажмите N для запуска";
			this->Button1->UseVisualStyleBackColor = true;
			this->Button1->Click += gcnew System::EventHandler(this, &MyForm::PressedButton);
			this->Button1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::OnPaint);
			// 
			// Button2
			// 
			this->Button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Button2->FlatAppearance->BorderSize = 0;
			this->Button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold));
			this->Button2->ForeColor = System::Drawing::Color::White;
			this->Button2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button2->Location = System::Drawing::Point(5, 46);
			this->Button2->Name = L"Button2";
			this->Button2->Size = System::Drawing::Size(219, 34);
			this->Button2->TabIndex = 1;
			this->Button2->TabStop = false;
			this->Button2->Text = L"Изменить настройки";
			this->Button2->UseVisualStyleBackColor = true;
			this->Button2->Click += gcnew System::EventHandler(this, &MyForm::PressedButton);
			this->Button2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::OnPaint);
			// 
			// Version
			// 
			this->Version->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->Version->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(73)));
			this->Version->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Version->Location = System::Drawing::Point(0, 102);
			this->Version->Name = L"Version";
			this->Version->Size = System::Drawing::Size(227, 18);
			this->Version->TabIndex = 2;
			this->Version->Text = L"v0.01";
			this->Version->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// Button3
			// 
			this->Button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Button3->FlatAppearance->BorderSize = 0;
			this->Button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold));
			this->Button3->ForeColor = System::Drawing::Color::White;
			this->Button3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Button3->Location = System::Drawing::Point(5, 86);
			this->Button3->Name = L"Button3";
			this->Button3->Size = System::Drawing::Size(219, 34);
			this->Button3->TabIndex = 3;
			this->Button3->Text = L"❮ Назад";
			this->Button3->UseVisualStyleBackColor = true;
			this->Button3->Visible = false;
			this->Button3->Click += gcnew System::EventHandler(this, &MyForm::PressedButton);
			this->Button3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::OnPaint);
			// 
			// Label1
			// 
			this->Label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->Label1->ForeColor = System::Drawing::Color::White;
			this->Label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Label1->Location = System::Drawing::Point(6, 6);
			this->Label1->Name = L"Label1";
			this->Label1->Size = System::Drawing::Size(215, 33);
			this->Label1->TabIndex = 0;
			this->Label1->Text = L"Нажмите клавишу";
			this->Label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AddEventMouse
			// 
			this->AddEventMouse->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->AddEventMouse->FlatAppearance->BorderSize = 0;
			this->AddEventMouse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddEventMouse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold));
			this->AddEventMouse->ForeColor = System::Drawing::Color::White;
			this->AddEventMouse->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->AddEventMouse->Location = System::Drawing::Point(5, 46);
			this->AddEventMouse->Name = L"AddEventMouse";
			this->AddEventMouse->Size = System::Drawing::Size(137, 34);
			this->AddEventMouse->TabIndex = 3;
			this->AddEventMouse->Text = L"Мышь";
			this->AddEventMouse->UseVisualStyleBackColor = true;
			this->AddEventMouse->Visible = false;
			this->AddEventMouse->Click += gcnew System::EventHandler(this, &MyForm::FunctionAddEventMouse);
			this->AddEventMouse->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::OnPaint);
			// 
			// AddEventPause
			// 
			this->AddEventPause->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->AddEventPause->FlatAppearance->BorderSize = 0;
			this->AddEventPause->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddEventPause->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold));
			this->AddEventPause->ForeColor = System::Drawing::Color::White;
			this->AddEventPause->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->AddEventPause->Location = System::Drawing::Point(148, 46);
			this->AddEventPause->Name = L"AddEventPause";
			this->AddEventPause->Size = System::Drawing::Size(138, 34);
			this->AddEventPause->TabIndex = 4;
			this->AddEventPause->Text = L"Пауза";
			this->AddEventPause->UseVisualStyleBackColor = true;
			this->AddEventPause->Visible = false;
			this->AddEventPause->Click += gcnew System::EventHandler(this, &MyForm::FunctionAddEventPause);
			this->AddEventPause->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::OnPaint);
			// 
			// AddEventKeyboard
			// 
			this->AddEventKeyboard->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->AddEventKeyboard->FlatAppearance->BorderSize = 0;
			this->AddEventKeyboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddEventKeyboard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold));
			this->AddEventKeyboard->ForeColor = System::Drawing::Color::White;
			this->AddEventKeyboard->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->AddEventKeyboard->Location = System::Drawing::Point(292, 46);
			this->AddEventKeyboard->Name = L"AddEventKeyboard";
			this->AddEventKeyboard->Size = System::Drawing::Size(137, 34);
			this->AddEventKeyboard->TabIndex = 5;
			this->AddEventKeyboard->Text = L"Клавиатура";
			this->AddEventKeyboard->UseVisualStyleBackColor = true;
			this->AddEventKeyboard->Visible = false;
			this->AddEventKeyboard->Click += gcnew System::EventHandler(this, &MyForm::FunctionAddEventKeyboard);
			this->AddEventKeyboard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::OnPaint);
			// 
			// AddEventLabel
			// 
			this->AddEventLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->AddEventLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddEventLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->AddEventLabel->ForeColor = System::Drawing::Color::White;
			this->AddEventLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->AddEventLabel->Location = System::Drawing::Point(0, 6);
			this->AddEventLabel->Name = L"AddEventLabel";
			this->AddEventLabel->Size = System::Drawing::Size(434, 33);
			this->AddEventLabel->TabIndex = 0;
			this->AddEventLabel->Text = L"Добавление нового события";
			this->AddEventLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->AddEventLabel->Visible = false;
			// 
			// TypeEventLabel
			// 
			this->TypeEventLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->TypeEventLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->TypeEventLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->TypeEventLabel->ForeColor = System::Drawing::Color::White;
			this->TypeEventLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->TypeEventLabel->Location = System::Drawing::Point(0, 87);
			this->TypeEventLabel->Name = L"TypeEventLabel";
			this->TypeEventLabel->Size = System::Drawing::Size(217, 33);
			this->TypeEventLabel->TabIndex = 6;
			this->TypeEventLabel->Text = L"Тип события";
			this->TypeEventLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->TypeEventLabel->Visible = false;
			// 
			// SubTypeEventLabel
			// 
			this->SubTypeEventLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->SubTypeEventLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SubTypeEventLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->SubTypeEventLabel->ForeColor = System::Drawing::Color::White;
			this->SubTypeEventLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->SubTypeEventLabel->Location = System::Drawing::Point(217, 87);
			this->SubTypeEventLabel->Name = L"SubTypeEventLabel";
			this->SubTypeEventLabel->Size = System::Drawing::Size(217, 33);
			this->SubTypeEventLabel->TabIndex = 7;
			this->SubTypeEventLabel->Text = L"Подтип события";
			this->SubTypeEventLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->SubTypeEventLabel->Visible = false;
			// 
			// EventsContainer
			// 
			this->EventsContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(93)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->EventsContainer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->EventsContainer->ForeColor = System::Drawing::Color::Transparent;
			this->EventsContainer->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->EventsContainer->Location = System::Drawing::Point(4, 248);
			this->EventsContainer->Name = L"EventsContainer";
			this->EventsContainer->Size = System::Drawing::Size(426, 77);
			this->EventsContainer->TabIndex = 8;
			this->EventsContainer->Visible = false;
			this->EventsContainer->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::EventsContainerOnPaint);
			this->EventsContainer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::EventsContainerOnClick);
			this->EventsContainer->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseWheel);
			// 
			// KeyToPressLabel
			// 
			this->KeyToPressLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->KeyToPressLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->KeyToPressLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->KeyToPressLabel->ForeColor = System::Drawing::Color::White;
			this->KeyToPressLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->KeyToPressLabel->Location = System::Drawing::Point(5, 168);
			this->KeyToPressLabel->Name = L"KeyToPressLabel";
			this->KeyToPressLabel->Size = System::Drawing::Size(209, 33);
			this->KeyToPressLabel->TabIndex = 8;
			this->KeyToPressLabel->Text = L"Клавиша для нажатия:";
			this->KeyToPressLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->KeyToPressLabel->Visible = false;
			// 
			// KeyToPress
			// 
			this->KeyToPress->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->KeyToPress->FlatAppearance->BorderSize = 0;
			this->KeyToPress->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->KeyToPress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold));
			this->KeyToPress->ForeColor = System::Drawing::Color::White;
			this->KeyToPress->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->KeyToPress->Location = System::Drawing::Point(220, 168);
			this->KeyToPress->Name = L"KeyToPress";
			this->KeyToPress->Size = System::Drawing::Size(211, 35);
			this->KeyToPress->TabIndex = 10;
			this->KeyToPress->Text = L"NULL";
			this->KeyToPress->UseVisualStyleBackColor = true;
			this->KeyToPress->Visible = false;
			this->KeyToPress->Click += gcnew System::EventHandler(this, &MyForm::ChangeKeyButton);
			this->KeyToPress->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::OnPaint);
			// 
			// MoveEventSphere
			// 
			this->MoveEventSphere->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->MoveEventSphere->FlatAppearance->BorderSize = 0;
			this->MoveEventSphere->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MoveEventSphere->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold));
			this->MoveEventSphere->ForeColor = System::Drawing::Color::White;
			this->MoveEventSphere->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->MoveEventSphere->Location = System::Drawing::Point(5, 209);
			this->MoveEventSphere->Name = L"MoveEventSphere";
			this->MoveEventSphere->Size = System::Drawing::Size(209, 34);
			this->MoveEventSphere->TabIndex = 11;
			this->MoveEventSphere->Text = L"Переместить";
			this->MoveEventSphere->UseVisualStyleBackColor = true;
			this->MoveEventSphere->Visible = false;
			this->MoveEventSphere->Click += gcnew System::EventHandler(this, &MyForm::FuncMoveEventSphere);
			this->MoveEventSphere->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::OnPaint);
			// 
			// DeleteEventSphere
			// 
			this->DeleteEventSphere->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->DeleteEventSphere->FlatAppearance->BorderSize = 0;
			this->DeleteEventSphere->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DeleteEventSphere->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold));
			this->DeleteEventSphere->ForeColor = System::Drawing::Color::White;
			this->DeleteEventSphere->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->DeleteEventSphere->Location = System::Drawing::Point(220, 209);
			this->DeleteEventSphere->Name = L"DeleteEventSphere";
			this->DeleteEventSphere->Size = System::Drawing::Size(209, 34);
			this->DeleteEventSphere->TabIndex = 12;
			this->DeleteEventSphere->Text = L"Удалить";
			this->DeleteEventSphere->UseVisualStyleBackColor = true;
			this->DeleteEventSphere->Visible = false;
			this->DeleteEventSphere->Click += gcnew System::EventHandler(this, &MyForm::FuncDeleteEventSphere);
			this->DeleteEventSphere->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::OnPaint);
			// 
			// PressKeyLabel
			// 
			this->PressKeyLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->PressKeyLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PressKeyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->PressKeyLabel->ForeColor = System::Drawing::Color::White;
			this->PressKeyLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->PressKeyLabel->Location = System::Drawing::Point(220, 168);
			this->PressKeyLabel->Name = L"PressKeyLabel";
			this->PressKeyLabel->Size = System::Drawing::Size(211, 35);
			this->PressKeyLabel->TabIndex = 13;
			this->PressKeyLabel->Text = L"Нажмите клавишу";
			this->PressKeyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->PressKeyLabel->Visible = false;
			// 
			// PauseWaitLabel
			// 
			this->PauseWaitLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->PauseWaitLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PauseWaitLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->PauseWaitLabel->ForeColor = System::Drawing::Color::White;
			this->PauseWaitLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->PauseWaitLabel->Location = System::Drawing::Point(5, 168);
			this->PauseWaitLabel->Name = L"PauseWaitLabel";
			this->PauseWaitLabel->Size = System::Drawing::Size(217, 33);
			this->PauseWaitLabel->TabIndex = 14;
			this->PauseWaitLabel->Text = L"Время ожидания (мкс)";
			this->PauseWaitLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MousePositionLabel
			// 
			this->MousePositionLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->MousePositionLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MousePositionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->MousePositionLabel->ForeColor = System::Drawing::Color::White;
			this->MousePositionLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->MousePositionLabel->Location = System::Drawing::Point(5, 168);
			this->MousePositionLabel->Name = L"MousePositionLabel";
			this->MousePositionLabel->Size = System::Drawing::Size(137, 33);
			this->MousePositionLabel->TabIndex = 15;
			this->MousePositionLabel->Text = L"Позиция (X:Y):";
			this->MousePositionLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ChangePositionButton
			// 
			this->ChangePositionButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ChangePositionButton->FlatAppearance->BorderSize = 0;
			this->ChangePositionButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ChangePositionButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold));
			this->ChangePositionButton->ForeColor = System::Drawing::Color::White;
			this->ChangePositionButton->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ChangePositionButton->Location = System::Drawing::Point(292, 168);
			this->ChangePositionButton->Name = L"ChangePositionButton";
			this->ChangePositionButton->Size = System::Drawing::Size(137, 35);
			this->ChangePositionButton->TabIndex = 16;
			this->ChangePositionButton->UseVisualStyleBackColor = true;
			this->ChangePositionButton->Click += gcnew System::EventHandler(this, &MyForm::ChangeMousePosition);
			this->ChangePositionButton->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::OnPaint);
			this->ChangePositionButton->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::OnPaintChangePositionButton);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->SizeChanged += gcnew System::EventHandler(this, &MyForm::OnSizeChanged);
			this->ClientSize = System::Drawing::Size(227, 126);
			this->Controls->Add(this->Button1);
			this->Controls->Add(this->Label1);
			this->Controls->Add(this->Button2);
			this->Controls->Add(this->Button3);
			this->Controls->Add(this->Version);
			this->Controls->Add(this->ChangePositionButton);
			this->Controls->Add(this->MousePositionLabel);
			this->Controls->Add(this->PauseWaitLabel);
			this->Controls->Add(this->DeleteEventSphere);
			this->Controls->Add(this->MoveEventSphere);
			this->Controls->Add(this->KeyToPress);
			this->Controls->Add(this->KeyToPressLabel);
			this->Controls->Add(this->SubTypeEventLabel);
			this->Controls->Add(this->TypeEventLabel);
			this->Controls->Add(this->AddEventLabel);
			this->Controls->Add(this->AddEventKeyboard);
			this->Controls->Add(this->AddEventPause);
			this->Controls->Add(this->AddEventMouse);
			this->Controls->Add(this->EventsContainer);
			this->Controls->Add(this->PressKeyLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"Icon")));
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Auto Clicker";
			this->Load += gcnew System::EventHandler(this, &MyForm::OnLoad);
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::OnKeyDown);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	System::Void OnPaintChangePositionButton(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		e->Graphics->DrawImage((cli::safe_cast<System::Drawing::Image^>(resources->GetObject("DCursor"))), 59, 8, 20, 20);
	}
	template < class T, class U >
	Boolean isinst(U u) {
		return dynamic_cast<T>(u) != nullptr;
	}
	System::Void ResizeButtons123() {
		System::String^ Formatted = System::String::Format("Нажмите {0} для запуска", ((System::Windows::Forms::Keys)Settings_LaunchHotKey).ToString());
		auto CSize = System::Windows::Forms::TextRenderer::MeasureText(Formatted, this->Button1->Font);
		this->Button1->Size = System::Drawing::Size(CSize.Width + 22, Button1->Size.Height);
		this->Label1->Size = System::Drawing::Size(CSize.Width + 22, Label1->Size.Height);
		this->Button2->Size = System::Drawing::Size(CSize.Width + 22, Button2->Size.Height);
		this->Button3->Size = System::Drawing::Size(CSize.Width + 22, Button3->Size.Height);
		this->Version->Size = System::Drawing::Size(CSize.Width + 32, Version->Height);
		this->ClientSize = System::Drawing::Size(CSize.Width + 32, 126);
		this->Button1->Text = Formatted;
	}
	System::Void WaitNewKey(System::Object^ Thread) {
		WaitingNewKey = true;
		while (true) {
			if (!WaitingNewKey) {
				Settings_LaunchHotKey = NewKey;
				ResizeButtons123();
				ChangeScreen(0);
				break;
			}
			FunctionWait(1000);
		}
		delete(Thread);
	}
	System::Void ChangeScreen(int ScreenIndex) {
		if (ScreenIndex == -1) {
			System::Threading::Thread^ WaitingNewKeyThread = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &MyForm::WaitNewKey));
			WaitingNewKeyThread->IsBackground = true;
			WaitingNewKeyThread->Start(WaitingNewKeyThread);
		}else if (ScreenIndex == 0) {
			this->Button1->Text = System::String::Format("Нажмите {0} для запуска", ((System::Windows::Forms::Keys)Settings_LaunchHotKey).ToString());
			this->Button2->Text = "Изменить настройки";
		}else if (ScreenIndex == 1) {
			this->Button1->Text = "Алгоритм";
			this->Button2->Text = "Выполнение";
		}else if (ScreenIndex == 3) {
			if (Settings_Hide) {
				this->Button1->Text = "Скрыть при запуске:Вкл.";
			} else {
				this->Button1->Text = "Скрыть при запуске:Выкл.";
			}
			if (Settings_Type == 'S') {
				this->Button2->Text = "Тип запуска:Переключить";
			} else if (Settings_Type == 'H') {
				this->Button2->Text = "Тип запуска:Зажать";
			}
		}
		CurrentScreen = ScreenIndex;
		this->Button1->Visible = (CurrentScreen == 0 || CurrentScreen == 1 || CurrentScreen == 3);
		this->Label1->Visible = (CurrentScreen == -1);
		this->Button2->Visible = (CurrentScreen == -1 || CurrentScreen == 0 || CurrentScreen == 1 || CurrentScreen == 3);
		this->Button3->Visible = (CurrentScreen == 1 || CurrentScreen == 2 || CurrentScreen == 3);
		this->Version->Visible = (CurrentScreen == -1 || CurrentScreen == 0);
		this->SubTypeEventLabel->Visible = (CurrentScreen == 2);
		this->TypeEventLabel->Visible = (CurrentScreen == 2);
		this->AddEventLabel->Visible = (CurrentScreen == 2);
		this->AddEventKeyboard->Visible = (CurrentScreen == 2);
		this->AddEventPause->Visible = (CurrentScreen == 2);
		this->AddEventMouse->Visible = (CurrentScreen == 2);
		this->EventsContainer->Visible = (CurrentScreen == 2);
		this->Button3->Size = System::Drawing::Size(this->ClientSize.Width-10,35);
		this->Button3->Location = System::Drawing::Point(5, this->ClientSize.Height - 40);
		this->Refresh();
	}
	System::Void OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (WaitingNewKey) {
			NewKey = e->KeyValue;
			WaitingNewKey = false;
		}
		if (WaitingNewKeyButton && NewKeyButtonIsKeyboard) {
			NewKeyButton = e->KeyValue;
			WaitingNewKeyButton = false;
		}
		if (e->KeyCode == System::Windows::Forms::Keys::Escape) {
			PressedButton(this->Button3,gcnew System::Windows::Forms::MouseEventArgs(System::Windows::Forms::MouseButtons::Left, 1, 0, 0, 0));
		}
	}
	System::Void OnMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (WaitingNewKeyButton && !NewKeyButtonIsKeyboard) {
			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				NewKeyButton = 1;
			}else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
				NewKeyButton = 2;
			}else if (e->Button == System::Windows::Forms::MouseButtons::Middle) {
				NewKeyButton = 4;
			}else if (e->Button == System::Windows::Forms::MouseButtons::XButton1) {
				NewKeyButton = 5;
			}else if (e->Button == System::Windows::Forms::MouseButtons::XButton2) {
				NewKeyButton = 6;
			}
			WaitingNewKeyButton = false;
		}
	}
	System::Void ScrollEventsContainer(int ScrollOffset) {
		int Length = 0;
		for (int Index = 0; Index < std::size(Algorithm); Index++) {
			if (Algorithm[Index].Type > 0) {
				Length += 1;
			}else {
				break;
			}
		}
		int Min, Max;
		Min = ((AlgorithmMiddleOffset + RadiusOfAlgorithmSphere * 2) * Length + AlgorithmStartOffset);
		Max = 0;
		if (Min > this->EventsContainer->Size.Width) {
			Min = -(Min - this->EventsContainer->Size.Width);
			if (AlgorithmScrolledX + ScrollOffset < Min) {
				AlgorithmScrolledX = Min;
			}else if (AlgorithmScrolledX + ScrollOffset > Max) {
				AlgorithmScrolledX = Max;
			}else {
				AlgorithmScrolledX += ScrollOffset;
			}
		}else {
			AlgorithmScrolledX = Max;
		}
		this->EventsContainer->Refresh();
	}
	System::Void OnMouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		ScrollEventsContainer(e->Delta);
	}
	System::Void PressedButton(System::Object^ sender, System::EventArgs^ e) {
		if (isinst< System::Windows::Forms::MouseEventArgs^ >(e) || isinst< System::Windows::Forms::KeyPressEventArgs^ >(e)) {
			System::Windows::Forms::Button^ SenderButton = (System::Windows::Forms::Button^)sender;
			if (CurrentScreen == 0) {
				if (SenderButton == this->Button1) {
					ChangeScreen(-1);
				}if (SenderButton == this->Button2) {
					ChangeScreen(1);
				}
			}else if (CurrentScreen == 1) {
				if (SenderButton == this->Button1) {
					System::Drawing::Point Pos = this->Location;
					auto CSize = System::Windows::Forms::TextRenderer::MeasureText(System::String::Format("Нажмите {0} для запуска", ((System::Windows::Forms::Keys)Settings_LaunchHotKey).ToString()), this->Button1->Font);
					this->ClientSize = System::Drawing::Size(434, 370);
					this->Location = System::Drawing::Point(this->Location.X - (434 - CSize.Width + 32) / 2, this->Location.Y - 102);
					ChangeScreen(2);
				}else if(SenderButton == this->Button2) {
					ChangeScreen(3);
				}else if (SenderButton == this->Button3) {
					ChangeScreen(0);
				}
			}else if (CurrentScreen == 2) {
				if (SenderButton == this->Button3) {
					auto CSize = System::Windows::Forms::TextRenderer::MeasureText(System::String::Format("Нажмите {0} для запуска", ((System::Windows::Forms::Keys)Settings_LaunchHotKey).ToString()), this->Button1->Font);
					this->ClientSize = System::Drawing::Size(CSize.Width + 32, 126);
					this->Location = System::Drawing::Point(this->Location.X + (434 - CSize.Width + 32) / 2, this->Location.Y + 102);
					ChangeScreen(1);
				}
			}else if (CurrentScreen == 3) {
				if (SenderButton == this->Button1) {
					Settings_Hide = !Settings_Hide;
					SaveSettings();
					ChangeScreen(3);
				}else if (SenderButton == this->Button2) {
					if (Settings_Type == 'S') {
						Settings_Type = 'H';
					}else {
						Settings_Type = 'S';
					}
					SaveSettings();
					ChangeScreen(3);
				}else if (SenderButton == this->Button3) {
					ChangeScreen(1);
				}
			}
		}
	}
	System::Void AllControls(System::Windows::Forms::Control::ControlCollection^ Collection) {
		for each (System::Windows::Forms::Control ^ Control in Collection) {
			if (isinst< System::Windows::Forms::Button^ >(Control)) {
				((System::Windows::Forms::Button^)Control)->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseDown);
			}else if (isinst< System::Windows::Forms::Label^ >(Control)) {
				((System::Windows::Forms::Label^)Control)->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseDown);
			}
			AllControls(Control->Controls);
		}
	}
	System::Void OnLoad(System::Object^ sender, System::EventArgs^ e) {
		this->TopMost = Settings_TopMost;
		ResizeButtons123();
		AllControls(this->Controls);
		ReadSettings();
	}
	int GetEventSpherePosition(int Index) {
		return AlgorithmScrolledX + AlgorithmStartOffset + (Index * (AlgorithmMiddleOffset + (RadiusOfAlgorithmSphere * 2)));
	}
	System::Void OnPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e){
		System::Windows::Forms::Button^ Button = (System::Windows::Forms::Button^)sender;
		if (Button->Visible) {
			e->Graphics->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(34, 34, 34), 1), 0, 0, Button->Size.Width - 1, Button->Size.Height - 1);
		}
	}
	System::Void EventsContainerOnPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (CurrentScreen == 2) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			e->Graphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::Bilinear;
			e->Graphics->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::Half;
			e->Graphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::None;
			System::Drawing::Brush^ EventSphereBrush = gcnew SolidBrush(System::Drawing::Color::FromArgb(65, 65, 65));
			System::Drawing::Brush^ SelectedEventSphereBrush = gcnew SolidBrush(System::Drawing::Color::FromArgb(45, 45, 45));
			System::Drawing::Brush^ EventSphereTextBrush = gcnew SolidBrush(System::Drawing::Color::FromArgb(255, 255, 255));
			System::Drawing::Brush^ EventContainerLineBrush = gcnew SolidBrush(System::Drawing::Color::FromArgb(110, 110, 110));
			System::Drawing::StringFormat^ EventSphereTextStringFormat = gcnew System::Drawing::StringFormat();
			EventSphereTextStringFormat->Alignment = System::Drawing::StringAlignment::Center;
			e->Graphics->FillRectangle(EventContainerLineBrush, 0, 37, 426, 1);
			for (int Index = 0; Index < std::size(Algorithm); Index++) {
				if (Algorithm[Index].Type > 0) {
					System::Drawing::Image^ EventSphereImage = nullptr;
					int EventSpherePosition = GetEventSpherePosition(Index);
					if (EventSpherePosition + (RadiusOfAlgorithmSphere * 2) >= 0 && EventSpherePosition - (RadiusOfAlgorithmSphere * 2) <= 426) {
						if (Index == SelectedAlgorithmIndex) {
							if (ChangingEventsPositions) {
								SelectedEventSphereBrush = gcnew SolidBrush(System::Drawing::Color::FromArgb(255, 255, 255));
							}
							e->Graphics->FillEllipse(SelectedEventSphereBrush, EventSpherePosition - 3, 35 - RadiusOfAlgorithmSphere, RadiusOfAlgorithmSphere * 2 + 6, RadiusOfAlgorithmSphere * 2 + 6);
						}
						e->Graphics->FillEllipse(EventSphereBrush, EventSpherePosition, 38 - RadiusOfAlgorithmSphere, RadiusOfAlgorithmSphere * 2, RadiusOfAlgorithmSphere * 2);
						if (Algorithm[Index].Type == 'K') {
							EventSphereImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DKeyboard")));
						} else if (Algorithm[Index].Type == 'P') {
							EventSphereImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DPause")));
						}else if (Algorithm[Index].Type == 'M') {
							EventSphereImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DMouse")));
						}
						e->Graphics->DrawImage(EventSphereImage, EventSpherePosition + 5, 43 - RadiusOfAlgorithmSphere, RadiusOfAlgorithmSphere * 2 - 10, RadiusOfAlgorithmSphere * 2 - 10);
						e->Graphics->DrawString((Index + 1).ToString(), (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0))), EventSphereTextBrush, System::Drawing::Rectangle(EventSpherePosition, 38 - (RadiusOfAlgorithmSphere * 2.25), RadiusOfAlgorithmSphere * 2, RadiusOfAlgorithmSphere * 2), EventSphereTextStringFormat);
					}
				} else {
					break;
				}
			}
		}
	}
	System::Void MyForm_Click(System::Object^ sender, System::EventArgs^ e) {
		TypeSelectionSetItems->Enabled = false;
		SubTypeSelectionSetItems->Enabled = false;
	}
	System::Void UpdateSelectionsData(int Index) {
		if (Algorithm[Index].Type != -1) {
			TypeSelectionSetItems->Text = "Мышь;Пауза;Клавиатура";
		}else {
			TypeSelectionSetItems->Text = "";
		}
		if (Algorithm[Index].Type == 'M') {
			TypeSelectionMain->Text = "Мышь";
			SubTypeSelectionSetItems->Text = "Нажать;Зажать;Отжать;Движение";
			if (Algorithm[Index].SubType != 'P' && Algorithm[Index].SubType != 'H' && Algorithm[Index].SubType != 'U' && Algorithm[Index].SubType != 'M') {
				Algorithm[Index].SubType = 'P';
			}
		}else if (Algorithm[Index].Type == 'P') {
			TypeSelectionMain->Text = "Пауза";
			SubTypeSelectionSetItems->Text = "Ожидание";
			if (Algorithm[Index].SubType != 'W') {
				Algorithm[Index].SubType = 'W';
			}
			PauseWaitUpDownTextBox->Text = Algorithm[Index].Microsecond.ToString();
		}else if (Algorithm[Index].Type == 'K') {
			TypeSelectionMain->Text = "Клавиатура";
			SubTypeSelectionSetItems->Text = "Нажать;Зажать;Отжать";
			if (Algorithm[Index].SubType != 'P' && Algorithm[Index].SubType != 'H' && Algorithm[Index].SubType != 'U') {
				Algorithm[Index].SubType = 'P';
			}
		}
		if (Algorithm[Index].SubType == 'P') {
			SubTypeSelectionMain->Text = "Нажать";
		}else if (Algorithm[Index].SubType == 'H') {
			SubTypeSelectionMain->Text = "Зажать";
		}else if (Algorithm[Index].SubType == 'U') {
			SubTypeSelectionMain->Text = "Отжать";
		}else if (Algorithm[Index].SubType == 'M') {
			SubTypeSelectionMain->Text = "Движение";
		}else if (Algorithm[Index].SubType == 'W') {
			SubTypeSelectionMain->Text = "Ожидание";
		}
		if (Algorithm[Index].SubType == 'P' || Algorithm[Index].SubType == 'H' || Algorithm[Index].SubType == 'U') {
			if (Algorithm[SelectedAlgorithmIndex].KeyOrButton) {
				KeyToPress->Text = ((System::Windows::Forms::Keys)Algorithm[SelectedAlgorithmIndex].KeyOrButton).ToString();
			} else {
				KeyToPress->Text = "NULL";
			}
		}else if (Algorithm[Index].SubType == 'M') {
			MousePositionXTextBox->Text = Algorithm[SelectedAlgorithmIndex].Position.X.ToString();
			MousePositionYTextBox->Text = Algorithm[SelectedAlgorithmIndex].Position.Y.ToString();
		}
	}
	System::Void EventsContainerOnClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int Index = ((e->X - AlgorithmScrolledX - AlgorithmStartOffset) / (RadiusOfAlgorithmSphere * 2 + AlgorithmMiddleOffset));
		int EventSpherePosition = GetEventSpherePosition(Index);
		if (e->X >= EventSpherePosition && e->X <= EventSpherePosition + (RadiusOfAlgorithmSphere * 2) && e->Y >= 38 - RadiusOfAlgorithmSphere && e->Y <= 38 + RadiusOfAlgorithmSphere && Algorithm[Index].Type > 0) {
			if (ChangingEventsPositions && Algorithm[SelectedAlgorithmIndex].Type > 0) {
				AlgorithmEvent SavedAlgorithmEvent = Algorithm[Index];
				Algorithm[Index] = Algorithm[SelectedAlgorithmIndex];
				Algorithm[SelectedAlgorithmIndex] = SavedAlgorithmEvent;
				ChangingEventsPositions = false;
			}
			SelectedAlgorithmIndex = Index;
		}else {
			SelectedAlgorithmIndex = -1;
			TypeSelectionSetItems->Text = "";
			SubTypeSelectionSetItems->Text = "";
		}
		TypeSelectionSetItems->Enabled = false;
		SubTypeSelectionSetItems->Enabled = false;
		UpdateSelectionsData(SelectedAlgorithmIndex);
		EventsContainer->Refresh();
		UpdateEventSphereControls();
	}
	System::Void UpdateEventSphereControls() {
		bool Exist = Algorithm[SelectedAlgorithmIndex].Type > 0;
		//Any Event
		MoveEventSphere->Visible = Exist;
		DeleteEventSphere->Visible = Exist;
		//Mouse
		MousePositionLabel->Visible = Exist && Algorithm[SelectedAlgorithmIndex].Type == 'M' && Algorithm[SelectedAlgorithmIndex].SubType == 'M';
		MousePositionXUpDown->Visible = Exist && Algorithm[SelectedAlgorithmIndex].Type == 'M' && Algorithm[SelectedAlgorithmIndex].SubType == 'M';
		MousePositionYUpDown->Visible = Exist && Algorithm[SelectedAlgorithmIndex].Type == 'M' && Algorithm[SelectedAlgorithmIndex].SubType == 'M';
		ChangePositionButton->Visible = Exist && Algorithm[SelectedAlgorithmIndex].Type == 'M' && Algorithm[SelectedAlgorithmIndex].SubType == 'M';
		//Pause
		PauseWaitLabel->Visible = Exist && Algorithm[SelectedAlgorithmIndex].Type == 'P';
		PauseWaitUpDown->Visible = Exist && Algorithm[SelectedAlgorithmIndex].Type == 'P';
		//Keyboard || Mouse
		KeyToPressLabel->Visible = Exist && ((Algorithm[SelectedAlgorithmIndex].Type == 'M' && Algorithm[SelectedAlgorithmIndex].SubType != 'M') || (Algorithm[SelectedAlgorithmIndex].Type == 'K'));
		PressKeyLabel->Visible = Exist && ((Algorithm[SelectedAlgorithmIndex].Type == 'M' && Algorithm[SelectedAlgorithmIndex].SubType != 'M') || (Algorithm[SelectedAlgorithmIndex].Type == 'K'));
		KeyToPress->Visible = Exist && ((Algorithm[SelectedAlgorithmIndex].Type == 'M' && Algorithm[SelectedAlgorithmIndex].SubType != 'M') || (Algorithm[SelectedAlgorithmIndex].Type == 'K'));
	}
	System::Void TypeChanged(System::Object^ sender, System::EventArgs^ e) {
		char PrevType = Algorithm[SelectedAlgorithmIndex].Type;
		if (TypeSelectionMain->Text == "Мышь") {
			Algorithm[SelectedAlgorithmIndex].Type = 'M';
		}else if (TypeSelectionMain->Text == "Пауза") {
			Algorithm[SelectedAlgorithmIndex].Type = 'P';
		}else if (TypeSelectionMain->Text == "Клавиатура") {
			Algorithm[SelectedAlgorithmIndex].Type = 'K';
		}
		if (PrevType != Algorithm[SelectedAlgorithmIndex].Type && (PrevType == 'M' && Algorithm[SelectedAlgorithmIndex].Type == 'K') || (PrevType == 'K' && Algorithm[SelectedAlgorithmIndex].Type == 'M')) {
			Algorithm[SelectedAlgorithmIndex].KeyOrButton = NULL;
		}
		EventsContainer->Refresh();
		UpdateSelectionsData(SelectedAlgorithmIndex);
		UpdateEventSphereControls();
		SaveSettings();
	}
	System::Void SubTypeChanged(System::Object^ sender, System::EventArgs^ e) {
		if (SubTypeSelectionMain->Text == "Нажать") {
			Algorithm[SelectedAlgorithmIndex].SubType = 'P';
		}else if (SubTypeSelectionMain->Text == "Зажать") {
			Algorithm[SelectedAlgorithmIndex].SubType = 'H';
		}else if (SubTypeSelectionMain->Text == "Отжать") {
			Algorithm[SelectedAlgorithmIndex].SubType = 'U';
		}else if (SubTypeSelectionMain->Text == "Движение") {
			Algorithm[SelectedAlgorithmIndex].SubType = 'M';
		}else if (SubTypeSelectionMain->Text == "Ожидание") {
			Algorithm[SelectedAlgorithmIndex].SubType = 'W';
		}
		UpdateEventSphereControls();
		SaveSettings();
	}
	System::Void WaitKeyButton(System::Object^ GivenObject) {
		bool IsKeyboard = (bool)GivenObject;
		NewKeyButtonIsKeyboard = IsKeyboard;
		WaitingNewKeyButton = true;
		this->KeyToPress->Visible = false;
		while (true) {
			if (!WaitingNewKeyButton) {
				Algorithm[SelectedAlgorithmIndex].KeyOrButton = NewKeyButton;
				this->KeyToPress->Text = ((System::Windows::Forms::Keys)NewKeyButton).ToString();
				this->KeyToPress->Visible = true;
				break;
			}
		}
	}
	private: System::Void OnSizeChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!SelectionsAdded) {
			System::Windows::Forms::Control::ControlCollection^ ControlCollection = this->Controls;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			//cli::array<System::String^>^ Types = gcnew cli::array<System::String^, 1>(3) { "Мышь", "Пауза", "Клавиатура" };
			//cli::array<System::String^>^ SubTypes = gcnew cli::array<System::String^, 1>(4) { "Нажатие", "Зажать", "Отжать", "Движение" };
			auto TypesItems = gcnew cli::array<System::String^, 1>(0) {};
			auto SubTypesItems = gcnew cli::array<System::String^, 1>(0) {};
			CustomSelection TypeSelection(this->Controls, System::Drawing::Point(4, 128), System::Drawing::Size(211, 35), TypesItems, resources);
			CustomSelection SubTypeSelection(this->Controls, System::Drawing::Point(219, 128), System::Drawing::Size(211, 35), SubTypesItems, resources);
			CustomNumericUpDown NumericUpDown(this->Controls, System::Drawing::Point(220, 168), System::Drawing::Size(211, 35), System::Drawing::Size(30, 18), resources, 0, 9999999999999999, true);
			CustomNumericUpDown MousePositionX(this->Controls, System::Drawing::Point(147, 168), System::Drawing::Size(68, 35), System::Drawing::Size(30, 18), resources, 0, 9999999999999999, false);
			CustomNumericUpDown MousePositionY(this->Controls, System::Drawing::Point(219, 168), System::Drawing::Size(68, 35), System::Drawing::Size(30, 18), resources, 0, 9999999999999999, false);
			TypeSelection.InitializeComponent();
			SubTypeSelection.InitializeComponent();
			NumericUpDown.InitializeComponent();
			MousePositionX.InitializeComponent();
			MousePositionY.InitializeComponent();
			NumericUpDown.LabelBackground->Visible = false;
			MousePositionX.LabelBackground->Visible = false;
			MousePositionY.LabelBackground->Visible = false;
			MousePositionLabel->Visible = false;
			PauseWaitLabel->Visible = false;
			KeyToPressLabel->Visible = false;
			PressKeyLabel->Visible = false;
			ChangePositionButton->Visible = false;
			TypeSelectionMain = TypeSelection.SelectionMain;
			SubTypeSelectionMain = SubTypeSelection.SelectionMain;
			TypeSelectionSetItems = TypeSelection.SetItems;
			TypeSelectionSetItems->EnabledChanged += gcnew System::EventHandler(this, &MyForm::OnEnabledChanged);
			SubTypeSelectionSetItems = SubTypeSelection.SetItems;
			PauseWaitUpDown = NumericUpDown.LabelBackground;
			PauseWaitUpDownTextBox = NumericUpDown.NumericUpDown;
			MousePositionXUpDown = MousePositionX.LabelBackground;
			MousePositionYUpDown = MousePositionY.LabelBackground;
			MousePositionXTextBox = MousePositionX.NumericUpDown;
			MousePositionYTextBox = MousePositionY.NumericUpDown;
			TypeSelection.SelectionMain->TextChanged += gcnew System::EventHandler(this, &MyForm::TypeChanged);
			SubTypeSelection.SelectionMain->TextChanged += gcnew System::EventHandler(this, &MyForm::SubTypeChanged);
			PauseWaitUpDownTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::PauseWaitUpDownTextChanged);
			MousePositionXTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::MousePositionXTextChanged);
			MousePositionYTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::MousePositionYTextChanged);
			for each (System::Windows::Forms::Control ^ Control in ControlCollection) {
				if (Control->Name) {
					this->Controls->Remove(Control);
					this->Controls->Add(Control);
				}
			}
			SelectionsAdded = true;
			MouseEvents[1]['H'] = { MOUSEEVENTF_LEFTDOWN };
			MouseEvents[1]['U'] = { MOUSEEVENTF_LEFTUP };
			MouseEvents[2]['H'] = { MOUSEEVENTF_RIGHTDOWN };
			MouseEvents[2]['U'] = { MOUSEEVENTF_RIGHTUP };
			MouseEvents[4]['H'] = { MOUSEEVENTF_MIDDLEDOWN };
			MouseEvents[4]['U'] = { MOUSEEVENTF_MIDDLEUP };
			MouseEvents[5]['H'] = { MOUSEEVENTF_XDOWN };
			MouseEvents[5]['U'] = { MOUSEEVENTF_XUP };
			MouseEvents[6]['H'] = { MOUSEEVENTF_XDOWN };
			MouseEvents[6]['U'] = { MOUSEEVENTF_XUP };
			System::Threading::Thread^ PreStartAlgorithmThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MyForm::PreStartAlgorithm));
			PreStartAlgorithmThread->IsBackground = true;
			PreStartAlgorithmThread->Start();
			System::Threading::Thread^ ProcessAlgorithmLaunchedThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MyForm::ProcessAlgorithmLaunched));
			ProcessAlgorithmLaunchedThread->IsBackground = true;
			ProcessAlgorithmLaunchedThread->Start();
			System::Threading::Thread^ HideShowLoopThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MyForm::HideShowLoop));
			HideShowLoopThread->IsBackground = true;
			HideShowLoopThread->Start();
		}
	}
	System::Void OnEnabledChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Algorithm[SelectedAlgorithmIndex].Type == 'M' && Algorithm[SelectedAlgorithmIndex].SubType == 'M') {
			MousePositionXUpDown->Visible = !TypeSelectionSetItems->Enabled;
		}
	}
	System::Void LoopChangeCursor() {
		GetAsyncKeyState(MK_LBUTTON);
		while (true) {
			if (GetAsyncKeyState(MK_LBUTTON)) {
				ChangeCursorToClientStandart();
				Algorithm[SelectedAlgorithmIndex].Position = System::Windows::Forms::Cursor::Position;
				UpdateSelectionsData(SelectedAlgorithmIndex);
				break;
			}
		}
	}
	System::Void ChangeCursorToClientStandart() {
		if (OldSytemCursor) {
			SetSystemCursor(OldSytemCursor, OCR_NORMAL);
			DestroyCursor(OldSytemCursor);
			OldSytemCursor = NULL;
			this->Show();
		}
	}
	System::Void ChangeCursorToCross() {
		if (!OldSytemCursor) {
			OldSytemCursor = CopyCursor(::LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW)));
			SetSystemCursor(CopyCursor(::LoadCursor(NULL, MAKEINTRESOURCE(IDC_CROSS))), OCR_NORMAL);
			this->Hide();
		}
	}
	System::Void ChangeMousePosition(System::Object^ sender, System::EventArgs^ e) {
		if (!OldSytemCursor) {
			ChangeCursorToCross();
			System::Threading::Thread^ LoopChangeCursorThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MyForm::LoopChangeCursor));
			LoopChangeCursorThread->IsBackground = true;
			LoopChangeCursorThread->Start();
		}
	}
	System::Void PauseWaitUpDownTextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Algorithm[SelectedAlgorithmIndex].Type != 0) {
			Algorithm[SelectedAlgorithmIndex].Microsecond = System::Int32::Parse(PauseWaitUpDownTextBox->Text);
		}
	}
	System::Void MousePositionXTextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Algorithm[SelectedAlgorithmIndex].Type != 0) {
			Algorithm[SelectedAlgorithmIndex].Position = System::Drawing::Point(System::Int32::Parse(((System::Windows::Forms::TextBox^)sender)->Text), Algorithm[SelectedAlgorithmIndex].Position.Y);
		}
	}
	System::Void MousePositionYTextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Algorithm[SelectedAlgorithmIndex].Type != 0) {
			Algorithm[SelectedAlgorithmIndex].Position = System::Drawing::Point(Algorithm[SelectedAlgorithmIndex].Position.X, System::Int32::Parse(((System::Windows::Forms::TextBox^)sender)->Text));
		}
	}
	System::Void ChangeKeyButton(System::Object^ sender, System::EventArgs^ e) {
		if (isinst< System::Windows::Forms::MouseEventArgs^ >(e) || isinst< System::Windows::Forms::KeyPressEventArgs^ >(e)) {
			System::Threading::Thread^ WaitKeyButtonThread = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &MyForm::WaitKeyButton));
			WaitKeyButtonThread->IsBackground = true;
			WaitKeyButtonThread->Start(Algorithm[SelectedAlgorithmIndex].Type == 'K');
		}
	}
	System::Void AddEvent(char Type, char SubType, DWORD KeyOrButton, int Microsecond, System::Drawing::Point Position) {
		for (int Index = 0; Index <= sizeof(Algorithm); Index++) {
			if (!Algorithm[Index].Type != 0) {
				Algorithm[Index] = { Type, SubType, KeyOrButton, Microsecond, Position };
				SelectedAlgorithmIndex = Index;
				EventsContainer->Refresh();
				UpdateSelectionsData(Index);
				break;
			}
		}
	}
	System::Void DeleteEvent(int DeleteIndex) {
		bool DeleteIndexFound = false;
		for (int Index = 0; Index <= sizeof(Algorithm); Index++) {
			if (Index == DeleteIndex) {
				DeleteIndexFound = true;
			}
			if (DeleteIndexFound) {
				Algorithm[Index] = Algorithm[Index + 1];
			}
			if (Algorithm[Index].Type <= 0) {
				break;
			}
		}
	}
	System::Void ReadSettings() {
		if (access("Settings.resources", 0) == 0) {
			System::Resources::IResourceReader^ ResourceReader = gcnew System::Resources::ResourceReader("Settings.resources");
			auto Enums = ResourceReader->GetEnumerator();
			while (Enums->MoveNext()) {
				System::String^ Key = Enums->Key->ToString();
				if (Key == "Settings_LaunchHotKey") {
					Settings_LaunchHotKey = System::Int32::Parse(Enums->Value->ToString());
				}
				else if (Key == "Settings_TopMost") {
					Settings_TopMost = System::Boolean::Parse(Enums->Value->ToString());
				}
				else if (Key == "Settings_Hide") {
					Settings_Hide = System::Boolean::Parse(Enums->Value->ToString());
				}
				else if (Key == "Settings_Type") {
					Settings_Type = char::Parse(Enums->Value->ToString());
				}
				else if (Key->Substring(0, 14) == "AlgorithmEvent") {
					int IndexEvent = System::Int32::Parse(Key->Substring(14));
					System::String^ Value = Enums->Value->ToString() + ";";
					System::String^ Symbol = "";
					int Pos = 0;
					int SymbolIndex = 0;
					System::String^ EventData = "";
					for (int Index = 0; Index < Value->Length; Index++) {
						Symbol = Value->Substring(Index, 1);
						if (Symbol == ";") {
							EventData = Value->Substring(Pos, Index - Pos);
							SymbolIndex++;
							switch (SymbolIndex) {
							case 1:
								Algorithm[IndexEvent].Type = char::Parse(EventData);
								break;
							case 2:
								Algorithm[IndexEvent].SubType = char::Parse(EventData);
								break;
							case 3:
								Algorithm[IndexEvent].KeyOrButton = DWORD(System::Int32::Parse(EventData));
								break;
							case 4:
								Algorithm[IndexEvent].Microsecond = System::Int32::Parse(EventData);
								break;
							case 5:
								int SplitIndex = EventData->IndexOf(":");
								Algorithm[IndexEvent].Position = System::Drawing::Point(System::Int32::Parse(EventData->Substring(0, SplitIndex)), System::Int32::Parse(EventData->Substring(SplitIndex + 1)));
								break;
							}
							Pos = Index + 1;
						}
					}
				}
			}
			this->TopMost = Settings_TopMost;
			ResourceReader->Close();
		}
	}
	System::Void SaveSettings() {
		int AlgoirthmLength = 0;
		System::Resources::IResourceWriter ^ResourceWriter = gcnew System::Resources::ResourceWriter("Settings.resources");
		ResourceWriter->AddResource("Settings_LaunchHotKey", Settings_LaunchHotKey.ToString());
		ResourceWriter->AddResource("Settings_TopMost", Settings_TopMost.ToString());
		ResourceWriter->AddResource("Settings_Hide", Settings_Hide.ToString());
		ResourceWriter->AddResource("Settings_Type", Settings_Type);
		for (int Index = 0; Index <= sizeof(Algorithm); Index++) {
			if (Algorithm[Index].Type > 0) {
				ResourceWriter->AddResource("AlgorithmEvent" + Index.ToString(), System::String::Format("{0};{1};{2};{3};{4}:{5}",Algorithm[Index].Type, Algorithm[Index].SubType, Algorithm[Index].KeyOrButton, Algorithm[Index].Microsecond, Algorithm[Index].Position.X, Algorithm[Index].Position.Y));
			}else {
				AlgoirthmLength = Index + 1;
				break;
			}
		}
		ResourceWriter->AddResource("AlgoirthmLength", AlgoirthmLength.ToString());
		ResourceWriter->Close();
	}
	System::Void FuncMoveEventSphere(System::Object^ sender, System::EventArgs^ e) {
		ChangingEventsPositions = !ChangingEventsPositions;
		EventsContainer->Refresh();
	}
	System::Void FuncDeleteEventSphere(System::Object^ sender, System::EventArgs^ e) {
		DeleteEvent(SelectedAlgorithmIndex);
		System::String^ s = "";
		for (int Index = 0; Index <= sizeof(Algorithm); Index++) {
			if (Algorithm[Index].Type <= 0) {
				if (Index <= SelectedAlgorithmIndex) {
					SelectedAlgorithmIndex = Index-1;
					TypeSelectionSetItems->Text = "";
					SubTypeSelectionSetItems->Text = "";
				}
				break;
			}
		}
		TypeSelectionSetItems->Enabled = false;
		SubTypeSelectionSetItems->Enabled = false;
		UpdateSelectionsData(SelectedAlgorithmIndex);
		ScrollEventsContainer(0);
		UpdateEventSphereControls();
	}
	System::Void FunctionAddEventMouse(System::Object^ sender, System::EventArgs^ e) {
		AddEvent('M', 'P', NULL, 0, System::Drawing::Point(0,0));
	}
	System::Void FunctionAddEventPause(System::Object^ sender, System::EventArgs^ e) {
		AddEvent('P', 'W', NULL, 0, System::Drawing::Point(0, 0));
	}
	System::Void FunctionAddEventKeyboard(System::Object^ sender, System::EventArgs^ e) {
		AddEvent('K', 'P', NULL, 0, System::Drawing::Point(0, 0));
	}
	System::Void HideShow() {
		if (Settings_Hide && this->Visible != !AlgorithmLaunched) {
			if (!AlgorithmLaunched) {
				this->Show();
			}else {
				this->Hide();
			}
		}else {
			this->Show();
		}
	}
	System::Void HideShowLoop() {
		bool SavedState = NULL;
		while (true) {
			if (AlgorithmLaunched != SavedState) {
				if (CurrentScreen == 0 && AlgorithmLaunched && !Settings_Hide) {
					this->Button1->Text = System::String::Format("Нажмите {0} для останов.", ((System::Windows::Forms::Keys)Settings_LaunchHotKey).ToString());
				}else if (CurrentScreen == 0 && !AlgorithmLaunched && !Settings_Hide) {
					this->Button1->Text = System::String::Format("Нажмите {0} для запуска", ((System::Windows::Forms::Keys)Settings_LaunchHotKey).ToString());
				}
				HideShow();
				SavedState = AlgorithmLaunched;
			}
			FunctionWait(1);
		}
	}
	System::Void ProcessAlgorithmLaunched() {
		while (true) {
			if (WaitingNewKey) {
				while (true) {
					if (!WaitingNewKey) {
						while (true) {
							if (!GetAsyncKeyState(Settings_LaunchHotKey)) {
								break;
							}
						}
						break;
					}
				}
			}
			if (Settings_Type == 'S') {
				if (GetAsyncKeyState(Settings_LaunchHotKey)) {
					AlgorithmLaunched = true;
					while (true) {
						if (!GetAsyncKeyState(Settings_LaunchHotKey)) {
							break;
						}
					}
					while (true) {
						if (GetAsyncKeyState(Settings_LaunchHotKey)) {
							AlgorithmLaunched = false;
							break;
						}
					}
					while (true) {
						if (!GetAsyncKeyState(Settings_LaunchHotKey)) {
							break;
						}
					}
				}
			}else if (Settings_Type == 'H') {
				if (GetAsyncKeyState(Settings_LaunchHotKey)) {
					AlgorithmLaunched = true;
				}else {
					AlgorithmLaunched = false;
				}
			}
			FunctionWait(1);
		}
	}
	System::Void PreStartAlgorithm() {
		while (true) {
			if (AlgorithmLaunched) {
				for (int Index = 0; Index <= sizeof(Algorithm); Index++) {
					if (Algorithm[Index].Type != 0 && AlgorithmLaunched) {
						if ((Algorithm[Index].Type == 'M' || Algorithm[Index].Type == 'K') && (Algorithm[Index].KeyOrButton || Algorithm[Index].SubType == 'M')) {
							INPUT FirstInput{};
							if (Algorithm[Index].Type == 'M') {
								FirstInput.type = INPUT_MOUSE;
							}else {
								FirstInput.type = INPUT_KEYBOARD;
							}
							if (Algorithm[Index].SubType == 'P' || Algorithm[Index].SubType == 'H') {
								if (Algorithm[Index].Type == 'M') {
									FirstInput.mi.dwFlags = MouseEvents[Algorithm[Index].KeyOrButton]['H'];
								}else {
									FirstInput.ki.wVk = Algorithm[Index].KeyOrButton;
									FirstInput.ki.dwFlags = KEYEVENTF_KEYDOWN;
								}
							}else if (Algorithm[Index].SubType == 'U') {
								if (Algorithm[Index].Type == 'M') {
									FirstInput.mi.dwFlags = MouseEvents[Algorithm[Index].KeyOrButton]['U'];
								}else {
									FirstInput.ki.wVk = Algorithm[Index].KeyOrButton;
									FirstInput.ki.dwFlags = KEYEVENTF_KEYUP;
								}
							}else if (Algorithm[Index].SubType == 'M') {
								FirstInput.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_VIRTUALDESK | MOUSEEVENTF_ABSOLUTE;
								FirstInput.mi.dx = Algorithm[Index].Position.X * (65536 / GetSystemMetrics(SM_CXSCREEN));
								FirstInput.mi.dy = Algorithm[Index].Position.Y * (65536 / GetSystemMetrics(SM_CYSCREEN));
							}
							SendInput(1, &FirstInput, sizeof(FirstInput));
							if (Algorithm[Index].SubType == 'P') {
								if (Algorithm[Index].Type == 'M') {
									FirstInput.mi.dwFlags = MouseEvents[Algorithm[Index].KeyOrButton]['U'];
								}else {
									FirstInput.ki.dwFlags = KEYEVENTF_KEYUP;
								}
								SendInput(1, &FirstInput, sizeof(FirstInput));
							}
						}else if (Algorithm[Index].Type == 'P') {
							FunctionWait(Algorithm[Index].Microsecond);
						}
					}else {
						break;
					}
					FunctionWait(1);
				}
			}
		}
	}
};
}