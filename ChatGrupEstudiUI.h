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

            
            
            this->contextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip());
        
            System::Windows::Forms::ToolStripMenuItem^ menuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem("Item 1"));
            menuItem1->Text = "Descarregar";
            menuItem1->Click += gcnew System::EventHandler(this, &ChatGrupEstudiUI::Button_DownloadFile_Click);
            this->contextMenuStrip->Items->Add(menuItem1);

            System::Windows::Forms::ToolStripMenuItem^ menuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem("Item 2"));
            menuItem2->Text = "Esborrar";
            menuItem2->Click += gcnew System::EventHandler(this, &ChatGrupEstudiUI::Button_DeleteFile_Click);
            this->contextMenuStrip->Items->Add(menuItem2);

            //this->listBoxFiles->ContextMenuStrip = this->contextMenuStrip;
            id_group = idgroup;
			group = grupEstudiService->GetGrupEstudiById(id_group);
            this->Icon = gcnew System::Drawing::Icon("app.ico");
            this->pictureBox1->Image = Image::FromFile("resources/Icons/send_48dp_FILL0_wght500_GRAD-25_opsz48.png");
			this->label_grup_name->Text = "Chat " + group->GetGroupName();
            this->Load += gcnew System::EventHandler(this, &ChatGrupEstudiUI::ChatGrupEstudiUI_Load);
            listBoxFiles->Items->Clear();
            LoadFiles();



            this->listBoxFiles->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ChatGrupEstudiUI::listBox_MouseDown);
            
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





    private: System::Windows::Forms::Panel^ panel2;


    private: System::Windows::Forms::PictureBox^ pictureBox1;


    private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
    private: System::Windows::Forms::Label^ label_grup_name;
    private: System::Windows::Forms::Panel^ panel5;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Panel^ panel3;
    private: System::Windows::Forms::RichTextBox^ chatListBox;
    private: System::Windows::Forms::ListBox^ listBoxFiles;
    public: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip;


    private: FileByteConverterService^ fileByteConverterService;

    
