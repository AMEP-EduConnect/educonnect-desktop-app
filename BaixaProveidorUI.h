#pragma once
#include "BaixaProveidorService.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class BaixaProveidorUI : public System::Windows::Forms::Form
	{
	public:
		BaixaProveidorUI(void)
		{
		}

	protected:
		~BaixaProveidorUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: BaixaProveidorService^ baixaProveidorService;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox5;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void);
#pragma endregion

	private:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e); // Declare the button1 click event handler
	};
}

