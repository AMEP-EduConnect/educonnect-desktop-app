#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AltaUI : public System::Windows::Forms::Form
	{
	public:
		AltaUI(void);
	protected: 
		~AltaUI();

	private:
		System::Windows::Forms::Button^ button1;
		System::ComponentModel::Container^ components;

		void InitializeComponent(void);
		void button1_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
