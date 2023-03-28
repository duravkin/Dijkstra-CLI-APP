#pragma once

namespace Practice22 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ CreateTop;
	private: System::Windows::Forms::PictureBox^ PaperBox;

	private: System::Windows::Forms::Button^ DeleteTop;
	private: System::Windows::Forms::Button^ MoveTop;
	private: System::Windows::Forms::Button^ CreateRoad;
	private: System::Windows::Forms::GroupBox^ RoadLenBox;
	private: System::Windows::Forms::Button^ CreateRoadLen;
	private: System::Windows::Forms::TextBox^ RoadLen;
	private: System::Windows::Forms::Button^ DeleteAll;
	private: System::Windows::Forms::Button^ SearchRoad;
	private: System::Windows::Forms::Label^ OutputLen;




	protected:

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
			this->CreateTop = (gcnew System::Windows::Forms::Button());
			this->PaperBox = (gcnew System::Windows::Forms::PictureBox());
			this->DeleteTop = (gcnew System::Windows::Forms::Button());
			this->MoveTop = (gcnew System::Windows::Forms::Button());
			this->CreateRoad = (gcnew System::Windows::Forms::Button());
			this->RoadLenBox = (gcnew System::Windows::Forms::GroupBox());
			this->CreateRoadLen = (gcnew System::Windows::Forms::Button());
			this->RoadLen = (gcnew System::Windows::Forms::TextBox());
			this->DeleteAll = (gcnew System::Windows::Forms::Button());
			this->SearchRoad = (gcnew System::Windows::Forms::Button());
			this->OutputLen = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PaperBox))->BeginInit();
			this->RoadLenBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// CreateTop
			// 
			this->CreateTop->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->CreateTop->BackColor = System::Drawing::Color::Gainsboro;
			this->CreateTop->Location = System::Drawing::Point(787, 12);
			this->CreateTop->Name = L"CreateTop";
			this->CreateTop->Size = System::Drawing::Size(154, 37);
			this->CreateTop->TabIndex = 0;
			this->CreateTop->Text = L"Создать вершину";
			this->CreateTop->UseVisualStyleBackColor = false;
			this->CreateTop->Click += gcnew System::EventHandler(this, &MyForm::CreateTop_Click);
			// 
			// PaperBox
			// 
			this->PaperBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PaperBox->BackColor = System::Drawing::Color::LightSteelBlue;
			this->PaperBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->PaperBox->Location = System::Drawing::Point(12, 12);
			this->PaperBox->Name = L"PaperBox";
			this->PaperBox->Size = System::Drawing::Size(769, 417);
			this->PaperBox->TabIndex = 1;
			this->PaperBox->TabStop = false;
			this->PaperBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::PaperBox_Paint);
			this->PaperBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PaperBox_MouseDown);
			this->PaperBox->MouseEnter += gcnew System::EventHandler(this, &MyForm::PaperBox_MouseEnter);
			this->PaperBox->MouseLeave += gcnew System::EventHandler(this, &MyForm::PaperBox_MouseLeave);
			this->PaperBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PaperBox_MouseMove);
			// 
			// DeleteTop
			// 
			this->DeleteTop->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->DeleteTop->BackColor = System::Drawing::Color::Gainsboro;
			this->DeleteTop->Location = System::Drawing::Point(787, 55);
			this->DeleteTop->Name = L"DeleteTop";
			this->DeleteTop->Size = System::Drawing::Size(154, 37);
			this->DeleteTop->TabIndex = 2;
			this->DeleteTop->Text = L"Удалить вершину";
			this->DeleteTop->UseVisualStyleBackColor = false;
			this->DeleteTop->Click += gcnew System::EventHandler(this, &MyForm::DeleteTop_Click);
			// 
			// MoveTop
			// 
			this->MoveTop->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->MoveTop->BackColor = System::Drawing::Color::Gainsboro;
			this->MoveTop->Location = System::Drawing::Point(787, 99);
			this->MoveTop->Name = L"MoveTop";
			this->MoveTop->Size = System::Drawing::Size(154, 37);
			this->MoveTop->TabIndex = 3;
			this->MoveTop->Text = L"Переместить вершину";
			this->MoveTop->UseVisualStyleBackColor = false;
			this->MoveTop->Click += gcnew System::EventHandler(this, &MyForm::MoveTop_Click);
			// 
			// CreateRoad
			// 
			this->CreateRoad->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->CreateRoad->BackColor = System::Drawing::Color::Gainsboro;
			this->CreateRoad->Location = System::Drawing::Point(787, 143);
			this->CreateRoad->Name = L"CreateRoad";
			this->CreateRoad->Size = System::Drawing::Size(154, 37);
			this->CreateRoad->TabIndex = 4;
			this->CreateRoad->Text = L"Создать дугу";
			this->CreateRoad->UseVisualStyleBackColor = false;
			this->CreateRoad->Click += gcnew System::EventHandler(this, &MyForm::CreateRoad_Click);
			// 
			// RoadLenBox
			// 
			this->RoadLenBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->RoadLenBox->Controls->Add(this->CreateRoadLen);
			this->RoadLenBox->Controls->Add(this->RoadLen);
			this->RoadLenBox->Location = System::Drawing::Point(788, 187);
			this->RoadLenBox->Name = L"RoadLenBox";
			this->RoadLenBox->Size = System::Drawing::Size(153, 53);
			this->RoadLenBox->TabIndex = 5;
			this->RoadLenBox->TabStop = false;
			this->RoadLenBox->Text = L"Введите длину дуги";
			this->RoadLenBox->Visible = false;
			// 
			// CreateRoadLen
			// 
			this->CreateRoadLen->Location = System::Drawing::Point(113, 21);
			this->CreateRoadLen->Name = L"CreateRoadLen";
			this->CreateRoadLen->Size = System::Drawing::Size(31, 23);
			this->CreateRoadLen->TabIndex = 6;
			this->CreateRoadLen->Text = L"Ок";
			this->CreateRoadLen->UseVisualStyleBackColor = true;
			this->CreateRoadLen->Click += gcnew System::EventHandler(this, &MyForm::CreateRoadLen_Click);
			// 
			// RoadLen
			// 
			this->RoadLen->Location = System::Drawing::Point(7, 21);
			this->RoadLen->Name = L"RoadLen";
			this->RoadLen->Size = System::Drawing::Size(100, 21);
			this->RoadLen->TabIndex = 0;
			// 
			// DeleteAll
			// 
			this->DeleteAll->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->DeleteAll->BackColor = System::Drawing::Color::Gainsboro;
			this->DeleteAll->Location = System::Drawing::Point(787, 392);
			this->DeleteAll->Name = L"DeleteAll";
			this->DeleteAll->Size = System::Drawing::Size(154, 37);
			this->DeleteAll->TabIndex = 6;
			this->DeleteAll->Text = L"Удалить всё";
			this->DeleteAll->UseVisualStyleBackColor = false;
			this->DeleteAll->Click += gcnew System::EventHandler(this, &MyForm::DeleteAll_Click);
			// 
			// SearchRoad
			// 
			this->SearchRoad->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->SearchRoad->BackColor = System::Drawing::Color::Gainsboro;
			this->SearchRoad->Location = System::Drawing::Point(787, 246);
			this->SearchRoad->Name = L"SearchRoad";
			this->SearchRoad->Size = System::Drawing::Size(154, 55);
			this->SearchRoad->TabIndex = 7;
			this->SearchRoad->Text = L"Найти кратчайший путь";
			this->SearchRoad->UseVisualStyleBackColor = false;
			this->SearchRoad->Click += gcnew System::EventHandler(this, &MyForm::SearchRoad_Click);
			// 
			// OutputLen
			// 
			this->OutputLen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->OutputLen->AutoSize = true;
			this->OutputLen->Location = System::Drawing::Point(787, 308);
			this->OutputLen->Name = L"OutputLen";
			this->OutputLen->Size = System::Drawing::Size(0, 15);
			this->OutputLen->TabIndex = 8;
			// 
			// MyForm
			// 
			this->AcceptButton = this->CreateRoadLen;
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(944, 441);
			this->Controls->Add(this->OutputLen);
			this->Controls->Add(this->SearchRoad);
			this->Controls->Add(this->DeleteAll);
			this->Controls->Add(this->RoadLenBox);
			this->Controls->Add(this->CreateRoad);
			this->Controls->Add(this->MoveTop);
			this->Controls->Add(this->DeleteTop);
			this->Controls->Add(this->PaperBox);
			this->Controls->Add(this->CreateTop);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MinimumSize = System::Drawing::Size(960, 480);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Поиск кратчайшего пути на графе (алгоритм Дейкстры)";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PaperBox))->EndInit();
			this->RoadLenBox->ResumeLayout(false);
			this->RoadLenBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Pen^ PenForTops;
		Pen^ PenForRoads;
		Drawing::Font^ font;
		Brush^ brush;


private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void CreateTop_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DeleteTop_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MoveTop_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void CreateRoad_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void CreateRoadLen_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SearchRoad_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DeleteAll_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void PaperBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void PaperBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void PaperBox_MouseEnter(System::Object^ sender, System::EventArgs^ e);
private: System::Void PaperBox_MouseLeave(System::Object^ sender, System::EventArgs^ e);
private: System::Void PaperBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
};
}
