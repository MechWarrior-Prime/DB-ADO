#pragma once

namespace DBADO {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für frmMain
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form
	{
	public:
		frmMain(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnShowData;
	private: System::Windows::Forms::TextBox^ txtOutput;

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnShowData = (gcnew System::Windows::Forms::Button());
			this->txtOutput = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			//
			// btnShowData
			//
			this->btnShowData->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->btnShowData->Location = System::Drawing::Point(0, 236);
			this->btnShowData->Name = L"btnShowData";
			this->btnShowData->Size = System::Drawing::Size(960, 25);
			this->btnShowData->TabIndex = 0;
			this->btnShowData->Text = L"Show Data";
			this->btnShowData->UseVisualStyleBackColor = true;
			this->btnShowData->Click += gcnew System::EventHandler(this, &frmMain::btnShowData_Click);
			//
			// txtOutput
			//
			this->txtOutput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtOutput->Location = System::Drawing::Point(0, 0);
			this->txtOutput->Multiline = true;
			this->txtOutput->Name = L"txtOutput";
			this->txtOutput->Size = System::Drawing::Size(960, 236);
			this->txtOutput->TabIndex = 1;
			//
			// frmMain
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 261);
			this->Controls->Add(this->txtOutput);
			this->Controls->Add(this->btnShowData);
			this->DoubleBuffered = true;
			this->Name = L"frmMain";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DB-ADO Demo";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
		   System::Void btnShowData_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
