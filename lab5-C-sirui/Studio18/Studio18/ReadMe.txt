studio 18 answers here
Q2
Redefinition of all function are needed to write another system inherited from abstractFileSystem, so it is quite difficult,
	but also gives a lot freedom.
Maybe a contrect file system need extra methods to manage file creation of defined file type.

Q3
When would you want to create a new concrete file factory class?
	Only once before client first attempt to create a file.
What code must be modified if a new file type is introduced that should be created by existing factories? 
	creatFile method in file factory class
Given two file system implementations that manage the same types of files, can the same factory be 
used to create files for both?
	Yes, since factory only responsible for create file.
Given two file system implementations that manage
different types of files, can the same concrete factory implementation be used to create
files for both?
	As long as file factory can create both types of files.

Q4
	AbstractFileFactory* a = new SimpleFileFactory;
	AbstractFileSystem* b = new SimpleFileSystem;
	AbstractFile* temp = a->creatFile("1.txt");
	vector<char> content;
	content.push_back('1');
	content.push_back('2');
	content.push_back('3');
	temp->write(content);
	b->addFile("1.txt", temp);
	b->openFile("1.txt");
	b->deleteFile("1.txt");
	b->closeFile(temp);
	b->deleteFile("1.txt");
	temp->read();
	cout << temp->getName() << endl;

	123
	1.txt
	~TextFile()

Q5
Only depend on abstractfile type.

