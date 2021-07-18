#pragma once
#include "WorkFile.h"
#include "Row.h"
#include "SearchRow.h"


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

	private:
		WorkFile^ _workFile;
		SearchRow^ _searchRow;

	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox_comp;
	private: System::Windows::Forms::Button^ button_search;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox_add;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button_cancelsearch;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox_post;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox_edu;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox_sal;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox_exp;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ comboBox_cond;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_comp;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_add;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_post;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_sal;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ col_edu;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col_exp;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ col_cond;



	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;


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


	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^ button_exit;
	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->button_file = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_create = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_open = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->button_save = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_saveas = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->button_exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_del = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox_cond = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox_exp = (gcnew System::Windows::Forms::MaskedTextBox());
			this->textBox_sal = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox_edu = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_post = (gcnew System::Windows::Forms::TextBox());
			this->button_cancelsearch = (gcnew System::Windows::Forms::Button());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_add = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_comp = (gcnew System::Windows::Forms::TextBox());
			this->col_comp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_add = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_post = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_sal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_edu = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->col_exp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col_cond = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->col_comp,
					this->col_add, this->col_post, this->col_sal, this->col_edu, this->col_exp, this->col_cond
			});
			this->dataGridView1->Location = System::Drawing::Point(0, 119);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1241, 416);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellValueChanged);
			this->dataGridView1->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &MainForm::dataGridView1_DataError);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->button_file, this->button_del });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1241, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// button_file
			// 
			this->button_file->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->button_create,
					this->button_open, this->toolStripSeparator1, this->button_save, this->button_saveas, this->toolStripSeparator2, this->button_exit
			});
			this->button_file->Name = L"button_file";
			this->button_file->Size = System::Drawing::Size(59, 24);
			this->button_file->Text = L"Файл";
			this->button_file->Click += gcnew System::EventHandler(this, &MainForm::button_file_Click);
			// 
			// button_create
			// 
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(192, 26);
			this->button_create->Text = L"Создать";
			this->button_create->Click += gcnew System::EventHandler(this, &MainForm::button_create_Click);
			// 
			// button_open
			// 
			this->button_open->Name = L"button_open";
			this->button_open->Size = System::Drawing::Size(192, 26);
			this->button_open->Text = L"Открыть";
			this->button_open->Click += gcnew System::EventHandler(this, &MainForm::button_open_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(189, 6);
			// 
			// button_save
			// 
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(192, 26);
			this->button_save->Text = L"Сохранить";
			this->button_save->Click += gcnew System::EventHandler(this, &MainForm::button_save_Click);
			// 
			// button_saveas
			// 
			this->button_saveas->Name = L"button_saveas";
			this->button_saveas->Size = System::Drawing::Size(192, 26);
			this->button_saveas->Text = L"Сохранить как";
			this->button_saveas->Click += gcnew System::EventHandler(this, &MainForm::button_saveas_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(189, 6);
			// 
			// button_exit
			// 
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(192, 26);
			this->button_exit->Text = L"Выход";
			this->button_exit->Click += gcnew System::EventHandler(this, &MainForm::button_exit_Click);
			// 
			// button_del
			// 
			this->button_del->Name = L"button_del";
			this->button_del->Size = System::Drawing::Size(128, 24);
			this->button_del->Text = L"Удалить строку";
			this->button_del->Click += gcnew System::EventHandler(this, &MainForm::button_del_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"csv";
			this->saveFileDialog1->Filter = L"csv files (*.csv)|*.csv";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"csv";
			this->openFileDialog1->Filter = L"csv files (*.csv)|*.csv";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->comboBox_cond);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->maskedTextBox_exp);
			this->groupBox1->Controls->Add(this->textBox_sal);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->comboBox_edu);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox_post);
			this->groupBox1->Controls->Add(this->button_cancelsearch);
			this->groupBox1->Controls->Add(this->button_search);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox_add);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox_comp);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->Location = System::Drawing::Point(0, 28);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1241, 85);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Поиск по списку";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(829, 34);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(100, 17);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Жил. Условия";
			// 
			// comboBox_cond
			// 
			this->comboBox_cond->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_cond->FormattingEnabled = true;
			this->comboBox_cond->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"квартира", L"общежитие", L"не предоставляются" });
			this->comboBox_cond->Location = System::Drawing::Point(832, 57);
			this->comboBox_cond->Name = L"comboBox_cond";
			this->comboBox_cond->Size = System::Drawing::Size(156, 24);
			this->comboBox_cond->TabIndex = 15;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(723, 34);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 17);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Стаж";
			// 
			// maskedTextBox_exp
			// 
			this->maskedTextBox_exp->Location = System::Drawing::Point(726, 57);
			this->maskedTextBox_exp->Mask = L"00";
			this->maskedTextBox_exp->Name = L"maskedTextBox_exp";
			this->maskedTextBox_exp->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox_exp->TabIndex = 13;
			this->maskedTextBox_exp->ValidatingType = System::Int32::typeid;
			// 
			// textBox_sal
			// 
			this->textBox_sal->Location = System::Drawing::Point(436, 57);
			this->textBox_sal->Name = L"textBox_sal";
			this->textBox_sal->Size = System::Drawing::Size(100, 22);
			this->textBox_sal->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(436, 34);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 17);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Зарплата";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(539, 34);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Образование";
			// 
			// comboBox_edu
			// 
			this->comboBox_edu->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_edu->FormattingEnabled = true;
			this->comboBox_edu->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"высшее", L"среднее специальное", L"среднее",
					L"начальное"
			});
			this->comboBox_edu->Location = System::Drawing::Point(542, 55);
			this->comboBox_edu->Name = L"comboBox_edu";
			this->comboBox_edu->Size = System::Drawing::Size(178, 24);
			this->comboBox_edu->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(307, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Должность";
			// 
			// textBox_post
			// 
			this->textBox_post->Location = System::Drawing::Point(307, 57);
			this->textBox_post->Name = L"textBox_post";
			this->textBox_post->Size = System::Drawing::Size(123, 22);
			this->textBox_post->TabIndex = 6;
			// 
			// button_cancelsearch
			// 
			this->button_cancelsearch->Location = System::Drawing::Point(1093, 56);
			this->button_cancelsearch->Name = L"button_cancelsearch";
			this->button_cancelsearch->Size = System::Drawing::Size(123, 23);
			this->button_cancelsearch->TabIndex = 5;
			this->button_cancelsearch->Text = L"Отменить поиск";
			this->button_cancelsearch->UseVisualStyleBackColor = true;
			this->button_cancelsearch->Click += gcnew System::EventHandler(this, &MainForm::button_cancelsearch_Click);
			// 
			// button_search
			// 
			this->button_search->Location = System::Drawing::Point(1012, 56);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(75, 23);
			this->button_search->TabIndex = 4;
			this->button_search->Text = L"Поиск";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &MainForm::button_search_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(175, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Адерс";
			// 
			// textBox_add
			// 
			this->textBox_add->Location = System::Drawing::Point(178, 57);
			this->textBox_add->Name = L"textBox_add";
			this->textBox_add->Size = System::Drawing::Size(123, 22);
			this->textBox_add->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Предприятие";
			// 
			// textBox_comp
			// 
			this->textBox_comp->Location = System::Drawing::Point(49, 57);
			this->textBox_comp->Name = L"textBox_comp";
			this->textBox_comp->Size = System::Drawing::Size(123, 22);
			this->textBox_comp->TabIndex = 0;
			// 
			// col_comp
			// 
			this->col_comp->DataPropertyName = L"comp";
			this->col_comp->HeaderText = L"Предприятие";
			this->col_comp->MinimumWidth = 6;
			this->col_comp->Name = L"col_comp";
			this->col_comp->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->col_comp->Width = 125;
			// 
			// col_add
			// 
			this->col_add->DataPropertyName = L"add";
			this->col_add->HeaderText = L"Адрес";
			this->col_add->MinimumWidth = 6;
			this->col_add->Name = L"col_add";
			this->col_add->Width = 125;
			// 
			// col_post
			// 
			this->col_post->DataPropertyName = L"post";
			this->col_post->HeaderText = L"Должность";
			this->col_post->MinimumWidth = 6;
			this->col_post->Name = L"col_post";
			this->col_post->Width = 125;
			// 
			// col_sal
			// 
			this->col_sal->DataPropertyName = L"sal";
			dataGridViewCellStyle1->Format = L"C2";
			dataGridViewCellStyle1->NullValue = nullptr;
			this->col_sal->DefaultCellStyle = dataGridViewCellStyle1;
			this->col_sal->HeaderText = L"Зарплата";
			this->col_sal->MinimumWidth = 6;
			this->col_sal->Name = L"col_sal";
			this->col_sal->Width = 125;
			// 
			// col_edu
			// 
			this->col_edu->DataPropertyName = L"edu";
			this->col_edu->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::Nothing;
			this->col_edu->HeaderText = L"Образование";
			this->col_edu->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"высшее", L"среднее специальное", L"среднее", L"начальное" });
			this->col_edu->MinimumWidth = 6;
			this->col_edu->Name = L"col_edu";
			this->col_edu->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->col_edu->Width = 125;
			// 
			// col_exp
			// 
			this->col_exp->DataPropertyName = L"exp";
			this->col_exp->HeaderText = L"Стаж";
			this->col_exp->MaxInputLength = 2;
			this->col_exp->MinimumWidth = 6;
			this->col_exp->Name = L"col_exp";
			this->col_exp->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->col_exp->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->col_exp->Width = 125;
			// 
			// col_cond
			// 
			this->col_cond->DataPropertyName = L"cond";
			this->col_cond->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::Nothing;
			this->col_cond->HeaderText = L"Жил. условия";
			this->col_cond->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"квартира", L"общежитие", L"не предоставляются" });
			this->col_cond->MinimumWidth = 6;
			this->col_cond->Name = L"col_cond";
			this->col_cond->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->col_cond->Width = 125;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1241, 535);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"Безымянный - Список вакансий";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);         //Загрузка формы
	private: System::Void button_save_Click(System::Object^ sender, System::EventArgs^ e);     //Сохранить 
	private: System::Void button_file_Click(System::Object^ sender, System::EventArgs^ e) {}   //Файл
	private: System::Void button_create_Click(System::Object^ sender, System::EventArgs^ e);   //Создать 
	private: System::Void button_open_Click(System::Object^ sender, System::EventArgs^ e);     //Открыть 
	private: System::Void button_saveas_Click(System::Object^ sender, System::EventArgs^ e);  //Сохранить как
	private: System::Void button_del_Click(System::Object^ sender, System::EventArgs^ e);       //Удалить
	private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);        //Выход
	private: System::Void dataGridView1_DataError(System::Object^ sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^ e); //Введено невозможное значение
	private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);        //Закрытие формы
	private: System::Void button_search_Click(System::Object^ sender, System::EventArgs^ e);          //Поиск
	private: System::Void button_cancelsearch_Click(System::Object^ sender, System::EventArgs^ e);    //Отменить поиск
	private: System::Void dataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e); //Изменение значения в ячейке
	};
}
