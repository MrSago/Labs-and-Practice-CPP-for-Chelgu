#pragma once

#include "ProcessInf.h"
#include <string>

Process p;

namespace Lab9WinForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ TaskMgr
	/// </summary>
	public ref class TaskMgr : public System::Windows::Forms::Form
	{
	public:
		TaskMgr(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~TaskMgr()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Data::DataTable ^table;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;



	private: System::ComponentModel::IContainer^  components;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(869, 395);
			this->dataGridView1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &TaskMgr::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(875, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 98);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Update";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TaskMgr::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(875, 297);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(129, 67);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Kill";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TaskMgr::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(875, 271);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(129, 20);
			this->textBox1->TabIndex = 3;
			// 
			// TaskMgr
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1016, 395);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"TaskMgr";
			this->Text = L"TaskMgr";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	//InitTable();

}

private: System::Void InitTable() {

	DataTable ^new_table = gcnew DataTable();

	DataColumn ^column;
	DataRow ^row;

	String^ colName = "Name";
	String^ colPID = "PID";
	String^ colPPID = "Parent PID";
	String^ colCPU = "CPU (%)";
	String^ colRAM = "RAM (bytes)";
	String^ colThreads = "Threads";
	String^ colPriorityBase = "Priority Base";
	String^ colPriorityClass = "Priority Class";

	column = gcnew DataColumn(colName, System::String::typeid);
	new_table->Columns->Add(column);
	column = gcnew DataColumn(colPID, DWORD::typeid);
	new_table->Columns->Add(column);
	column = gcnew DataColumn(colPPID, DWORD::typeid);
	new_table->Columns->Add(column);
	column = gcnew DataColumn(colCPU, double::typeid);
	new_table->Columns->Add(column);
	column = gcnew DataColumn(colRAM, SIZE_T::typeid);
	new_table->Columns->Add(column);
	column = gcnew DataColumn(colThreads, DWORD::typeid);
	new_table->Columns->Add(column);
	column = gcnew DataColumn(colPriorityBase, DWORD::typeid);
	new_table->Columns->Add(column);
	column = gcnew DataColumn(colPriorityClass, System::String::typeid);
	new_table->Columns->Add(column);

	p.GetMainProcessInfo();

	for (size_t i = 0; i < p.list.size(); ++i) {

		row = new_table->NewRow();
		row[colName] = gcnew System::String(p.list[i].pInfo.File.c_str());
		row[colPID] = p.list[i].pInfo.PID;
		row[colPPID] = p.list[i].pInfo.ParentPID;
		row[colCPU] = p.list[i].pInfo.CPUusage;
		row[colRAM] = p.list[i].pInfo.RAMusage;
		row[colThreads] = p.list[i].pInfo.Threads;
		row[colPriorityBase] = p.list[i].pInfo.PriorityBase;
		row[colPriorityClass] = gcnew System::String(p.ProcessPriority(p.list[i].pInfo.PriorityClass).c_str());
		new_table->Rows->Add(row);
	}

	if (this->table != nullptr)
		delete this->table;

	this->table = new_table;
	this->dataGridView1->DataSource = table;
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	InitTable();

}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	unsigned long killPID;
	
	if (this->textBox1->Text == nullptr || this->textBox1->Text == "")
		return;

	killPID = UInt32::Parse(this->textBox1->Text);

	p.KillProcess((DWORD)killPID);

	InitTable();

}
};
}
