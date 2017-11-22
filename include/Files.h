#ifndef FILES_H_
#define FILES_H_

#include <string>
#include <vector>

#include "GlobalVariables.h"


using namespace std;

class BaseFile {
private:
	string name;

public:
	BaseFile(string name);
	/*
	virtual ~ BaseFile(); 	//Destructor
	BaseFile(const BaseFile &other);// Copy Constructor
	BaseFile(BaseFile &&other);// Move Constructor
	BaseFile& operator=(const BaseFile &other);// Copy Assignment
	BaseFile& operator=(BaseFile &&other);// Move Assignment
	 */
	string getName() const;
	void setName(string newName);
	virtual int getSize() = 0;

	virtual bool isFile() = 0;
};

class File : public BaseFile {
private:
    int size;

public:
    File(string name, int size); // Constructor
	/*
	~ File(); 	//Destructor
	File(const File &other);// Copy Constructor
	File(File &&other);// Move Constructor
	File& operator=(const File &other);// Copy Assignment
	File& operator=(File &&other);// Move Assignment
	 */
    int getSize(); // Return the size of the file

	virtual bool isFile();

};

class Directory : public BaseFile {
private:
    vector<BaseFile*> children;
    Directory *parent;
	int depth;



public:
    Directory(string name, Directory *parent); // Constructor

/*
	Directory(const Directory &other);// Copy Constructor
	Directory(File &&other);// Move Constructor
	Directory& operator=(const Directory &other);// Copy Assignment
	Directory& operator=(Directory &&other);// Move Assignment
	*/
	~Directory();
	void deleteDir();
    Directory *getParent() const; // Return a pointer to the parent of this directory
    void setParent(Directory *newParent); // Change the parent of this directory
    void addFile(BaseFile* file); // Add the file to children
    void removeFile(string name); // Remove the file with the specified name from children
    void removeFile(BaseFile* file); // Remove the file from children
    void sortByName(); // Sort children by name alphabetically (not recursively)
    void sortBySize(); // Sort children by size (not recursively)
    vector<BaseFile*> getChildren(); // Return children
    int getSize(); // Return the size of the directory (recursively)
    string getAbsolutePath();  //Return the path from the root to this

	virtual bool isFile();
	bool isContainDirectory(string fileName);	//Return true if a directory with the specified name is in children
	bool isContainFile(string fileName);		//Return true if a file with the specified name is in children
	BaseFile* getFileByName(string fileName);	//Return the file with the specified name from children, nullptr if not exist
	int getDepth();								//Return the depth of the directory in the file system (root depth = 0)

};

#endif