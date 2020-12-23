#pragma once
#include "ChooseGameModeForm.h"

namespace PRCOURSE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ StartGameButton;
	private: System::Windows::Forms::Button^ RecordsButton;
	protected:

	protected:

	private: System::Windows::Forms::Label^ NameOfTheGameLabel;


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->StartGameButton = (gcnew System::Windows::Forms::Button());
			this->RecordsButton = (gcnew System::Windows::Forms::Button());
			this->NameOfTheGameLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// StartGameButton
			// 
			this->StartGameButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StartGameButton->Location = System::Drawing::Point(221, 212);
			this->StartGameButton->Name = L"StartGameButton";
			this->StartGameButton->Size = System::Drawing::Size(130, 38);
			this->StartGameButton->TabIndex = 0;
			this->StartGameButton->Text = L"������ ����";
			this->StartGameButton->UseVisualStyleBackColor = true;
			this->StartGameButton->Click += gcnew System::EventHandler(this, &StartForm::StartGameButton_Click);
			// 
			// RecordsButton
			// 
			this->RecordsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RecordsButton->Location = System::Drawing::Point(221, 269);
			this->RecordsButton->Name = L"RecordsButton";
			this->RecordsButton->Size = System::Drawing::Size(130, 38);
			this->RecordsButton->TabIndex = 1;
			this->RecordsButton->Text = L"�������";
			this->RecordsButton->UseVisualStyleBackColor = true;
			// 
			// NameOfTheGameLabel
			// 
			this->NameOfTheGameLabel->AutoSize = true;
			this->NameOfTheGameLabel->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameOfTheGameLabel->Location = System::Drawing::Point(43, 48);
			this->NameOfTheGameLabel->Name = L"NameOfTheGameLabel";
			this->NameOfTheGameLabel->Size = System::Drawing::Size(519, 76);
			this->NameOfTheGameLabel->TabIndex = 2;
			this->NameOfTheGameLabel->Text = L"����-���������";
			this->NameOfTheGameLabel->Click += gcnew System::EventHandler(this, &StartForm::label1_Click);
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(583, 383);
			this->Controls->Add(this->NameOfTheGameLabel);
			this->Controls->Add(this->RecordsButton);
			this->Controls->Add(this->StartGameButton);
			this->Name = L"StartForm";
			this->Text = L"����-���������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void StartGameButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ChooseGameModeForm^ f2 = gcnew ChooseGameModeForm();
		this->Hide();
		f2->ShowDialog();
		this->Close();
	}
};
}
