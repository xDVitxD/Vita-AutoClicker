#pragma once

public ref class CustomSelection {
public:
	System::ComponentModel::ComponentResourceManager^ resources;
	System::Windows::Forms::Control::ControlCollection^ ParentOfSelection;
	cli::array<System::String^>^ Items;
	System::Drawing::Point Location;
	System::Drawing::Size Size;
	CustomSelection(System::Windows::Forms::Control::ControlCollection^ ObjectToCreate, System::Drawing::Point GivenLocation, System::Drawing::Size GivenSize, cli::array<System::String^>^ GivenItems, System::ComponentModel::ComponentResourceManager^ GivenResources) {
		ParentOfSelection = ObjectToCreate; Items = GivenItems; Location = GivenLocation; Size = GivenSize; resources = GivenResources;
	};
	System::Windows::Forms::Label^ SetItems;
	System::Windows::Forms::Button^ SelectionMain;
	System::Windows::Forms::PictureBox^ ArrowImage;
	System::Windows::Forms::Label^ UnderLineSelection;
	System::Windows::Forms::Label^ List;
	bool Opened = false;
	System::Void InitializeComponent() {
		SetItems = gcnew System::Windows::Forms::Label();
		SetItems->Text = " ";
		SetItems->TextChanged += gcnew System::EventHandler(this, &CustomSelection::SetNewItems);
		SetItems->Enabled = Opened;
		SetItems->EnabledChanged += gcnew System::EventHandler(this, &CustomSelection::ChangeListOpen);
		SetItems->Name = "SetItems";
		SetItems->Visible = false;
		SelectionMain = gcnew System::Windows::Forms::Button();
		SelectionMain->BackColor = System::Drawing::Color::FromArgb(68, 68, 68);
		SelectionMain->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		SelectionMain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		SelectionMain->Location = Location;
		SelectionMain->Size = Size;
		SelectionMain->FlatAppearance->BorderSize = 0;
		SelectionMain->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(0, 0, 0, 0);
		SelectionMain->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(145, 68, 68, 68);
		SelectionMain->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
		if (Items->Length > 0) {
			SelectionMain->Text = Items[0];
		}
		SelectionMain->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		SelectionMain->Click += gcnew System::EventHandler(this, &CustomSelection::CustomSelectionClick);
		SelectionMain->Name = "SelectionMain";
		ArrowImage = gcnew System::Windows::Forms::PictureBox;
		ArrowImage->BackColor = System::Drawing::Color::Transparent;
		ArrowImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ArrowImage")));
		ArrowImage->Location = System::Drawing::Point(Size.Width - 22, 15);
		ArrowImage->Name = L"ArrowImage";
		ArrowImage->Size = System::Drawing::Size(8, 5);
		ArrowImage->TabIndex = 9;
		ArrowImage->TabStop = false;
		ArrowImage->Name = "ArrowImage";
		UnderLineSelection = gcnew System::Windows::Forms::Label;
		UnderLineSelection->BackColor = System::Drawing::Color::FromArgb(29, 29, 29);
		UnderLineSelection->Size = System::Drawing::Size(Size.Width, 2);
		UnderLineSelection->Location = System::Drawing::Point(0, Size.Height - 2);
		UnderLineSelection->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		UnderLineSelection->Name = "UnderLineSelection";
		SelectionMain->Controls->Add(ArrowImage);
		SelectionMain->Controls->Add(UnderLineSelection);
		SelectionMain->Controls->Add(SetItems);
		ParentOfSelection->Add(SelectionMain);
		List = gcnew System::Windows::Forms::Label();
		List->BackColor = System::Drawing::Color::FromArgb(38, 38, 38);
		List->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		List->Visible = false;
		List->Name = "List";
		RePosSizeList();
		ParentOfSelection->Add(List);
	}
	System::Void SetNewItems(System::Object^ sender,System::EventArgs^ e) {
		int Pos = 0;
		int NewItemIndex = 0;
		System::String^ SetItemsText = SetItems->Text;
		if (SetItemsText->Length > 0) {
			SetItemsText += ";";
		}
		cli::array<System::String^>^ NewItems = gcnew cli::array<System::String^, 1>(99) {};
		for (int Index = 0; Index < SetItemsText->Length; Index++) {
			System::String^ Symbol = SetItemsText->Substring(Index, 1);
			if (Symbol == ";") {
				NewItems[NewItemIndex] = SetItemsText->Substring(Pos, Index - Pos);
				NewItemIndex++;
				Pos = Index+1;
			}
		}
		Items = NewItems;
		if (SetItemsText == "") {
			SelectionMain->Text = "";
		}
	}
	System::Void ChangeListOpen(System::Object^ sender, System::EventArgs^ e) {
		OpenCloseItems(SetItems->Enabled);;
	}
	System::Int32 GetLengthItems() {
		int Result = 0;
		for (int i = 0; i < Items->Length; i++) {
			if (Items[i]) {
				Result++;
			}else {
				break;
			}
		}
		return Result;
	}
	System::Void RePosSizeList() {
		List->Location = System::Drawing::Point(Location.X, Location.Y + Size.Height);
		List->Size = System::Drawing::Size(Size.Width, (Size.Height * GetLengthItems()) + 10);
	}
	System::Void CreateItemInList(int Index) {
		System::Windows::Forms::Button^ Item = gcnew System::Windows::Forms::Button();
		Item->Name = Index.ToString();
		Item->BackColor = System::Drawing::Color::FromArgb(0, 0, 0, 0);
		Item->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		Item->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		Item->Location = System::Drawing::Point(0, (Index * Size.Height) + 5);
		Item->Size = Size;
		Item->FlatAppearance->BorderSize = 0;
		Item->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(0, 0, 0, 0);
		Item->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(40, 98, 145);
		Item->FlatAppearance->MouseDownBackColor = Item->FlatAppearance->MouseOverBackColor;
		Item->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
		Item->Text = Items[Index];
		Item->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		Item->Click += gcnew System::EventHandler(this, &CustomSelection::ItemClick);
		List->Controls->Add(Item);
	}
	System::Void ItemClick(System::Object^ sender, System::EventArgs^ e) {
		int Index = int::Parse(((System::Windows::Forms::Button^)sender)->Name);
		SelectionMain->Text = Items[Index];
		SetItems->Enabled = false;
	}
	System::Void OpenCloseItems(bool Bool) {
		Opened = Bool;
		if (Bool) {
			RePosSizeList();
			for (int i = 0; i < Items->Length; i++) {
				if (Items[i]) {
					CreateItemInList(i);
				}else {
					break;
				}
			}
			List->Visible = true;
		}
		else if (!Bool) {
			List->Visible = false;
			List->Controls->Clear();
		}
	}
	System::Void CustomSelectionClick(System::Object^ sender, System::EventArgs^ e) {
		SetItems->Enabled = !Opened;
	};
};