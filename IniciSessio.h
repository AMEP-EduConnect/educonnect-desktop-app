#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de IniciSessio
	/// </summary>
	public ref class IniciSessio : public System::Windows::Forms::Form
	{
	public:
		IniciSessio(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			// Asocia los eventos Enter y Leave del TextBox al mismo manejador de eventos.
			textBox1->Enter += gcnew System::EventHandler(this, &IniciSessio::TextBox_Enter);
			textBox1->Leave += gcnew System::EventHandler(this, &IniciSessio::TextBox_Leave);

			textBox2->Enter += gcnew System::EventHandler(this, &IniciSessio::TextBox_Enter1);
			textBox2->Leave += gcnew System::EventHandler(this, &IniciSessio::TextBox_Leave1);



			// Configura el texto predeterminado cuando se carga el formulario.
			textBox1->Text = "Nom d'usuari";
			// Cambia el color del texto predeterminado para diferenciarlo del texto introducido por el usuario.
			textBox1->ForeColor = System::Drawing::SystemColors::GrayText;

			// Configura el texto predeterminado cuando se carga el formulario.
			textBox2->Text = "Contrasenya";
			// Cambia el color del texto predeterminado para diferenciarlo del texto introducido por el usuario.
			textBox2->ForeColor = System::Drawing::SystemColors::GrayText;




		}


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~IniciSessio()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(191, 108);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(161, 21);
			this->textBox1->TabIndex = 1;
			this->textBox1->TabStop = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &IniciSessio::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(191, 144);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(161, 21);
			this->textBox2->TabIndex = 3;
			this->textBox2->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(185, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(178, 34);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Iniciar sessió";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(191, 241);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(161, 25);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Continuar";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// IniciSessio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(535, 367);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"IniciSessio";
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &IniciSessio::IniciSessio_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		System::Void TextBox_Enter(System::Object^ sender, System::EventArgs^ e)
		{
			// Si el texto actual es igual al texto predeterminado, elimina el texto.
			if (textBox1->Text == "Nom d'usuari")
			{
				textBox1->Text = "";
				// Restaura el color del texto a negro.
				textBox1->ForeColor = System::Drawing::SystemColors::ControlText;
			}

		}
		System::Void TextBox_Leave(System::Object^ sender, System::EventArgs^ e)
		{
			// Si el texto está vacío, restaura el texto predeterminado.
			if (textBox1->Text->Trim() == "")
			{
				textBox1->Text = "Nom d'usuari";
				// Cambia el color del texto predeterminado.
				textBox1->ForeColor = System::Drawing::SystemColors::GrayText;
			}

		}
		System::Void TextBox_Enter1(System::Object^ sender, System::EventArgs^ e)
		{
			// Si el texto actual es igual al texto predeterminado, elimina el texto.
			if (textBox2->Text == "Contrasenya")
			{
				textBox2->Text = "";
				// Restaura el color del texto a negro.
				textBox2->ForeColor = System::Drawing::SystemColors::ControlText;
			}

		}
		System::Void TextBox_Leave1(System::Object^ sender, System::EventArgs^ e)
		{
			// Si el texto está vacío, restaura el texto predeterminado.
			if (textBox2->Text->Trim() == "")
			{
				textBox2->Text = "Contrasenya";
				// Cambia el color del texto predeterminado.
				textBox2->ForeColor = System::Drawing::SystemColors::GrayText;
			}

		}
#pragma endregion
	private: System::Void IniciSessio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
