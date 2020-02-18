#pragma once

namespace DBADO {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

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
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::TextBox^ txtID;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::TextBox^ txtCity;

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
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->txtID = (gcnew System::Windows::Forms::TextBox());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->txtCity = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel1->SuspendLayout();
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
			// btnAdd
			//
			this->btnAdd->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->btnAdd->Location = System::Drawing::Point(0, 211);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(960, 25);
			this->btnAdd->TabIndex = 2;
			this->btnAdd->Text = L"Add Data";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &frmMain::btnAdd_Click);
			//
			// flowLayoutPanel1
			//
			this->flowLayoutPanel1->Controls->Add(this->txtID);
			this->flowLayoutPanel1->Controls->Add(this->txtName);
			this->flowLayoutPanel1->Controls->Add(this->txtCity);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 187);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(960, 24);
			this->flowLayoutPanel1->TabIndex = 6;
			//
			// txtID
			//
			this->txtID->Location = System::Drawing::Point(3, 3);
			this->txtID->Name = L"txtID";
			this->txtID->Size = System::Drawing::Size(110, 20);
			this->txtID->TabIndex = 6;
			//
			// txtName
			//
			this->txtName->Location = System::Drawing::Point(119, 3);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(110, 20);
			this->txtName->TabIndex = 7;
			//
			// txtCity
			//
			this->txtCity->Location = System::Drawing::Point(235, 3);
			this->txtCity->Name = L"txtCity";
			this->txtCity->Size = System::Drawing::Size(110, 20);
			this->txtCity->TabIndex = 8;
			//
			// frmMain
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 261);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->txtOutput);
			this->Controls->Add(this->btnShowData);
			this->DoubleBuffered = true;
			this->Name = L"frmMain";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DB-ADO Demo";
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
		   System::Void btnShowData_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filePath = System::IO::Directory::GetCurrentDirectory();
		String^ strConn = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=" + filePath + "\\DB-Example.mdf;Integrated Security=True;Connect Timeout=30";

		SqlConnection^ connection = gcnew SqlConnection(strConn);

		try {
			connection->Open();
		}
		catch (Exception ^ ex) {
			MessageBox::Show(ex->Message);
			return;
		}

		//String^ strCommand = "INSERT INTO tblParticipants (Id, Name, City) VALUES (100, 'Wilfied Wetterfest', 'Humbug')";
		String^ strCommand = "INSERT INTO tblParticipants (Id, Name, City) VALUES (" + txtID->Text + ", '" + txtName->Text + "', '" + txtCity->Text + "')";
		SqlCommand^ command = gcnew SqlCommand(strCommand, connection);

		try {
			command->ExecuteNonQuery();
		}
		catch (Exception ^ ex) {
			MessageBox::Show(ex->Message);
			return;
		}

		connection->Close();
		frmMain::btnShowData->PerformClick();
		MessageBox::Show("Data acquired");
	}
	};
}