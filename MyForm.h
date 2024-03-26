#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::Windows::Forms;

	public ref class AltaProveidorUI : public Form
	{
	public:
		AltaProveidorUI(void);
	protected:
		~AltaProveidorUI();

	private:
		Button^ testButton;
		void InitializeComponent(void);
	private:
		System::Void testButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
