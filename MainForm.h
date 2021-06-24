#pragma once

namespace Prakt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;          //Для работы с файлами

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ button_file;
	private: System::Windows::Forms::ToolStripMenuItem^ button_create;
	private: System::Windows::Forms::ToolStripMenuItem^ button_open;
	private: System::Windows::Forms::ToolStripMenuItem^ button_save;
	private: System::Windows::Forms::ToolStripMenuItem^ button_saveas;





	private: System::Windows::Forms::ToolStripMenuItem^ button_del;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_comp;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_add;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_post;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_sal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_edu;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_exp;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_cond;
	private: System::Windows::Forms::ToolStripMenuItem^ button_search;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->col_comp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_add = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_post = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_sal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_edu = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_exp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_cond = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->button_file = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_create = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_open = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_save = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_saveas = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_search = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_del = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->col_comp,
					this->col_add, this->col_post, this->col_sal, this->col_edu, this->col_exp, this->col_cond
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 28);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(994, 507);
			this->dataGridView1->TabIndex = 0;
			// 
			// col_comp
			// 
			this->col_comp->HeaderText = L"Пердприяетие";
			this->col_comp->MinimumWidth = 6;
			this->col_comp->Name = L"col_comp";
			this->col_comp->Width = 125;
			// 
			// col_add
			// 
			this->col_add->HeaderText = L"Адрес";
			this->col_add->MinimumWidth = 6;
			this->col_add->Name = L"col_add";
			this->col_add->Width = 125;
			// 
			// col_post
			// 
			this->col_post->HeaderText = L"Должность";
			this->col_post->MinimumWidth = 6;
			this->col_post->Name = L"col_post";
			this->col_post->Width = 125;
			// 
			// col_sal
			// 
			this->col_sal->HeaderText = L"Зарплата";
			this->col_sal->MinimumWidth = 6;
			this->col_sal->Name = L"col_sal";
			this->col_sal->Width = 125;
			// 
			// col_edu
			// 
			this->col_edu->HeaderText = L"Образование";
			this->col_edu->MinimumWidth = 6;
			this->col_edu->Name = L"col_edu";
			this->col_edu->Width = 125;
			// 
			// col_exp
			// 
			this->col_exp->HeaderText = L"Стаж";
			this->col_exp->MinimumWidth = 6;
			this->col_exp->Name = L"col_exp";
			this->col_exp->Width = 125;
			// 
			// col_cond
			// 
			this->col_cond->HeaderText = L"Жил. условия";
			this->col_cond->MinimumWidth = 6;
			this->col_cond->Name = L"col_cond";
			this->col_cond->Width = 125;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->button_file, this->button_search,
					this->button_del
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(994, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// button_file
			// 
			this->button_file->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->button_create,
					this->button_open, this->button_save, this->button_saveas
			});
			this->button_file->Name = L"button_file";
			this->button_file->Size = System::Drawing::Size(59, 24);
			this->button_file->Text = L"Файл";
			this->button_file->Click += gcnew System::EventHandler(this, &MainForm::button_file_Click);
			// 
			// button_create
			// 
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(224, 26);
			this->button_create->Text = L"Создать";
			this->button_create->Click += gcnew System::EventHandler(this, &MainForm::новыйToolStripMenuItem_Click);
			// 
			// button_open
			// 
			this->button_open->Name = L"button_open";
			this->button_open->Size = System::Drawing::Size(224, 26);
			this->button_open->Text = L"Открыть";
			this->button_open->Click += gcnew System::EventHandler(this, &MainForm::button_open_Click);
			// 
			// button_save
			// 
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(224, 26);
			this->button_save->Text = L"Сохранить";
			this->button_save->Click += gcnew System::EventHandler(this, &MainForm::сохранитьToolStripMenuItem_Click);
			// 
			// button_saveas
			// 
			this->button_saveas->Name = L"button_saveas";
			this->button_saveas->Size = System::Drawing::Size(224, 26);
			this->button_saveas->Text = L"Сохранить как";
			this->button_saveas->Click += gcnew System::EventHandler(this, &MainForm::button_saveas_Click);
			// 
			// button_search
			// 
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(66, 24);
			this->button_search->Text = L"Поиск";
			this->button_search->Click += gcnew System::EventHandler(this, &MainForm::button_search_Click);
			// 
			// button_del
			// 
			this->button_del->Name = L"button_del";
			this->button_del->Size = System::Drawing::Size(79, 24);
			this->button_del->Text = L"Удалить";
			this->button_del->Click += gcnew System::EventHandler(this, &MainForm::button_del_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(994, 535);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {}      //Загрузка формы
	private: System::Void button_save_Click(System::Object^ sender, System::EventArgs^ e) {}  //Сохранить 
	private: System::Void button_file_Click(System::Object^ sender, System::EventArgs^ e) {}   //Файл
	private: System::Void button_create_Click(System::Object^ sender, System::EventArgs^ e) {} //Создать 
	private: System::Void button_open_Click(System::Object^ sender, System::EventArgs^ e) {}    //Открыть 
	private: System::Void button_saveas_Click(System::Object^ sender, System::EventArgs^ e) {}  //Сохранить как
	private: System::Void button_search_Click(System::Object^ sender, System::EventArgs^ e) {}  //Поиск
	private: System::Void button_del_Click(System::Object^ sender, System::EventArgs^ e) {}     //Удалить
};
}
