using namespace System;
using namespace System::Data::SqlClient;
int main() {
	Console::WriteLine("Database CLR 17-FEB-2020");

	// connection string. remember to escape the backslashes!
	// NOTE: adapt path for your machine
	String^ strConn = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\Alfa\\Desktop\\VC++\\DB-ADO\\DB-Example.mdf;Integrated Security=True;Connect Timeout=30";

	SqlConnection^ connection = gcnew SqlConnection(strConn);

	try {
		connection->Open();
	}
	catch (Exception ^ ex) {
		Console::WriteLine("ERROR: connection failed.\nReason: " + ex->Message);
		Console::Write("Hit any key");
		Console::ReadKey();
		return -1;
	}

	Console::WriteLine("Connection successful");

	String^ strCommand = "SELECT COUNT (*) FROM tblParticipants";// SQL command
	SqlCommand^ command = gcnew SqlCommand(strCommand, connection);

	Console::WriteLine(command->ExecuteScalar()); // for single line answer

	connection->Close();

	Console::Write("Hit any key");
	Console::ReadKey();

	return 0;
}