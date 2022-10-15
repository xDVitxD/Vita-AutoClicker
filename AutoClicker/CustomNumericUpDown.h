#pragma once
#include <chrono>
#include <thread>

void FunctionWait(int Microseconds) {
	std::this_thread::sleep_for(std::chrono::microseconds{ Microseconds });
}

public ref class CustomNumericUpDown {
public:
	System::ComponentModel::ComponentResourceManager^ resources;
	System::Windows::Forms::Control::ControlCollection^ ParentOfSelection;
	System::Drawing::Point Location;
	System::Drawing::Size Size;
	System::Drawing::Size UpDownSize;
	int MinValue, MaxValue;
	bool CreateUpDownButtons;
	CustomNumericUpDown(System::Windows::Forms::Control::ControlCollection^ ObjectToCreate, System::Drawing::Point GivenLocation, System::Drawing::Size GivenSize, System::Drawing::Size GivenUpDownSize, System::ComponentModel::ComponentResourceManager^ GivenResources, int Min, int Max, bool VisibleUpDown) {
		ParentOfSelection = ObjectToCreate; Location = GivenLocation; Size = GivenSize; UpDownSize = GivenUpDownSize; resources = GivenResources; MinValue = Min; MaxValue = Max; CreateUpDownButtons = VisibleUpDown;
	};
	System::Windows::Forms::Label^ LabelBackground;
	System::Windows::Forms::TextBox^ NumericUpDown;
	System::Windows::Forms::Button^ UpButton;
	System::Windows::Forms::Button^ DownButton;
	System::Windows::Forms::Label^ UnderLineNumbericUpDown;
	bool UpButtonHolding, DownButtonHolding;
	int CurrentNumber = 0;
	System::String^ LastText = "0";
	System::Void InitializeComponent() {
		LabelBackground = gcnew System::Windows::Forms::Label;
		LabelBackground->AutoSize = false;
		LabelBackground->BackColor = System::Drawing::Color::FromArgb(68, 68, 68);
		LabelBackground->Location = Location;
		LabelBackground->Size = Size;
		LabelBackground->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
		LabelBackground->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		LabelBackground->Name = "LabelBackground";
		NumericUpDown = gcnew System::Windows::Forms::TextBox;
		NumericUpDown->AutoSize = false;
		NumericUpDown->BackColor = System::Drawing::Color::FromArgb(68, 68, 68);
		NumericUpDown->BorderStyle = System::Windows::Forms::BorderStyle::None;
		NumericUpDown->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
		NumericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
		NumericUpDown->Location = System::Drawing::Point(8, 8);
		if (CreateUpDownButtons) {
			NumericUpDown->Size = System::Drawing::Size(Size.Width - UpDownSize.Width - 8, Size.Height);
		}
		else {
			NumericUpDown->Size = System::Drawing::Size(Size.Width - 8, Size.Height);
		}
		NumericUpDown->Text = CurrentNumber.ToString();
		NumericUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		NumericUpDown->GotFocus += gcnew System::EventHandler(this, &CustomNumericUpDown::NumericUpDownFocused);
		NumericUpDown->LostFocus += gcnew System::EventHandler(this, &CustomNumericUpDown::NumericUpDownUnFocused);
		NumericUpDown->TextChanged += gcnew System::EventHandler(this, &CustomNumericUpDown::NumericUpDownTextChanged);
		NumericUpDown->Name = "NumericUpDown";
		UpButton = gcnew System::Windows::Forms::Button;
		UpButton->AutoSize = false;
		UpButton->BackColor = System::Drawing::Color::FromArgb(68, 68, 68);
		UpButton->FlatAppearance->BorderSize = 0;
		UpButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		UpButton->Location = System::Drawing::Point(Size.Width - UpDownSize.Width, 0);
		UpButton->Size = System::Drawing::Size(UpDownSize.Width, UpDownSize.Height);
		UpButton->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CustomNumericUpDown::OnPaint);
		UpButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &CustomNumericUpDown::OnMouseDown);
		UpButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &CustomNumericUpDown::OnMouseUp);
		UpButton->Visible = CreateUpDownButtons;
		UpButton->Name = "UpButton";
		DownButton = gcnew System::Windows::Forms::Button;
		DownButton->AutoSize = false;
		DownButton->BackColor = System::Drawing::Color::FromArgb(68, 68, 68);
		DownButton->FlatAppearance->BorderSize = 0;
		DownButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		DownButton->Location = System::Drawing::Point(Size.Width - UpDownSize.Width, UpDownSize.Height - 1);
		DownButton->Size = System::Drawing::Size(UpDownSize.Width, UpDownSize.Height);
		DownButton->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CustomNumericUpDown::OnPaint);
		DownButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &CustomNumericUpDown::OnMouseDown);
		DownButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &CustomNumericUpDown::OnMouseUp);
		DownButton->Visible = CreateUpDownButtons;
		DownButton->Name = "DownButton";
		UnderLineNumbericUpDown = gcnew System::Windows::Forms::Label;
		UnderLineNumbericUpDown->BackColor = System::Drawing::Color::FromArgb(29, 29, 29);
		UnderLineNumbericUpDown->Location = System::Drawing::Point(0, Size.Height - 2);
		UnderLineNumbericUpDown->Size = System::Drawing::Size(Size.Width, 2);
		UnderLineNumbericUpDown->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		UnderLineNumbericUpDown->Name = "UnderLineNumbericUpDown";
		LabelBackground->Controls->Add(UpButton);
		LabelBackground->Controls->Add(DownButton);
		LabelBackground->Controls->Add(UnderLineNumbericUpDown);
		LabelBackground->Controls->Add(NumericUpDown);
		ParentOfSelection->Add(LabelBackground);
	}
	System::Void ButtonHolding(System::Object^ sender) {
		bool IsUpButton, IsDownButton;
		IsUpButton = (System::Windows::Forms::Button^)sender == UpButton;
		IsDownButton = (System::Windows::Forms::Button^)sender == DownButton;
		int WaitTime = 250;
		if (IsUpButton) {
			UpButtonHolding = true;
		}
		else if (IsDownButton) {
			DownButtonHolding = true;
		}
		while (true) {
			if ((IsUpButton && UpButtonHolding) || (IsDownButton && DownButtonHolding)) {
				if (IsUpButton) {
					CurrentNumber++;
				}
				else if (IsDownButton) {
					CurrentNumber--;
				}
				if (CurrentNumber < MinValue) {
					CurrentNumber = MinValue;
					break;
				}
				else if (CurrentNumber > MaxValue) {
					CurrentNumber = MaxValue;
					break;
				}
				NumericUpDown->Text = CurrentNumber.ToString();
				FunctionWait(WaitTime * 1000);
				if (WaitTime > 250) {
					WaitTime -= 5;
				}
				else if (WaitTime > 150) {
					WaitTime -= 25;
				}
				else if (WaitTime > 10) {
					WaitTime -= 10;
				}
			}
			else {
				break;
			}
		}
	}
	System::Void OnMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Threading::Thread^ ButtonHoldingThread = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &CustomNumericUpDown::ButtonHolding));
		ButtonHoldingThread->IsBackground = true;
		ButtonHoldingThread->Start(sender);
	}
	System::Void OnMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if ((System::Windows::Forms::Button^)sender == UpButton) {
			UpButtonHolding = false;
		}
		else if ((System::Windows::Forms::Button^)sender == DownButton) {
			DownButtonHolding = false;
		}
	}
	System::Void NumericUpDownFocused(System::Object^ sender, System::EventArgs^ e) {
		UnderLineNumbericUpDown->BackColor = System::Drawing::Color::FromArgb(33, 150, 243);
	}
	System::Void NumericUpDownUnFocused(System::Object^ sender, System::EventArgs^ e) {
		UnderLineNumbericUpDown->BackColor = System::Drawing::Color::FromArgb(29, 29, 29);
	}
	System::Void NumericUpDownTextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (System::Text::RegularExpressions::Regex::IsMatch(NumericUpDown->Text, "[^0-9]")) {
			NumericUpDown->Text = LastText;
		}
		CurrentNumber = System::Int32::Parse(NumericUpDown->Text);
		LastText = NumericUpDown->Text;
	}
	System::Void OnPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		System::Windows::Forms::Button^ Button = (System::Windows::Forms::Button^)sender;
		if (Button->Visible) {
			e->Graphics->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(34, 34, 34), 1), 0, 0, UpDownSize.Width - 1, UpDownSize.Height - 1);
			if (Button == UpButton) {
				e->Graphics->DrawImage((cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ArrowImageInversed"))), (UpDownSize.Width / 2) - 5, (UpDownSize.Height / 2) - 2);
			}
			else if (Button == DownButton) {
				e->Graphics->DrawImage((cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ArrowImage"))), (UpDownSize.Width / 2) - 5, (UpDownSize.Height / 2) - 4);
			}
		}
	}
};