#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->chatTimer = (gcnew System::Windows::Forms::Timer(this->components));
            this->messageTextBox = (gcnew System::Windows::Forms::TextBox());
            this->Button_Cancelar = (gcnew System::Windows::Forms::Button());
            this->Button_Send_Files = (gcnew System::Windows::Forms::Button());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->label_grup_name = (gcnew System::Windows::Forms::Label());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->chatListBox = (gcnew System::Windows::Forms::RichTextBox());
            this->listBoxFiles = (gcnew System::Windows::Forms::ListBox());
            this->panel2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->tableLayoutPanel2->SuspendLayout();
            this->panel3->SuspendLayout();
            this->panel5->SuspendLayout();
            this->panel1->SuspendLayout();
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
            this->messageTextBox->Location = System::Drawing::Point(10, 30);
            this->messageTextBox->Name = L"messageTextBox";
            this->messageTextBox->Size = System::Drawing::Size(448, 27);
            this->messageTextBox->TabIndex = 0;
            this->messageTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ChatGrupEstudiUI::messageTextBox_KeyDown);
            // 
            // Button_Cancelar
            // 
            this->Button_Cancelar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->Button_Cancelar->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Button_Cancelar->ForeColor = System::Drawing::Color::Red;
            this->Button_Cancelar->Location = System::Drawing::Point(675, 55);
            this->Button_Cancelar->Name = L"Button_Cancelar";
            this->Button_Cancelar->Size = System::Drawing::Size(93, 35);
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
            this->Button_Send_Files->Location = System::Drawing::Point(564, 282);
            this->Button_Send_Files->Name = L"Button_Send_Files";
            this->Button_Send_Files->Size = System::Drawing::Size(142, 34);
            this->Button_Send_Files->TabIndex = 4;
            this->Button_Send_Files->Text = L"Pujar fitxer";
            this->Button_Send_Files->UseVisualStyleBackColor = true;
            this->Button_Send_Files->Click += gcnew System::EventHandler(this, &ChatGrupEstudiUI::Button_Send_Files_Click);
            // 
            // panel2
            // 
            this->panel2->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->panel2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->panel2->Controls->Add(this->pictureBox1);
            this->panel2->Controls->Add(this->messageTextBox);
            this->panel2->Location = System::Drawing::Point(31, 3);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(536, 87);
            this->panel2->TabIndex = 9;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(473, 30);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(30, 27);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 4;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &ChatGrupEstudiUI::sendButton_Click);
            // 
            // tableLayoutPanel2
            // 
            this->tableLayoutPanel2->ColumnCount = 1;
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                20)));
            this->tableLayoutPanel2->Controls->Add(this->panel3, 0, 2);
            this->tableLayoutPanel2->Controls->Add(this->label_grup_name, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->panel5, 0, 1);
            this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 3;
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 8.938547F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 68.52886F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.53259F)));
            this->tableLayoutPanel2->Size = System::Drawing::Size(814, 537);
            this->tableLayoutPanel2->TabIndex = 8;
            // 
            // panel3
            // 
            this->panel3->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->panel3->Controls->Add(this->panel2);
            this->panel3->Controls->Add(this->Button_Cancelar);
            this->panel3->Location = System::Drawing::Point(3, 421);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(808, 111);
            this->panel3->TabIndex = 12;
            // 
            // label_grup_name
            // 
            this->label_grup_name->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->label_grup_name->AutoSize = true;
            this->label_grup_name->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label_grup_name->ForeColor = System::Drawing::SystemColors::HotTrack;
            this->label_grup_name->Location = System::Drawing::Point(287, 7);
            this->label_grup_name->Name = L"label_grup_name";
            this->label_grup_name->Size = System::Drawing::Size(239, 33);
            this->label_grup_name->TabIndex = 3;
            this->label_grup_name->Text = L"Chat Grup Estudi";
            this->label_grup_name->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // panel5
            // 
            this->panel5->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->panel5->Controls->Add(this->panel1);
            this->panel5->Location = System::Drawing::Point(3, 59);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(808, 345);
            this->panel5->TabIndex = 4;
            // 
            // panel1
            // 
            this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->panel1->Controls->Add(this->label1);
            this->panel1->Controls->Add(this->chatListBox);
            this->panel1->Controls->Add(this->Button_Send_Files);
            this->panel1->Controls->Add(this->listBoxFiles);
            this->panel1->Location = System::Drawing::Point(31, 14);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(737, 326);
            this->panel1->TabIndex = 8;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
            this->label1->Location = System::Drawing::Point(606, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(63, 19);
            this->label1->TabIndex = 12;
            this->label1->Text = L"Fitxers";
            this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // chatListBox
            // 
            this->chatListBox->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->chatListBox->BackColor = System::Drawing::SystemColors::Window;
            this->chatListBox->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->chatListBox->Location = System::Drawing::Point(8, 9);
            this->chatListBox->Name = L"chatListBox";
            this->chatListBox->ReadOnly = true;
            this->chatListBox->Size = System::Drawing::Size(528, 307);
            this->chatListBox->TabIndex = 2;
            this->chatListBox->Text = L"";
            this->chatListBox->SelectionChanged += gcnew System::EventHandler(this, &ChatGrupEstudiUI::chatListBox_SelectionChanged);
            // 
            // listBoxFiles
            // 
            this->listBoxFiles->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->listBoxFiles->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->listBoxFiles->FormattingEnabled = true;
            this->listBoxFiles->ItemHeight = 19;
            this->listBoxFiles->Location = System::Drawing::Point(552, 42);
            this->listBoxFiles->Name = L"listBoxFiles";
            this->listBoxFiles->Size = System::Drawing::Size(169, 232);
            this->listBoxFiles->TabIndex = 6;
            // 
            // ChatGrupEstudiUI
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(814, 537);
            this->Controls->Add(this->tableLayoutPanel2);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->MinimumSize = System::Drawing::Size(814, 537);
            this->Name = L"ChatGrupEstudiUI";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Chat de Grupo de Estudio";
            this->panel2->ResumeLayout(false);
            this->panel2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->tableLayoutPanel2->ResumeLayout(false);
            this->tableLayoutPanel2->PerformLayout();
            this->panel3->ResumeLayout(false);
            this->panel5->ResumeLayout(false);
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void sendButton_Click(System::Object^ sender, System::EventArgs^ e);
           System::Void ChatGrupEstudiUI_Load(System::Object^ sender, System::EventArgs^ e);
           String^ FormatMessage(System::String^ message);
           System::Void ChatGrupEstudiUI_Refresh(System::Object^ sender, System::EventArgs^ e);
           System::Void Button_DeleteFile_Click(System::Object^ sender, System::EventArgs^ e);
           System::Void FilesGrupEstudiUI_Refresh(System::Object^ sender, System::EventArgs^ e);
    private: System::Void Button_Cancelar_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void TimerTickHandler(System::Object^ sender, System::EventArgs^ e)
    {
        ChatGrupEstudiUI_Refresh(this, EventArgs::Empty);
        FilesGrupEstudiUI_Refresh(this, EventArgs::Empty);
        
        // Llama directamente a ChatGrupEstudiUI_Load
    }
	private: System::Void listBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
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
