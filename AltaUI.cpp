
#include "pch.h"
#include "AltaUI.h"
#include "AltaProveidorService.h"

using namespace CppCLRWinFormsProject;

// Constructor
AltaUI::AltaUI(void)
{
    InitializeComponent();
    // Asigna el manejador de eventos del clic del botón
    this->button1->Click += gcnew System::EventHandler(this, &AltaUI::button1_Click);
}

// Destructor
AltaUI::~AltaUI()
{
    if (components)
    {
        delete components;
    }
}

void AltaUI::InitializeComponent(void)
{
    this->button1 = (gcnew System::Windows::Forms::Button());
    this->SuspendLayout();
    // 
    // button1
    // 
    this->button1->Location = System::Drawing::Point(250, 118);
    this->button1->Name = L"button1";
    this->button1->Size = System::Drawing::Size(75, 23);
    this->button1->TabIndex = 0;
    this->button1->Text = L"button1";
    this->button1->UseVisualStyleBackColor = true;
    this->button1->Click += gcnew System::EventHandler(this, &AltaUI::button1_Click);
    // 
    // MyForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(720, 369);
    this->Controls->Add(this->button1);
    this->Name = L"AltaUI";
    this->Text = L"AltaUI";
    this->ResumeLayout(false);
    this->PerformLayout();
}

// Manejador del evento clic para button1
void AltaUI::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Implementación de la función que se ejecutará cuando se haga clic en button1
}

// Punto de entrada principal para la aplicación.
[STAThread]
void Main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew AltaUI());
}
