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
	/// Сводка для StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
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
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ StartGameButton;

	protected:

	protected:

	private: System::Windows::Forms::Label^ NameOfTheGameLabel;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
			this->StartGameButton = (gcnew System::Windows::Forms::Button());
			this->NameOfTheGameLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// StartGameButton
			// 
			this->StartGameButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"StartGameButton.BackgroundImage")));
			this->StartGameButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StartGameButton->Location = System::Drawing::Point(219, 233);
			this->StartGameButton->Name = L"StartGameButton";
			this->StartGameButton->Size = System::Drawing::Size(130, 38);
			this->StartGameButton->TabIndex = 0;
			this->StartGameButton->Text = L"Начать игру";
			this->StartGameButton->UseVisualStyleBackColor = true;
			this->StartGameButton->Click += gcnew System::EventHandler(this, &StartForm::StartGameButton_Click);
			// 
			// NameOfTheGameLabel
			// 
			this->NameOfTheGameLabel->AutoSize = true;
			this->NameOfTheGameLabel->BackColor = System::Drawing::Color::Transparent;
			this->NameOfTheGameLabel->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Demi", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NameOfTheGameLabel->Location = System::Drawing::Point(43, 64);
			this->NameOfTheGameLabel->Name = L"NameOfTheGameLabel";
			this->NameOfTheGameLabel->Size = System::Drawing::Size(495, 81);
			this->NameOfTheGameLabel->TabIndex = 2;
			this->NameOfTheGameLabel->Text = L"Игра-викторина";
			this->NameOfTheGameLabel->Click += gcnew System::EventHandler(this, &StartForm::label1_Click);
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(583, 383);
			this->Controls->Add(this->NameOfTheGameLabel);
			this->Controls->Add(this->StartGameButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"StartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Игра-викторина";
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
