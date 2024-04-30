#pragma once
#include "ChatGrupEstudiService.h"
#include "ChatMessage.h"
#include "GrupEstudi_ConsultarUI.h"
#include "MainPageUI.h"
#include "Usuari.h"
#include "CurrentSession.h"
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
        ChatGrupEstudiUI(void)
        {
            chatGrupEstudiService = gcnew ChatGrupEstudiService();
            
            chatMembers_Refresh = gcnew List<ChatMessage^>(0);
            InitializeComponent();
            this->Load += gcnew System::EventHandler(this, &ChatGrupEstudiUI::ChatGrupEstudiUI_Load);
            //this->Activated += gcnew System::EventHandler(this, &ChatGrupEstudiUI::FormActivated);
            //this->Deactivate += gcnew System::EventHandler(this, &ChatGrupEstudiUI::Button_Cancelar_Click);
        }

    protected:
        ~ChatGrupEstudiUI()
        {
            this->chatTimer->Stop();
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::TextBox^ messageTextBox;
    private: System::Windows::Forms::Button^ sendButton;
    private: System::Windows::Forms::RichTextBox^ chatListBox;
    private: ChatGrupEstudiService^ chatGrupEstudiService;
    public: System::Windows::Forms::Timer^ chatTimer;
    private: System::Windows::Forms::Button^ Button_Cancelar;
    private: List<ChatMessage^>^ chatMembers_Refresh;
    public: Int64^ messagelast_id;
    public: static ChatGrupEstudiUI^ Instance;
    private: System::ComponentModel::IContainer^ components;
    private:

    
#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->chatTimer = (gcnew System::Windows::Forms::Timer(this->components));
            this->messageTextBox = (gcnew System::Windows::Forms::TextBox());
            this->sendButton = (gcnew System::Windows::Forms::Button());
            this->chatListBox = (gcnew System::Windows::Forms::RichTextBox());
            this->Button_Cancelar = (gcnew System::Windows::Forms::Button());
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
            this->messageTextBox->Location = System::Drawing::Point(162, 394);
            this->messageTextBox->Name = L"messageTextBox";
            this->messageTextBox->Size = System::Drawing::Size(351, 20);
            this->messageTextBox->TabIndex = 0;
            // 
            // sendButton
            // 
            this->sendButton->Location = System::Drawing::Point(563, 394);
            this->sendButton->Name = L"sendButton";
            this->sendButton->Size = System::Drawing::Size(75, 23);
            this->sendButton->TabIndex = 1;
            this->sendButton->Text = L"Send";
            this->sendButton->UseVisualStyleBackColor = true;
            this->sendButton->Click += gcnew System::EventHandler(this, &ChatGrupEstudiUI::sendButton_Click);
            // 
            // chatListBox
            // 
            this->chatListBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->chatListBox->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->chatListBox->Location = System::Drawing::Point(162, 75);
            this->chatListBox->Name = L"chatListBox";
            this->chatListBox->ReadOnly = true;
            this->chatListBox->Size = System::Drawing::Size(611, 290);
            this->chatListBox->TabIndex = 2;
            this->chatListBox->Text = L"";
            // 
            // Button_Cancelar
            // 
            this->Button_Cancelar->Location = System::Drawing::Point(162, 438);
            this->Button_Cancelar->Name = L"Button_Cancelar";
            this->Button_Cancelar->Size = System::Drawing::Size(75, 23);
            this->Button_Cancelar->TabIndex = 3;
            this->Button_Cancelar->Text = L"Cancelar";
            this->Button_Cancelar->UseVisualStyleBackColor = true;
            this->Button_Cancelar->Click += gcnew System::EventHandler(this, &ChatGrupEstudiUI::Button_Cancelar_Click);
            // 
            // ChatGrupEstudiUI
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1034, 609);
            this->Controls->Add(this->Button_Cancelar);
            this->Controls->Add(this->chatListBox);
            this->Controls->Add(this->sendButton);
            this->Controls->Add(this->messageTextBox);
            this->Name = L"ChatGrupEstudiUI";
            this->Text = L"Chat de Grupo de Estudio";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void sendButton_Click(System::Object^ sender, System::EventArgs^ e);
           System::Void ChatGrupEstudiUI_Load(System::Object^ sender, System::EventArgs^ e);
           String^ FormatMessage(System::String^ message);
           System::Void ChatGrupEstudiUI_Refresh(System::Object^ sender, System::EventArgs^ e);
    private: System::Void Button_Cancelar_Click(System::Object^ sender, System::EventArgs^ e) {
        		this->chatTimer->Stop();
                /*GrupEstudi_ConsultarUI^ PanelUI = gcnew GrupEstudi_ConsultarUI();

                PanelUI->TopLevel = false;
                PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
                PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

                MainPageUI::Instance->screen->Controls->Clear();
                MainPageUI::Instance->screen->Controls->Add(PanelUI);
                PanelUI->Show();*/
    }
    private: System::Void TimerTickHandler(System::Object^ sender, System::EventArgs^ e)
    {
        ChatGrupEstudiUI_Refresh(this, EventArgs::Empty);  // Llama directamente a ChatGrupEstudiUI_Load
    }

    private: System::Void FormActivated(System::Object^ sender, System::EventArgs^ e)
    {
        this->chatTimer->Start(); // Inicia el timer cuando el formulario es activado.
    }
    };
}
