#pragma once

#include "Module.h"
#include <cstdlib>
#include <ctime>
#define PIXEL_SIZE 30

namespace Lab52 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ SnakeForm
	/// </summary>
	public ref class SnakeForm : public System::Windows::Forms::Form
	{
	public:
		SnakeForm(void)
		{
			snk = new Snake(10, 10);
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~SnakeForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: WinType wt;
	private: Snake* snk;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &SnakeForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(-5, 243);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(259, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SnakeForm::button1_Click);
			// 
			// SnakeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(240, 271);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SnakeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SnakeForm";
			this->ResumeLayout(false);

		}
#pragma endregion

	protected: virtual bool ProcessCmdKey(Message% msg, Keys keyData) override {

		if (wt == GAME_CONTINUE)
		{
			switch (keyData)
			{
			case Keys::Up:
				if (snk->Struct.Look != LOOK_DOWN)
					snk->Struct.Look = LOOK_UP;
				break;

			case Keys::Down:
				if (snk->Struct.Look != LOOK_UP)
					snk->Struct.Look = LOOK_DOWN;
				break;

			case Keys::Left:
				if (snk->Struct.Look != LOOK_RIGHT)
					snk->Struct.Look = LOOK_LEFT;
				break;

			case Keys::Right:
				if (snk->Struct.Look != LOOK_LEFT)
					snk->Struct.Look = LOOK_RIGHT;
				break;
			}
		}

		return Form::ProcessCmdKey(msg, keyData);
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ gr = Graphics::FromHwnd(this->Handle);
		wt = snk->SnakeMove();

		if (snk != nullptr && wt == GAME_CONTINUE)
		{
			gr->Clear(Color::White);
			DrawWorld();
		}
	}

	private: void DrawWorld() {
		Graphics^ gr = Graphics::FromHwnd(this->Handle);
		SolidBrush^ r = gcnew SolidBrush(Color::Red);
		SolidBrush^ g = gcnew SolidBrush(Color::Green);
		SolidBrush^ bl = gcnew SolidBrush(Color::Black);

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				switch (snk->getObj(i, j))
				{
				case SNAKE_HEAD:	gr->FillEllipse(g, (i - 1) * PIXEL_SIZE, (j - 1) * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE); break;
				case SNAKE_TAIL:	gr->FillEllipse(g, (i - 1) * PIXEL_SIZE, (j - 1) * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE); break;
				case WORLD_APPLE:	gr->FillEllipse(r, (i - 1) * PIXEL_SIZE, (j - 1) * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE); break;
				}
			}
		}

		delete r;
		delete g;
		delete bl;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ gr = Graphics::FromHwnd(this->Handle);

		delete snk;
		snk = new Snake(10, 10);

		gr->Clear(Color::White);
		DrawWorld();
	}
};
}
