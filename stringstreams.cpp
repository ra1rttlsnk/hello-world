cout << "String stream manipulation initiating...\n\n";
	system("pause");
	ostringstream name;
	name << "hello" << 1;
	cout << name.str();
	system("pause");
	long long int longint;
	cout << sizeof(longint);
	
	string s;
	istringstream ist{ name.str() };
	ist >> s;
	cout << "\n\nThe string part is "<< s;
	cin.get();
