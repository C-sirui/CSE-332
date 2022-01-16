Studio 20 ReadMe.txt

Q2
As the answer to this question, explain why it is necessary to delete the pointer to the
actual file in the PasswordProxy destructor.

Since proxy should be the only access to Abstract File, it can only be deleted by proxy;

Q3
None;

Q4
TEST:
	AbstractFileFactory* a = new SimpleFileFactory;
	AbstractFile* txt = a->createFile("text.txt");
	vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };


	PasswordProxy txtProxy(txt, "password is no password");
	AbstractFileVisitor* read = new BasicDisplayVisitor;
	txtProxy.write(v);
	txtProxy.accept(read);
	return 0;


CMD:
	password is no password
	password is no password
	X X X X X3