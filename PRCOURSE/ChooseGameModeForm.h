#pragma once
#include "TextQForm.h"

namespace PRCOURSE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ChooseGameModeForm
	/// </summary>
	public ref class ChooseGameModeForm : public System::Windows::Forms::Form
	{
	public:
		ChooseGameModeForm(void)
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
		~ChooseGameModeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ StandartModeButton;
	protected:
	private: System::Windows::Forms::Button^ ExtendedModeButton;
	private: System::Windows::Forms::Label^ ChooseModeLabel;
	private: System::Windows::Forms::ToolTip^ GameModeToolTip;


	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Button^ FiveQuestionsButton;
	private: System::Windows::Forms::Button^ TenQuestionsButton;
	private: System::Windows::Forms::Button^ FifteenQuestionsButton;
	private: System::Windows::Forms::Label^ QuestionsAmountLabel;
	private: System::Windows::Forms::Button^ BackButton;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		char gameMode;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ChooseGameModeForm::typeid));
			this->StandartModeButton = (gcnew System::Windows::Forms::Button());
			this->ExtendedModeButton = (gcnew System::Windows::Forms::Button());
			this->ChooseModeLabel = (gcnew System::Windows::Forms::Label());
			this->GameModeToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->FiveQuestionsButton = (gcnew System::Windows::Forms::Button());
			this->TenQuestionsButton = (gcnew System::Windows::Forms::Button());
			this->FifteenQuestionsButton = (gcnew System::Windows::Forms::Button());
			this->QuestionsAmountLabel = (gcnew System::Windows::Forms::Label());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// StandartModeButton
			// 
			this->StandartModeButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"StandartModeButton.BackgroundImage")));
			this->StandartModeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StandartModeButton->Location = System::Drawing::Point(68, 182);
			this->StandartModeButton->Name = L"StandartModeButton";
			this->StandartModeButton->Size = System::Drawing::Size(139, 40);
			this->StandartModeButton->TabIndex = 0;
			this->StandartModeButton->Text = L"Стандартный";
			this->GameModeToolTip->SetToolTip(this->StandartModeButton, L"Только обычные текстовые и блиц-вопросы");
			this->StandartModeButton->UseVisualStyleBackColor = true;
			this->StandartModeButton->Click += gcnew System::EventHandler(this, &ChooseGameModeForm::StandartModeButton_Click);
			// 
			// ExtendedModeButton
			// 
			this->ExtendedModeButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ExtendedModeButton.BackgroundImage")));
			this->ExtendedModeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ExtendedModeButton->Location = System::Drawing::Point(335, 182);
			this->ExtendedModeButton->Name = L"ExtendedModeButton";
			this->ExtendedModeButton->Size = System::Drawing::Size(139, 40);
			this->ExtendedModeButton->TabIndex = 1;
			this->ExtendedModeButton->Text = L"Расширенный";
			this->GameModeToolTip->SetToolTip(this->ExtendedModeButton, L"Обычные текстовые вопросы, блиц-вопросы и вопросы по фото.\r\nПри наведении на фото"
				L" оно увеличится.");
			this->ExtendedModeButton->UseVisualStyleBackColor = true;
			this->ExtendedModeButton->Click += gcnew System::EventHandler(this, &ChooseGameModeForm::ExtendedModeButton_Click);
			// 
			// ChooseModeLabel
			// 
			this->ChooseModeLabel->AutoSize = true;
			this->ChooseModeLabel->BackColor = System::Drawing::Color::Transparent;
			this->ChooseModeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ChooseModeLabel->Location = System::Drawing::Point(112, 53);
			this->ChooseModeLabel->Name = L"ChooseModeLabel";
			this->ChooseModeLabel->Size = System::Drawing::Size(317, 87);
			this->ChooseModeLabel->TabIndex = 2;
			this->ChooseModeLabel->Text = L"Выберите режим игры\r\n(при наведении на них\r\nвыведется их описание)";
			this->ChooseModeLabel->Click += gcnew System::EventHandler(this, &ChooseGameModeForm::ChooseModeLabel_Click);
			// 
			// GameModeToolTip
			// 
			this->GameModeToolTip->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &ChooseGameModeForm::toolTip1_Popup);
			// 
			// FiveQuestionsButton
			// 
			this->FiveQuestionsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FiveQuestionsButton.BackgroundImage")));
			this->FiveQuestionsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FiveQuestionsButton->Location = System::Drawing::Point(196, 140);
			this->FiveQuestionsButton->Name = L"FiveQuestionsButton";
			this->FiveQuestionsButton->Size = System::Drawing::Size(148, 37);
			this->FiveQuestionsButton->TabIndex = 3;
			this->FiveQuestionsButton->Text = L"5 вопросов";
			this->FiveQuestionsButton->UseVisualStyleBackColor = true;
			this->FiveQuestionsButton->Visible = false;
			this->FiveQuestionsButton->Click += gcnew System::EventHandler(this, &ChooseGameModeForm::FiveQuestionsButton_Click);
			// 
			// TenQuestionsButton
			// 
			this->TenQuestionsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TenQuestionsButton.BackgroundImage")));
			this->TenQuestionsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TenQuestionsButton->Location = System::Drawing::Point(196, 183);
			this->TenQuestionsButton->Name = L"TenQuestionsButton";
			this->TenQuestionsButton->Size = System::Drawing::Size(148, 37);
			this->TenQuestionsButton->TabIndex = 4;
			this->TenQuestionsButton->Text = L"10 вопросов";
			this->TenQuestionsButton->UseVisualStyleBackColor = true;
			this->TenQuestionsButton->Visible = false;
			this->TenQuestionsButton->Click += gcnew System::EventHandler(this, &ChooseGameModeForm::TenQuestionsButton_Click);
			// 
			// FifteenQuestionsButton
			// 
			this->FifteenQuestionsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FifteenQuestionsButton.BackgroundImage")));
			this->FifteenQuestionsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->FifteenQuestionsButton->Location = System::Drawing::Point(196, 226);
			this->FifteenQuestionsButton->Name = L"FifteenQuestionsButton";
			this->FifteenQuestionsButton->Size = System::Drawing::Size(148, 37);
			this->FifteenQuestionsButton->TabIndex = 5;
			this->FifteenQuestionsButton->Text = L"15 вопросов";
			this->FifteenQuestionsButton->UseVisualStyleBackColor = true;
			this->FifteenQuestionsButton->Visible = false;
			this->FifteenQuestionsButton->Click += gcnew System::EventHandler(this, &ChooseGameModeForm::FifteenQuestionsButton_Click);
			// 
			// QuestionsAmountLabel
			// 
			this->QuestionsAmountLabel->AutoSize = true;
			this->QuestionsAmountLabel->BackColor = System::Drawing::Color::Transparent;
			this->QuestionsAmountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->QuestionsAmountLabel->Location = System::Drawing::Point(77, 91);
			this->QuestionsAmountLabel->Name = L"QuestionsAmountLabel";
			this->QuestionsAmountLabel->Size = System::Drawing::Size(413, 29);
			this->QuestionsAmountLabel->TabIndex = 6;
			this->QuestionsAmountLabel->Text = L"Выберите количество вопросов";
			this->QuestionsAmountLabel->Visible = false;
			// 
			// BackButton
			// 
			this->BackButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackButton.BackgroundImage")));
			this->BackButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BackButton->Location = System::Drawing::Point(26, 271);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(133, 43);
			this->BackButton->TabIndex = 7;
			this->BackButton->Text = L"Назад";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Visible = false;
			this->BackButton->Click += gcnew System::EventHandler(this, &ChooseGameModeForm::BackButton_Click);
			// 
			// ChooseGameModeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(542, 336);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->QuestionsAmountLabel);
			this->Controls->Add(this->FifteenQuestionsButton);
			this->Controls->Add(this->TenQuestionsButton);
			this->Controls->Add(this->FiveQuestionsButton);
			this->Controls->Add(this->ChooseModeLabel);
			this->Controls->Add(this->ExtendedModeButton);
			this->Controls->Add(this->StandartModeButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"ChooseGameModeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Выбор режима игры";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ChooseModeLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void toolTip1_Popup(System::Object^ sender, System::Windows::Forms::PopupEventArgs^ e) {
	}
	private: System::Void StandartModeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		gameMode = 'S';
		ChooseModeLabel->Visible = false;
		StandartModeButton->Visible = false;
		ExtendedModeButton->Visible = false;
		QuestionsAmountLabel->Visible = true;
		BackButton->Visible = true;
		FiveQuestionsButton->Visible = true;
		TenQuestionsButton->Visible = true;
		FifteenQuestionsButton->Visible = true;
	}
	private: System::Void ExtendedModeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		gameMode = 'E';
		ChooseModeLabel->Visible = false;
		StandartModeButton->Visible = false;
		ExtendedModeButton->Visible = false;
		QuestionsAmountLabel->Visible = true;
		BackButton->Visible = true;
		FiveQuestionsButton->Visible = true;
		TenQuestionsButton->Visible = true;
		FifteenQuestionsButton->Visible = true;
	}
	private: System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ChooseModeLabel->Visible = true;
		StandartModeButton->Visible = true;
		ExtendedModeButton->Visible = true;
		QuestionsAmountLabel->Visible = false;
		BackButton->Visible = false;
		FiveQuestionsButton->Visible = false;
		TenQuestionsButton->Visible = false;
		FifteenQuestionsButton->Visible = false;
	}
	private: System::Void FiveQuestionsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		TextQForm^ tqf = gcnew TextQForm();
		tqf->QuestionFunc(gameMode, 5);
		this->Hide();
		tqf->ShowDialog();
		this->Show();
	}
	private: System::Void TenQuestionsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		TextQForm^ tqf = gcnew TextQForm();
		tqf->QuestionFunc(gameMode, 10);
		this->Hide();
		tqf->ShowDialog();
		this->Show();
	}
	private: System::Void FifteenQuestionsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		TextQForm^ tqf = gcnew TextQForm();
		tqf->QuestionFunc(gameMode, 15);
		this->Hide();
		tqf->ShowDialog();
		this->Show();
	}
};
}
