studio 19 answers here

Q2
Test code:
	AbstractFileFactory* a = new SimpleFileFactory;
	AbstractFile * txt = a->createFile("uxeyrgtnfu.txt");
	
	vector<char> content;
	content.push_back('s');
	content.push_back('b');
	txt->write(content);
	cout << "txt_size: " << txt->getSize() << endl;

	vector<char> txt_content = txt->read();
	txt_content.push_back('s');
	cout << "txt modified" << endl;

	txt->write(txt_content);
	cout << "txt_size: " << txt->getSize() << endl;

Result:
	txt_size: 2
	txt modified
	txt_size: 3

Q3:
	ObjectStructure(TextFile) call accept and pass a pointer to generalVisitor to accept 
	the accept belongs to a specific concretElement
	in concretElement, accept calls visit_textfile functions defined in the generalVisitor that was passed in, and pass this(itself) to it.


Q4:
	delegation: execute the visitor function by passing visior pointer to another class's accept function. The accept function will then call 
				a kind specific visitor to accomplish job.


Q5:
	U need to take care of circular inclusion. Basically when u have this visitor style, inclusion pattern is restricted.

Q6:
	// unit test is doing ugly on this case
	// it doesn't accept formated display like
	// cout << file->getName() << " : has size" << file->getSize() << " and type: " << "text" << endl;
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// unit test is doing ugly on this case
	// 真他妈浪费时间