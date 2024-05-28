#pragma once
#include "ChatGrupEstudiService.h"
#include "ChatMessage.h"
#include "GrupEstudi_ConsultarUI.h"
#include "MainPageUI.h"
#include "Usuari.h"
#include "CurrentSession.h"
#include "FileByteConverterService.h"
#include "GrupEstudi.h"
#include "GrupEstudiService.h"
#include "GrupEstudi_InfoUI.h"

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class ChatGrupEstudiUI : public System::Windows::Forms::Form
    {
    public:
        ChatGrupEstudiUI(Int64^ idgroup)
        {
            chatGrupEstudiService = gcnew ChatGrupEstudiService();
            fileByteConverterService = gcnew FileByteConverterService();
            GrupEstudiService^ grupEstudiService = gcnew GrupEstudiService();
            chatMembers_Refresh = gcnew List<ChatMessage^>(0);
            InitializeComponent();

            id_group = idgroup;
			group = grupEstudiService->GetGrupEstudiById(id_group);
            this->Icon = gcnew System::Drawing::Icon("app.ico");
            this->pictureBox1->Image = Image::FromFile("resources/Icons/send.png");
			this->label_grup_name->Text = "Chat " + group->GetGroupName();
            this->Load += gcnew System::EventHandler(this, &ChatGrupEstudiUI::ChatGrupEstudiUI_Load);
            listBoxFiles->Items->Clear();
            LoadFiles();
            
        }

    protected:
        ~ChatGrupEstudiUI()
        {
            Instance = nullptr;
            if (components)
            {
                delete components;
                
            }
        }

    private: System::Windows::Forms::TextBox^ messageTextBox;
    public: String^ date;
    private: System::Windows::Forms::RichTextBox^ chatListBox;
    private: ChatGrupEstudiService^ chatGrupEstudiService;
    public: System::Windows::Forms::Timer^ chatTimer;
    private: System::Windows::Forms::Button^ Button_Cancelar;
    private: List<ChatMessage^>^ chatMembers_Refresh;
    public: Int64^ messagelast_id;
	public: Int64^ last_file_id;
    public: Int64^ id_group;
	public: GrupEstudi^ group;
    public: List<Files^>^ files;
    public: static ChatGrupEstudiUI^ Instance;
    private: System::Windows::Forms::Button^ Button_Send_Files;
    private: System::ComponentModel::IContainer^ components;
    private: System::Windows::Forms::Button^ Button_Download;
    private: System::Windows::Forms::ListBox^ listBoxFiles;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Label^ label_grup_name;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::Panel^ panel3;
    private: System::Windows::Forms::Panel^ panel4;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Label^ label1;


    private: FileByteConverterService^ fileByteConverterService;

    
#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->chatTimer = (gcnew System::Windows::Forms::Timer(this->components));
            this->messageTextBox = (gcnew System::Windows::Forms::TextBox());
            this->chatListBox = (gcnew System::Windows::Forms::RichTextBox());
            this->Button_Cancelar = (gcnew System::Windows::Forms::Button());
            this->Button_Send_Files = (gcnew System::Windows::Forms::Button());
            this->Button_Download = (gcnew System::Windows::Forms::Button());
            this->listBoxFiles = (gcnew System::Windows::Forms::ListBox());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label_grup_name = (gcnew System::Windows::Forms::Label());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->tableLayoutPanel1->SuspendLayout();
            this->panel1->SuspendLayout();
            this->panel2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->panel3->SuspendLayout();
            this->panel4->SuspendLayout();
            this->SuspendLayout();
            // 
            // chatTimer
            // 
            this->chatTimer->Enabled = true;
            this->chatTimer->Interval = 500;
            this->chatTimer->Tick += gcnew System::EventHandler(this, &ChatGrupEstudiUI::TimerTickHandler);
            // 
            // messageTextBox
            // 
            this->messageTextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->messageTextBox->Location = System::Drawing::Point(18, 23);
            this->messageTextBox->Name = L"messageTextBox";
            this->messageTextBox->Size = System::Drawing::Size(402, 27);
            this->messageTextBox->TabIndex = 0;
            this->messageTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ChatGrupEstudiUI::messageTextBox_KeyDown);
            // 
            // chatListBox
            // 
            this->chatListBox->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->chatListBox->BackColor = System::Drawing::SystemColors::Window;
            this->chatListBox->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->chatListBox->Location = System::Drawing::Point(18, 25);
            this->chatListBox->Name = L"chatListBox";
            this->chatListBox->ReadOnly = true;
            this->chatListBox->Size = System::Drawing::Size(560, 288);
            this->chatListBox->TabIndex = 2;
            this->chatListBox->Text = L"";
            this->chatListBox->SelectionChanged += gcnew System::EventHandler(this, &ChatGrupEstudiUI::chatListBox_SelectionChanged);

            // 
            // Button_Cancelar
            // 
            this->Button_Cancelar->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->Button_Cancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Button_Cancelar->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Button_Cancelar->ForeColor = System::Drawing::Color::Red;
            this->Button_Cancelar->Location = System::Drawing::Point(18, 72);
            this->Button_Cancelar->Name = L"Button_Cancelar";
            this->Button_Cancelar->Size = System::Drawing::Size(87, 29);
            this->Button_Cancelar->TabIndex = 3;
            this->Button_Cancelar->Text = L"Tornar";
            this->Button_Cancelar->UseVisualStyleBackColor = true;
            this->Button_Cancelar->Click += gcnew System::EventHandler(this, &ChatGrupEstudiUI::Button_Cancelar_Click);
            // 
            // Button_Send_Files
            // 
            this->Button_Send_Files->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Button_Send_Files->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Button_Send_Files->Location = System::Drawing::Point(278, 69);
            this->Button_Send_Files->Name = L"Button_Send_Files";
            this->Button_Send_Files->Size = System::Drawing::Size(142, 34);
            this->Button_Send_Files->TabIndex = 4;
            this->Button_Send_Files->Text = L"Adjuntar fitxer";
            this->Button_Send_Files->UseVisualStyleBackColor = true;
            this->Button_Send_Files->Click += gcnew System::EventHandler(this, &ChatGrupEstudiUI::Button_Send_Files_Click);
            // 
            // Button_Download
            // 
            this->Button_Download->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->Button_Download->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Button_Download->Location = System::Drawing::Point(11, 12);
            this->Button_Download->Name = L"Button_Download";
            this->Button_Download->Size = System::Drawing::Size(99, 34);
            this->Button_Download->TabIndex = 5;
            this->Button_Download->Text = L"Download";
            this->Button_Download->UseVisualStyleBackColor = true;
            this->Button_Download->Click += gcnew System::EventHandler(this, &ChatGrupEstudiUI::Button_DownloadFile_Click);
            // 
            // listBoxFiles
            // 
            this->listBoxFiles->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->listBoxFiles->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->listBoxFiles->FormattingEnabled = true;
            this->listBoxFiles->ItemHeight = 19;
            this->listBoxFiles->Location = System::Drawing::Point(3, 24);
            this->listBoxFiles->Name = L"listBoxFiles";
            this->listBoxFiles->Size = System::Drawing::Size(159, 289);
            this->listBoxFiles->TabIndex = 6;
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->ColumnCount = 3;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                4.545455F)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                74.69287F)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                20.88452F)));
            this->tableLayoutPanel1->Controls->Add(this->panel1, 1, 1);
            this->tableLayoutPanel1->Controls->Add(this->panel2, 1, 2);
            this->tableLayoutPanel1->Controls->Add(this->panel3, 2, 1);
            this->tableLayoutPanel1->Controls->Add(this->label_grup_name, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->panel4, 2, 2);
            this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 3;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.98969F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 63.91753F)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.88136F)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
            this->tableLayoutPanel1->TabIndex = 7;
            // 
            // panel1
            // 
            this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->panel1->Controls->Add(this->chatListBox);
            this->panel1->Location = System::Drawing::Point(39, 72);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(601, 337);
            this->panel1->TabIndex = 8;
            // 
            // panel2
            // 
            this->panel2->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->panel2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->panel2->Controls->Add(this->pictureBox1);
            this->panel2->Controls->Add(this->Button_Cancelar);
            this->panel2->Controls->Add(this->Button_Send_Files);
            this->panel2->Controls->Add(this->messageTextBox);
            this->panel2->Location = System::Drawing::Point(39, 415);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(601, 115);
            this->panel2->TabIndex = 9;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(436, 23);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(30, 27);
            this->pictureBox1->TabIndex = 4;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &ChatGrupEstudiUI::sendButton_Click);
            // 
            // panel3
            // 
            this->panel3->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->panel3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->panel3->Controls->Add(this->listBoxFiles);
            this->panel3->Controls->Add(this->label1);
            this->panel3->Location = System::Drawing::Point(646, 72);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(165, 337);
            this->panel3->TabIndex = 10;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
            this->label1->Location = System::Drawing::Point(52, 3);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(63, 19);
            this->label1->TabIndex = 12;
            this->label1->Text = L"Fitxers";
            this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // label_grup_name
            // 
            this->label_grup_name->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->label_grup_name->AutoSize = true;
            this->label_grup_name->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label_grup_name->ForeColor = System::Drawing::SystemColors::HotTrack;
            this->label_grup_name->Location = System::Drawing::Point(220, 18);
            this->label_grup_name->Name = L"label_grup_name";
            this->label_grup_name->Size = System::Drawing::Size(239, 33);
            this->label_grup_name->TabIndex = 3;
            this->label_grup_name->Text = L"Chat Grup Estudi";
            this->label_grup_name->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // panel4
            // 
            this->panel4->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->panel4->Controls->Add(this->Button_Download);
            this->panel4->Location = System::Drawing::Point(668, 426);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(121, 97);
            this->panel4->TabIndex = 11;
            // 
            // ChatGrupEstudiUI
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(814, 537);
            this->Controls->Add(this->tableLayoutPanel1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->MinimumSize = System::Drawing::Size(814, 537);
            this->Name = L"ChatGrupEstudiUI";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Chat de Grupo de Estudio";
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
            this->panel1->ResumeLayout(false);
            this->panel2->ResumeLayout(false);
            this->panel2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->panel3->ResumeLayout(false);
            this->panel3->PerformLayout();
            this->panel4->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void sendButton_Click(System::Object^ sender, System::EventArgs^ e);
           System::Void ChatGrupEstudiUI_Load(System::Object^ sender, System::EventArgs^ e);
           String^ FormatMessage(System::String^ message);
           System::Void ChatGrupEstudiUI_Refresh(System::Object^ sender, System::EventArgs^ e);
		   System::Void FilesGrupEstudiUI_Refresh(System::Object^ sender, System::EventArgs^ e);
    private: System::Void Button_Cancelar_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void TimerTickHandler(System::Object^ sender, System::EventArgs^ e)
    {
        ChatGrupEstudiUI_Refresh(this, EventArgs::Empty);
        FilesGrupEstudiUI_Refresh(this, EventArgs::Empty);
        
        // Llama directamente a ChatGrupEstudiUI_Load
    }

    private: System::Void Button_Send_Files_Click(System::Object^ sender, System::EventArgs^ e);

    private: Void Button_DownloadFile_Click(System::Object^ sender, System::EventArgs^ e);

    private: Void LoadFiles();

           String^ ConvertDate(DateTime^ date);

           String^ ConvertHour(DateTime^ date);

           
    private: System::Void messageTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
    if (e->KeyCode == Keys::Enter) {
		sendButton_Click(sender, e);
	}
    }
 private: System::Void chatListBox_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
     RichTextBox^ box = dynamic_cast<RichTextBox^>(sender);
     if (box != nullptr) {
         // Anul·lar qualsevol selecció feta per l'usuari
         box->SelectionLength = 0;  // Estableix la longitud de la selecció a zero
     }
 }
            



};
}
