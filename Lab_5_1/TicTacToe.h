#pragma once

#include "Module.h"

namespace Lab51 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ TicTacToe
	/// </summary>
	public ref class TicTacToe : public System::Windows::Forms::Form
	{
	public:
		TicTacToe(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~TicTacToe()
		{
			if (components)
			{
				delete components;
			}
		}
	private: bool CurrentPlayer = true;
	private: System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TicTacToe::typeid));
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TicTacToe::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Control;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->Location = System::Drawing::Point(90, 63);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(60, 60);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &TicTacToe::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Control;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->Location = System::Drawing::Point(156, 63);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(60, 60);
			this->button2->TabIndex = 0;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &TicTacToe::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::Control;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->Location = System::Drawing::Point(222, 63);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(60, 60);
			this->button3->TabIndex = 0;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &TicTacToe::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::Control;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->Location = System::Drawing::Point(90, 129);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(60, 60);
			this->button4->TabIndex = 0;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &TicTacToe::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::Control;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->Location = System::Drawing::Point(156, 129);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(60, 60);
			this->button5->TabIndex = 0;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &TicTacToe::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::Control;
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->Location = System::Drawing::Point(222, 129);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(60, 60);
			this->button6->TabIndex = 0;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &TicTacToe::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::Control;
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->Location = System::Drawing::Point(90, 195);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(60, 60);
			this->button7->TabIndex = 0;
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &TicTacToe::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::Control;
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->Location = System::Drawing::Point(156, 195);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(60, 60);
			this->button8->TabIndex = 0;
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &TicTacToe::button8_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::SystemColors::Control;
			this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->Location = System::Drawing::Point(222, 195);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(60, 60);
			this->button9->TabIndex = 0;
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &TicTacToe::button9_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::SystemColors::Control;
			this->button10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->Location = System::Drawing::Point(406, 170);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(85, 85);
			this->button10->TabIndex = 1;
			this->button10->Text = L"Reset";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &TicTacToe::button_reset_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::SystemColors::Control;
			this->button11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button11->Location = System::Drawing::Point(406, 63);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(85, 85);
			this->button11->TabIndex = 2;
			this->button11->Text = L"About";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &TicTacToe::button_about_Click);
			// 
			// TicTacToe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(588, 335);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"TicTacToe";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TicTacToe";
			this->Load += gcnew System::EventHandler(this, &TicTacToe::TicTacToe_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

		//Board methods
	private: void WinCheck(short Y, short X) {
		extern Board BoardApp;
		extern WinType WinCheckApp;

		switch (CurrentPlayer)
		{
		case 0:
			BoardApp.makeMove(Y, X, NOL);
			CurrentPlayer = true;
			break;

		case 1:
			BoardApp.makeMove(Y, X, KREST);
			CurrentPlayer = false;
			break;
		}

		WinCheckApp = BoardApp.isWin();

		switch (WinCheckApp)
		{
		case NONE:
			break;

		case X_WIN:
			MessageBox::Show("X Win!", "Winner!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			break;

		case O_WIN:
			MessageBox::Show("O Win!", "Winner!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			break;

		case DRAW:
			MessageBox::Show("Draw!", "No Winners! :(", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			break;
		}

		return;
	}

	//Buttons click
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		extern WinType WinCheckApp;

		if (!this->button1->Image && WinCheckApp == NONE)
		{
			switch (CurrentPlayer)
			{
			case 0:
				this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"null")));
				break;

			case 1:
				this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cross")));
				break;
			}

			WinCheck(0, 0);
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		extern WinType WinCheckApp;

		if (!this->button2->Image && WinCheckApp == NONE)
		{
			switch (CurrentPlayer)
			{
			case 0:
				this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"null")));
				break;

			case 1:
				this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cross")));
				break;
			}

			WinCheck(0, 1);
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		extern WinType WinCheckApp;

		if (!this->button3->Image && WinCheckApp == NONE)
		{
			switch (CurrentPlayer)
			{
			case 0:
				this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"null")));
				break;

			case 1:
				this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cross")));
				break;
			}

			WinCheck(0, 2);
		}
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		extern WinType WinCheckApp;

		if (!this->button4->Image && WinCheckApp == NONE)
		{
			switch (CurrentPlayer)
			{
			case 0:
				this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"null")));
				break;

			case 1:
				this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cross")));
				break;
			}

			WinCheck(1, 0);
		}
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		extern WinType WinCheckApp;

		if (!this->button5->Image && WinCheckApp == NONE)
		{
			switch (CurrentPlayer)
			{
			case 0:
				this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"null")));
				break;

			case 1:
				this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cross")));
				break;
			}

			WinCheck(1, 1);
		}
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		extern WinType WinCheckApp;

		if (!this->button6->Image && WinCheckApp == NONE)
		{
			switch (CurrentPlayer)
			{
			case 0:
				this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"null")));
				break;

			case 1:
				this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cross")));
				break;
			}

			WinCheck(1, 2);
		}
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		extern WinType WinCheckApp;

		if (!this->button7->Image && WinCheckApp == NONE)
		{
			switch (CurrentPlayer)
			{
			case 0:
				this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"null")));
				break;

			case 1:
				this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cross")));
				break;
			}

			WinCheck(2, 0);
		}
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		extern WinType WinCheckApp;

		if (!this->button8->Image && WinCheckApp == NONE)
		{
			switch (CurrentPlayer)
			{
			case 0:
				this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"null")));
				break;

			case 1:
				this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cross")));
				break;
			}

			WinCheck(2, 1);
		}
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
		extern WinType WinCheckApp;

		if (!this->button9->Image && WinCheckApp == NONE)
		{
			switch (CurrentPlayer)
			{
			case 0:
				this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"null")));
				break;

			case 1:
				this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cross")));
				break;
			}

			WinCheck(2, 2);
		}
	}
	private: System::Void button_about_Click(System::Object^  sender, System::EventArgs^  e) {

		MessageBox::Show("Tic-Tac-Toe\nGordeev Alexander\nMK-201\n2018", "About", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void button_reset_Click(System::Object^  sender, System::EventArgs^  e) {
		this->button1->Image = nullptr;
		this->button2->Image = nullptr;
		this->button3->Image = nullptr;
		this->button4->Image = nullptr;
		this->button5->Image = nullptr;
		this->button6->Image = nullptr;
		this->button7->Image = nullptr;
		this->button8->Image = nullptr;
		this->button9->Image = nullptr;

		extern Board BoardApp;
		extern WinType WinCheckApp;

		BoardApp.newGame();
		WinCheckApp = NONE;
		CurrentPlayer = true;
	};
	private: System::Void TicTacToe_Load(System::Object^  sender, System::EventArgs^  e) {
	}
};
}