#pragma once
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#define M 30
using namespace System::IO;

namespace PRCOURSE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� TextQForm
	/// </summary>
	public ref class TextQForm : public System::Windows::Forms::Form
	{
	public:
		TextQForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			for (int i = 0; i < M; i++)
			{
				regularQuestionNumbers[i] = 0;
				blitzQuestionNumbers[i] = 0;
				photoQuestionNumbers[i] = 0;
			}
		}
		/* ������� �� ������ ������� �� ����� � ������ textQName. */
		void QuestionOutputFunc(char gameMode, String^ textQName, int count, int maxQuestions, int* questionNumbers)
		{
			// ������ ����� ��� ������ ��������� ������.
			array <String^>^ answerString;
			// ������ ��� ������ ������ �� �����.
			String^ helpStr = "";
			// ����� ������� ��� ������.
			int questionNumber;
			// ����� �������� ������ ��� ������ � button.
			int answerOptionNumber;
			// ������ ��� �������� ��� �������������� ��������� ������.
			int options[4];
			for (int i = 0; i < 4; i++)
				options[i] = 0;
			// ���� ��� ������ ���������� ������.
			if (questionNumbers[0] == 0)
			{
				PointCountLabel->Text = "�����: " + points + "/" + (count * 5);
				gameMode_q = gameMode;
				count_q = count;
				srand(time(0));
				questionNumber = (rand() % maxQuestions) + 1;
				questionNumbers[0] = questionNumber;
				questionNumbers[count * 2] = -1;
			}
			else
			{
				// ��������� ������ ���������� �������.
				do
				{
					srand(time(0));
					questionNumber = (rand() % maxQuestions) + 1;
				} while (arrayContainsNumber(questionNumbers, count * 2, questionNumber));
				// �������� ����� ������� � ������ ��� ��������������.
				addNumber(questionNumbers, count * 2, questionNumber);
			}

			QuestionCountLabel->Text = "������ " + questionsAsked + "/" + count;
			// ��������� ������ ����������� ������.
			right_answer = (rand() % 4) + 1;
			addNumber(options, 4, right_answer);

			StreamReader^ fptr = File::OpenText(textQName);
			do
			{
				helpStr = fptr->ReadLine();
			} while (helpStr != questionNumber.ToString());

			helpStr = fptr->ReadLine();
			QuestionThemeLabel->Text = "������ �� ����: " + helpStr;
			// ����� �������, ���� ������ �� ����� ���������� �� ����� �������.
			do
			{
				helpStr = fptr->ReadLine();
				QuestionLabel->Text = QuestionLabel->Text + helpStr + "\n";
			} while (helpStr[0] != ' ');
			// ���� ������ �� ���� - ������� ��� ����.
			if (textQName == photoTextQName)
			{
				helpStr = fptr->ReadLine();
				Bitmap^ image = gcnew Bitmap(helpStr);
				pictureBox->Image = image;
				pictureBox->Visible = true;
			}
			// ��������� ��������� ������ �� ����� � �������� �� �� ��������� ������.
			helpStr = fptr->ReadLine();
			answerString = helpStr->Split('|');
			fptr->Close();
			// ���� �� ���������� ������ ��������� ������ � ������.
			for (int i = 0; i < 3; i++)
			{
				do
				{
					answerOptionNumber = (rand() % 4) + 1;
				} while (arrayContainsNumber(options, 4, answerOptionNumber));
				addNumber(options, 4, answerOptionNumber);

				if (answerOptionNumber == 1)
					button1->Text = answerString[i];
				if (answerOptionNumber == 2)
					button2->Text = answerString[i];
				if (answerOptionNumber == 3)
					button3->Text = answerString[i];
				if (answerOptionNumber == 4)
					button4->Text = answerString[i];
			}
			// ����� ����������� ������ � ���������� ������.
			if (right_answer == 1)
				button1->Text = answerString[3];
			if (right_answer == 2)
				button2->Text = answerString[3];
			if (right_answer == 3)
				button3->Text = answerString[3];
			if (right_answer == 4)
				button4->Text = answerString[3];
		}
		/* ������� �� ������ �������� � ������������ �� ������ ���� � ����� ��������. */
		void QuestionFunc(char gameMode, int count)
		{
			// ��� �������.
			int questionType;
			// ���-�� ��������/5 ��� �������� ���-�� ����-��������. 
			int countDivFive = count / 5;
			// ���� ����-����� ���������.
			if (isInBlitz == false)
			{
				// ���� ����� ���� �����������.
				if (gameMode == 'S')
				{
					// ���� ����� ����-������� �� ��������� (��������, �� 10 �������� �������� 2 ����-�������).
					if (blitzLimit < countDivFive)
					{
						// ��������� ����� ����� ������� � ���� ��������.
						srand(time(0));
						questionType = (rand() % 2);
					}
					// ���� �� ����� ��������� - ����� ������ ������� ������.
					else
					{
						questionType = 0;
					}
					// ���� ��� ������ ����-������ - ������� ���������� � ���.
					if (questionType)
					{
						gameMode_q = gameMode;
						count_q = count;
						questionsAsked++;
						blitzLimit++;
						isInBlitz = true;
						QuestionThemeLabel->Visible = false;
						QuestionLabel->Visible = false;
						button1->Visible = false;
						button2->Visible = false;
						button3->Visible = false;
						button4->Visible = false;
						BlitzLabel->Visible = true;
						BlitzContinueButton->Visible = true;
						QuestionCountLabel->Text = "������ " + questionsAsked + "/" + count;
						PointCountLabel->Text = "�����: " + points + "/" + (count * 5);
					}
					else
					{
						// ����� �������� �������.
						questionsAsked++;
						QuestionOutputFunc(gameMode, regularTextQName, count, regularMaxQuestions, regularQuestionNumbers);
					}
				}
				// ���� ����� ���� �����������. 
				else
				{
					// ���� ����� ����-������� �� ��������� (��������, �� 10 �������� �������� 2 ����-�������).
					if (blitzLimit < countDivFive)
					{
						// ��������� ����� �� ���� ����� ��������.
						srand(time(0));
						questionType = (rand() % 3);
					}
					else
					{
						// ��������� ����� �� ���� ����� �������� (������� � ������ �� ����).
						questionType = (rand() % 2);
					}

					if (questionType == 0)
					{
						// ����� �������� �������.
						questionsAsked++;
						QuestionOutputFunc(gameMode, regularTextQName, count, regularMaxQuestions, regularQuestionNumbers);
					}
					else if (questionType == 1)
					{
						// ����� ������� �� ����.
						questionsAsked++;
						QuestionOutputFunc(gameMode, photoTextQName, count, photoMaxQuestions, photoQuestionNumbers);
					}
					else
					{
						// ����� ���������� � ����-�������. ���� ����-������� �������� ����� ������� ������ "����������".
						gameMode_q = gameMode;
						count_q = count;
						questionsAsked++;
						blitzLimit++;
						isInBlitz = true;
						QuestionThemeLabel->Visible = false;
						QuestionLabel->Visible = false;
						button1->Visible = false;
						button2->Visible = false;
						button3->Visible = false;
						button4->Visible = false;
						BlitzLabel->Visible = true;
						BlitzContinueButton->Visible = true;
						QuestionCountLabel->Text = "������ " + questionsAsked + "/" + count;
						PointCountLabel->Text = "�����: " + points + "/" + (count * 5);
					}
				}
			}
			// ���� ����-����� �������.
			else
			{
				// ����� ����-�������, ���������� ���������� ���������� ����-�������� �� 1 (�� 5).
				QuestionOutputFunc(gameMode, blitzTextQName, count, blitzMaxQuestions, blitzQuestionNumbers);
				blitzQuestionsAsked++;
				// ����� ������� (8 ������).
				BlitzTimer->Start();
			}
		}
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~TextQForm()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::ComponentModel::IContainer^ components;
protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>

		// ����� ����������� �������� ������ ��� ������� ������ ������� � ��������� ������.
		int	right_answer;
		// ���������� ������.
		int points = 0;
		// ���������� ��������.
		int count_q;
		// ����� ����.
		char gameMode_q;
		// �������� ������ � ��������� � ����������� �� �� �����.
		String^ regularTextQName = "RegularTextQ.txt";
		String^ blitzTextQName = "BlitzTextQ.txt";
		String^ photoTextQName = "PhotoTextQ.txt";
		// ���������� �������� � ������ �� ���� ������.
		int regularMaxQuestions = 20;
		int blitzMaxQuestions = 16;
		int photoMaxQuestions = 5;
		// ���� ��� �����������, ��������� �� ���� � ����-������.
		bool isInBlitz = false;
		// ����� ������� ���������� ��������.
		int questionsAsked = 0;
		// ������� ����-������ (5 ����-��������) - �� ������ ���� �� ������ count_q/5.
		int blitzLimit = 0;
		// ������� ���������� ����-�������� ��� ������ ����-�����.
		int blitzQuestionsAsked = 0;
		// ������� ��������� ���������� ����-�������� ��� ������ �����.
		int blitzQuestionsAnswered = 0;


	private: System::Windows::Forms::Label^ QuestionCountLabel;
	private: System::Windows::Forms::Label^ PointCountLabel;
	private: System::Windows::Forms::Label^ QuestionThemeLabel;
	private: System::Windows::Forms::Label^ QuestionLabel;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ AnswerResultLabel;
	private: System::Windows::Forms::Button^ ContinueButton;
	private: System::Windows::Forms::Button^ BlitzContinueButton;

	private: System::Windows::Forms::Label^ BlitzLabel;
	private: System::Windows::Forms::Timer^ BlitzTimer;

	private: System::Windows::Forms::ProgressBar^ BlitzTimeProgressBar;
	private: System::Windows::Forms::PictureBox^ pictureBox;

	int* regularQuestionNumbers = (int*)malloc(sizeof(int) * (M + 1));
	int* blitzQuestionNumbers = (int*)malloc(sizeof(int) * (M + 1));
	int* photoQuestionNumbers = (int*)malloc(sizeof(int) * (M + 1));

		/* �������, �����������, �������� �� ������ ����� ������������ �����. */
		int arrayContainsNumber(int* array, int n, int number)
		{
			for (int i = 0; i < n; i++)
				if (array[i] == number)
					return 1;
			return 0;
		}

		/* �������, ����������� ����� � ������ �����. */
		void addNumber(int* array, int n, int number)
		{
			for (int i = 0; i < n; i++)
				if (array[i] == 0)
				{
					array[i] = number;
					break;
				}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TextQForm::typeid));
			this->QuestionCountLabel = (gcnew System::Windows::Forms::Label());
			this->PointCountLabel = (gcnew System::Windows::Forms::Label());
			this->QuestionThemeLabel = (gcnew System::Windows::Forms::Label());
			this->QuestionLabel = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->AnswerResultLabel = (gcnew System::Windows::Forms::Label());
			this->ContinueButton = (gcnew System::Windows::Forms::Button());
			this->BlitzContinueButton = (gcnew System::Windows::Forms::Button());
			this->BlitzLabel = (gcnew System::Windows::Forms::Label());
			this->BlitzTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->BlitzTimeProgressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// QuestionCountLabel
			// 
			this->QuestionCountLabel->AutoSize = true;
			this->QuestionCountLabel->BackColor = System::Drawing::Color::Transparent;
			this->QuestionCountLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->QuestionCountLabel->Location = System::Drawing::Point(12, 9);
			this->QuestionCountLabel->Name = L"QuestionCountLabel";
			this->QuestionCountLabel->Size = System::Drawing::Size(118, 25);
			this->QuestionCountLabel->TabIndex = 11;
			this->QuestionCountLabel->Text = L"������ 1/";
			// 
			// PointCountLabel
			// 
			this->PointCountLabel->AutoSize = true;
			this->PointCountLabel->BackColor = System::Drawing::Color::Transparent;
			this->PointCountLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PointCountLabel->Location = System::Drawing::Point(804, 11);
			this->PointCountLabel->Name = L"PointCountLabel";
			this->PointCountLabel->Size = System::Drawing::Size(100, 25);
			this->PointCountLabel->TabIndex = 12;
			this->PointCountLabel->Text = L"�����: 0";
			// 
			// QuestionThemeLabel
			// 
			this->QuestionThemeLabel->AutoSize = true;
			this->QuestionThemeLabel->BackColor = System::Drawing::Color::Transparent;
			this->QuestionThemeLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->QuestionThemeLabel->Location = System::Drawing::Point(196, 43);
			this->QuestionThemeLabel->Name = L"QuestionThemeLabel";
			this->QuestionThemeLabel->Size = System::Drawing::Size(262, 36);
			this->QuestionThemeLabel->TabIndex = 13;
			this->QuestionThemeLabel->Text = L"������ �� ����:";
			// 
			// QuestionLabel
			// 
			this->QuestionLabel->AutoSize = true;
			this->QuestionLabel->BackColor = System::Drawing::Color::Transparent;
			this->QuestionLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->QuestionLabel->Location = System::Drawing::Point(51, 89);
			this->QuestionLabel->Name = L"QuestionLabel";
			this->QuestionLabel->Size = System::Drawing::Size(15, 32);
			this->QuestionLabel->TabIndex = 14;
			this->QuestionLabel->Text = L"\r\n";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gainsboro;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(27, 266);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(417, 70);
			this->button1->TabIndex = 15;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &TextQForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Gainsboro;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(27, 384);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(417, 70);
			this->button2->TabIndex = 16;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &TextQForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Gainsboro;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(473, 266);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(451, 70);
			this->button3->TabIndex = 17;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &TextQForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Gainsboro;
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(473, 384);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(451, 70);
			this->button4->TabIndex = 18;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &TextQForm::button4_Click);
			// 
			// AnswerResultLabel
			// 
			this->AnswerResultLabel->AutoSize = true;
			this->AnswerResultLabel->BackColor = System::Drawing::Color::Transparent;
			this->AnswerResultLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AnswerResultLabel->ForeColor = System::Drawing::Color::ForestGreen;
			this->AnswerResultLabel->Location = System::Drawing::Point(372, 190);
			this->AnswerResultLabel->Name = L"AnswerResultLabel";
			this->AnswerResultLabel->Size = System::Drawing::Size(188, 56);
			this->AnswerResultLabel->TabIndex = 19;
			this->AnswerResultLabel->Text = L"�����!";
			this->AnswerResultLabel->Visible = false;
			// 
			// ContinueButton
			// 
			this->ContinueButton->BackColor = System::Drawing::Color::Gainsboro;
			this->ContinueButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ContinueButton.BackgroundImage")));
			this->ContinueButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ContinueButton->Location = System::Drawing::Point(370, 503);
			this->ContinueButton->Name = L"ContinueButton";
			this->ContinueButton->Size = System::Drawing::Size(194, 40);
			this->ContinueButton->TabIndex = 20;
			this->ContinueButton->Text = L"����������";
			this->ContinueButton->UseVisualStyleBackColor = false;
			this->ContinueButton->Visible = false;
			this->ContinueButton->Click += gcnew System::EventHandler(this, &TextQForm::ContinueButton_Click);
			// 
			// BlitzContinueButton
			// 
			this->BlitzContinueButton->BackColor = System::Drawing::Color::Gainsboro;
			this->BlitzContinueButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BlitzContinueButton.BackgroundImage")));
			this->BlitzContinueButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BlitzContinueButton->Location = System::Drawing::Point(370, 430);
			this->BlitzContinueButton->Name = L"BlitzContinueButton";
			this->BlitzContinueButton->Size = System::Drawing::Size(194, 40);
			this->BlitzContinueButton->TabIndex = 21;
			this->BlitzContinueButton->Text = L"����������";
			this->BlitzContinueButton->UseVisualStyleBackColor = false;
			this->BlitzContinueButton->Visible = false;
			this->BlitzContinueButton->Click += gcnew System::EventHandler(this, &TextQForm::BlitzContinueButton_Click);
			// 
			// BlitzLabel
			// 
			this->BlitzLabel->AutoSize = true;
			this->BlitzLabel->BackColor = System::Drawing::Color::Transparent;
			this->BlitzLabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BlitzLabel->Location = System::Drawing::Point(101, 109);
			this->BlitzLabel->Name = L"BlitzLabel";
			this->BlitzLabel->Size = System::Drawing::Size(752, 288);
			this->BlitzLabel->TabIndex = 22;
			this->BlitzLabel->Text = resources->GetString(L"BlitzLabel.Text");
			this->BlitzLabel->Visible = false;
			// 
			// BlitzTimer
			// 
			this->BlitzTimer->Interval = 1000;
			this->BlitzTimer->Tick += gcnew System::EventHandler(this, &TextQForm::BlitzTimer_Tick);
			// 
			// BlitzTimeProgressBar
			// 
			this->BlitzTimeProgressBar->BackColor = System::Drawing::Color::Yellow;
			this->BlitzTimeProgressBar->Location = System::Drawing::Point(164, 14);
			this->BlitzTimeProgressBar->MarqueeAnimationSpeed = 0;
			this->BlitzTimeProgressBar->Maximum = 8;
			this->BlitzTimeProgressBar->Name = L"BlitzTimeProgressBar";
			this->BlitzTimeProgressBar->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->BlitzTimeProgressBar->Size = System::Drawing::Size(604, 23);
			this->BlitzTimeProgressBar->Step = 1;
			this->BlitzTimeProgressBar->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->BlitzTimeProgressBar->TabIndex = 23;
			this->BlitzTimeProgressBar->Visible = false;
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox.Image")));
			this->pictureBox->Location = System::Drawing::Point(685, 50);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(243, 147);
			this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox->TabIndex = 24;
			this->pictureBox->TabStop = false;
			this->pictureBox->Visible = false;
			this->pictureBox->MouseLeave += gcnew System::EventHandler(this, &TextQForm::pictureBox_MouseLeave);
			this->pictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &TextQForm::pictureBox_MouseMove);
			// 
			// TextQForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(950, 557);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->BlitzTimeProgressBar);
			this->Controls->Add(this->BlitzLabel);
			this->Controls->Add(this->BlitzContinueButton);
			this->Controls->Add(this->ContinueButton);
			this->Controls->Add(this->AnswerResultLabel);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->QuestionLabel);
			this->Controls->Add(this->QuestionThemeLabel);
			this->Controls->Add(this->PointCountLabel);
			this->Controls->Add(this->QuestionCountLabel);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"TextQForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"���������";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// ������� ����� ������� �� ������ 1.
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// ��������� �������.
		BlitzTimer->Stop();
		// ����������� ��� ������� ���� ������.
		Bitmap^ imageRed = gcnew Bitmap("Images/red.jpg");
		Bitmap^ imageGreen = gcnew Bitmap("Images/green.jpg");
		// ����� ��� ������.
		if (right_answer == 1)
		{
			button1->BackgroundImage = imageGreen;
			if (blitzQuestionsAsked > 0)
			{
				// �� ��������� ���������� ����-������ +1 ����.
				points++;
				blitzQuestionsAnswered++;
			}
			else
				// �� ��������� ���������� �� ����-������ +5 ������.
				points += 5;
		}
		// ����� ��� ������� � ��������� �������.
		if (right_answer == 2)
		{
			button1->BackgroundImage = imageRed;
			button2->BackgroundImage = imageGreen;
			AnswerResultLabel->Text = "�������!";
			AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}
		if (right_answer == 3)
		{
			button1->BackgroundImage = imageRed;
			button3->BackgroundImage = imageGreen;
			this->AnswerResultLabel->Text = "�������!";
			this->AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}
		if (right_answer == 4)
		{
			button1->BackgroundImage = imageRed;
			button4->BackgroundImage = imageGreen;
			this->AnswerResultLabel->Text = "�������!";
			this->AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}
		// ���� ��� ����-������� ��������.
		if (blitzQuestionsAsked == 5)
		{
			BlitzTimeProgressBar->Visible = false;
			blitzQuestionsAsked = 0;
			isInBlitz = false;
			// ���� ��� ����-������� �������� ��������� - ��� +5 ������.
			if (blitzQuestionsAnswered == 5)
				points += 5;
			blitzQuestionsAnswered = 0;
		}

		PointCountLabel->Text = "�����: " + points + "/" + (count_q * 5);
		AnswerResultLabel->Visible = true;
		ContinueButton->Visible = true;
		button1->Enabled = false;
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;
		// ���� ��� ������� �������� - ������� ��������� � ����������� �� ������.
		if (questionsAsked == count_q)
		{
			if ((double)points > ((3.0 / 4.0) * (double)(count_q * 5)))
				MessageBox::Show("�� �������� ������������� ���������: " + points + "/" + (count_q * 5), "�������!");
			else if ((double)points > ((1.0 / 2.0) * (double)(count_q * 5)))
				MessageBox::Show("�� �������� ��������� ���������: " + points + "/" + (count_q * 5), "�������!");
			else
				MessageBox::Show("� ���������, �� �������� ������ ���������: " + points + "/" + (count_q * 5), "�������������");
			this->Close();
		}
	}

	/* ��� ��������� ������ ������� ���������� ������� ��� ������ ������ � ���������� �����������.*/
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		BlitzTimer->Stop();

		Bitmap^ imageRed = gcnew Bitmap("Images/red.jpg");
		Bitmap^ imageGreen = gcnew Bitmap("Images/green.jpg");

		if (right_answer == 1)
		{
			button2->BackgroundImage = imageRed;
			button1->BackgroundImage = imageGreen;
			AnswerResultLabel->Text = "�������!";
			AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}
		if (right_answer == 2)
		{
			button2->BackgroundImage = imageGreen;
			if (blitzQuestionsAsked > 0)
			{
				points++;
				blitzQuestionsAnswered++;
			}
			else
				points += 5;
		}
		if (right_answer == 3)
		{
			button2->BackgroundImage = imageRed;
			button3->BackgroundImage = imageGreen;
			this->AnswerResultLabel->Text = "�������!";
			this->AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}
		if (right_answer == 4)
		{
			button2->BackgroundImage = imageRed;
			button4->BackgroundImage = imageGreen;
			this->AnswerResultLabel->Text = "�������!";
			this->AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}

		if (blitzQuestionsAsked == 5)
		{
			BlitzTimeProgressBar->Visible = false;
			blitzQuestionsAsked = 0;
			isInBlitz = false;
			if (blitzQuestionsAnswered == 5)
				points += 5;
			blitzQuestionsAnswered = 0;
		}

		PointCountLabel->Text = "�����: " + points + "/" + (count_q * 5);
		AnswerResultLabel->Visible = true;
		ContinueButton->Visible = true;
		button1->Enabled = false;
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;

		if (questionsAsked == count_q)
		{
			if ((double)points > ((3.0 / 4.0) * (double)(count_q * 5)))
				MessageBox::Show("�� �������� ������������� ���������: " + points + "/" + (count_q * 5), "�������!");
			else if ((double)points > ((1.0 / 2.0) * (double)(count_q * 5)))
				MessageBox::Show("�� �������� ��������� ���������: " + points + "/" + (count_q * 5), "�������!");
			else
				MessageBox::Show("� ���������, �� �������� ������ ���������: " + points + "/" + (count_q * 5), "�������������");
			this->Close();
		}
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		BlitzTimer->Stop();

		Bitmap^ imageRed = gcnew Bitmap("Images/red.jpg");
		Bitmap^ imageGreen = gcnew Bitmap("Images/green.jpg");

		if (right_answer == 1)
		{
			button3->BackgroundImage = imageRed;
			button1->BackgroundImage = imageGreen;
			AnswerResultLabel->Text = "�������!";
			AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}
		if (right_answer == 2)
		{
			button3->BackgroundImage = imageRed;
			button2->BackgroundImage = imageGreen;
			this->AnswerResultLabel->Text = "�������!";
			this->AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}
		if (right_answer == 3)
		{
			button3->BackgroundImage = imageGreen;
			if (blitzQuestionsAsked > 0)
			{
				points++;
				blitzQuestionsAnswered++;
			}
			else
				points += 5;
		}
		if (right_answer == 4)
		{
			button3->BackgroundImage = imageRed;
			button4->BackgroundImage = imageGreen;
			this->AnswerResultLabel->Text = "�������!";
			this->AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}

		if (blitzQuestionsAsked == 5)
		{
			BlitzTimeProgressBar->Visible = false;
			blitzQuestionsAsked = 0;
			isInBlitz = false;
			if (blitzQuestionsAnswered == 5)
				points += 5;
			blitzQuestionsAnswered = 0;
		}

		PointCountLabel->Text = "�����: " + points + "/" + (count_q * 5);
		AnswerResultLabel->Visible = true;
		ContinueButton->Visible = true;
		button1->Enabled = false;
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;

		if (questionsAsked == count_q)
		{
			if ((double)points > ((3.0 / 4.0) * (double)(count_q * 5)))
				MessageBox::Show("�� �������� ������������� ���������: " + points + "/" + (count_q * 5), "�������!");
			else if ((double)points > ((1.0 / 2.0) * (double)(count_q * 5)))
				MessageBox::Show("�� �������� ��������� ���������: " + points + "/" + (count_q * 5), "�������!");
			else
				MessageBox::Show("� ���������, �� �������� ������ ���������: " + points + "/" + (count_q * 5), "�������������");
			this->Close();
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		BlitzTimer->Stop();

		Bitmap^ imageRed = gcnew Bitmap("Images/red.jpg");
		Bitmap^ imageGreen = gcnew Bitmap("Images/green.jpg");

		if (right_answer == 1)
		{
			button4->BackgroundImage = imageRed;
			button1->BackgroundImage = imageGreen;
			AnswerResultLabel->Text = "�������!";
			AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}
		if (right_answer == 2)
		{
			button4->BackgroundImage = imageRed;
			button2->BackgroundImage = imageGreen;
			this->AnswerResultLabel->Text = "�������!";
			this->AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}
		if (right_answer == 3)
		{
			button4->BackgroundImage = imageRed;
			button3->BackgroundImage = imageGreen;
			this->AnswerResultLabel->Text = "�������!";
			this->AnswerResultLabel->ForeColor = System::Drawing::Color::Firebrick;
		}
		if (right_answer == 4)
		{
			button4->BackgroundImage = imageGreen;
			if (blitzQuestionsAsked > 0)
			{
				points++;
				blitzQuestionsAnswered++;
			}
			else
				points += 5;
		}

		if (blitzQuestionsAsked == 5)
		{
			BlitzTimeProgressBar->Visible = false;
			blitzQuestionsAsked = 0;
			isInBlitz = false;
			if (blitzQuestionsAnswered == 5)
				points += 5;
			blitzQuestionsAnswered = 0;
		}

		PointCountLabel->Text = "�����: " + points + "/" + (count_q * 5);
		AnswerResultLabel->Visible = true;
		ContinueButton->Visible = true;
		button1->Enabled = false;
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;

		if (questionsAsked == count_q)
		{
			if ((double)points > ((3.0 / 4.0) * (double)(count_q* 5)))
				MessageBox::Show("�� �������� ������������� ���������: " + points + "/" + (count_q * 5), "�������!");
			else if ((double)points > ((1.0 / 2.0) * (double)(count_q * 5)))
				MessageBox::Show("�� �������� ��������� ���������: " + points + "/" + (count_q * 5), "�������!");
			else
				MessageBox::Show("� ���������, �� �������� ������ ���������: " + points + "/" + (count_q * 5), "�������������");
			this->Close();
		}
	}
	// ������� ����� ������� �� ������ "����������", ����������� ����� ������ �� ������.
	private: System::Void ContinueButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// ������� ��� � �������� ��������� ��� ������ ���������� �������.
		BlitzTimeProgressBar->Value = 0;
		pictureBox->Visible = false;
		AnswerResultLabel->Visible = false;
		ContinueButton->Visible = false;

		Bitmap^ imageYellow = gcnew Bitmap("Images/contrastYellow.jpg");
		button1->BackgroundImage = imageYellow;
		button2->BackgroundImage = imageYellow;
		button3->BackgroundImage = imageYellow;
		button4->BackgroundImage = imageYellow;

		button1->Enabled = true;
		button2->Enabled = true;
		button3->Enabled = true;
		button4->Enabled = true;
		AnswerResultLabel->Text = "�����!";
		AnswerResultLabel->ForeColor = System::Drawing::Color::ForestGreen;
		QuestionLabel->Text = "";
		// ��������� ������� ������ ������ �������.
		QuestionFunc(gameMode_q, count_q);
	}
	// ������� ����� ������� �� ������ "����������", ����������� ����� ����-������ ��������.
	private: System::Void BlitzContinueButton_Click(System::Object^ sender, System::EventArgs^ e) {
		QuestionFunc(gameMode_q, count_q);
		BlitzTimeProgressBar->Visible = true;
		QuestionLabel->Visible = true;
		QuestionThemeLabel->Visible = true;
		button1->Visible = true;
		button2->Visible = true;
		button3->Visible = true;
		button4->Visible = true;
		BlitzLabel->Visible = false;
		BlitzContinueButton->Visible = false;
	}
	// ������� �������, ������������� ������ ������� ��� ����-��������.
	private: System::Void BlitzTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (BlitzTimeProgressBar->Value == 8)
		{
			BlitzTimer->Stop();
			PointCountLabel->Text = "�����: " + points + "/" + (count_q * 5);
			QuestionLabel->Text = "";
			BlitzTimeProgressBar->Value = 0;
			if (blitzQuestionsAsked == 5)
			{
				blitzQuestionsAsked = 0;
				isInBlitz = false;
				blitzQuestionsAnswered = 0;
				BlitzTimeProgressBar->Visible = false;
			}
			QuestionFunc(gameMode_q, count_q);
		}
		// ��������� ������ Progress Bar, ������������ ���������� ����� ��� ������.
		BlitzTimeProgressBar->PerformStep();
	}
	// ��� ��������� ���� �� ���� - ��� ����������.
	private: System::Void pictureBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		pictureBox->Location = System::Drawing::Point(17, 50);
		pictureBox->Size = System::Drawing::Size(911, 493);
	}
	// ��� ��������� ���� � ���� - ��� ����������.
	private: System::Void pictureBox_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		pictureBox->Location = System::Drawing::Point(685, 50);
		pictureBox->Size = System::Drawing::Size(243, 147);
	}
};
}
