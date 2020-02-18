#include "frmMain.h"
using namespace System;
using namespace System::Text;
using namespace System::Data::SqlClient;

using namespace DBADO;
System::Void DBADO::frmMain::btnShowData_Click(System::Object^ sender, System::EventArgs^ e) {
	txtOutput->Clear();

	String^ filePath = System::IO::Directory::GetCurrentDirectory();
	String^ strConn = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=" + filePath + "\\DB-Example.mdf;Integrated Security=True;Connect Timeout=30";

	SqlConnection^ connection = gcnew SqlConnection(strConn);

	try {
		connection->Open();
		txtOutput->Text = "Connection open\n\n";
	}
	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message);
		return;
	}

	StringBuilder^ sb = gcnew StringBuilder;

	try {
		String^ strCommand = "SELECT * FROM tblParticipants ORDER BY Name ASC";
		SqlCommand^ command = gcnew SqlCommand(strCommand, connection);
		SqlDataReader^ reader = command->ExecuteReader();
		while (reader->Read()) {
			sb->AppendLine(reader["Id"]->ToString() + " " + reader["Name"]->ToString() + " " + reader["City"]->ToString());
		}
	}
	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message);
	}
	txtOutput->Text += Environment::NewLine + (sb->ToString()); // "\r\n"
	connection->Close();
	txtOutput->Text += "Connection closed";
}