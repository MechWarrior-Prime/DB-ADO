using namespace System;
using namespace System::Data::SqlClient;
int main() {
	Console::WriteLine("Database CLR 17-FEB-2020");

	// connection string. remember to escape the backslashes!
	// NOTE: adapt path for your machine

	String^ filePath = System::IO::Directory::GetCurrentDirectory();
	//String^ strConn = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\Alfa\\Desktop\\VC++\\DB-ADO\\DB-Example.mdf;Integrated Security=True;Connect Timeout=30";
	String^ strConn = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=" + filePath + "\\DB-Example.mdf;Integrated Security=True;Connect Timeout=30";

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

	try {
		int result = Convert::ToInt32(command->ExecuteScalar());
		//Console::WriteLine(command->ExecuteScalar()); // for single line answer
		Console::WriteLine(result + " entries"); // for single line answer
		strCommand = "SELECT TOP (1) Name FROM tblParticipants ORDER BY Name ASC";
		command->CommandText = strCommand;
		Console::WriteLine("1st entry: " + command->ExecuteScalar());
	}
	catch (Exception ^ ex) {
		Console::WriteLine("ERROR: command execution failed.\nReason: " + ex->Message);
		Console::Write("Hit any key");
		Console::ReadKey();
		return -1;
	}

	// examples for class B commands: commands w/o return value
	strCommand = "UPDATE tblParticipants SET City ='Köln' WHERE Name = 'Wenzel Hilbig' ";
	strCommand = "DELETE FROM tblParticipants WHERE City = 'Rosenheim' "; // out of Rosenheim
	//-> executeNonQuery

	// examples for class C commands with multiple results
	try {
		strCommand = "SELECT * FROM tblParticipants ORDER BY Name ASC";
		command->CommandText = strCommand;
		SqlDataReader^ reader = command->ExecuteReader();
		while (reader->Read()) {
			Console::WriteLine(reader["Id"]->ToString() + " " + reader["Name"]->ToString() + " " + reader["City"]->ToString());
		}
	}
	catch (Exception ^ ex) {
		Console::WriteLine("ERROR: command execution failed.\nReason: " + ex->Message);
		Console::Write("Hit any key");
		Console::ReadKey();
		return -1;
	}

	connection->Close();

	Console::Write("Hit any key");
	Console::ReadKey();

	return 0;
}