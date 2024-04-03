#pragma once
using namespace MySql::Data::MySqlClient;
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainPageUI
	/// </summary>
	public ref class MainPageUI : public System::Windows::Forms::Form
	{
	public:
		MainPageUI(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainPageUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ versionLabel;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->versionLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// versionLabel
			// 
			this->versionLabel->AutoSize = true;
			this->versionLabel->Location = System::Drawing::Point(64, 422);
			this->versionLabel->Name = L"versionLabel";
			this->versionLabel->Size = System::Drawing::Size(67, 13);
			this->versionLabel->TabIndex = 0;
			this->versionLabel->Text = L"versionLabel";
			// 
			// MainPageUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(938, 496);
			this->Controls->Add(this->versionLabel);
			this->Name = L"MainPageUI";
			this->Text = L"MainPageUI";
			this->Load += gcnew System::EventHandler(this, &MainPageUI::MainPageUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void MainPage_Load(System::Object^ sender, System::EventArgs^ e);
		//TESTING METHOD, DELETE LATER
		System::Void testQuery();
	};
}