#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

#ifdef _WIN32
	char SEP = '\\';
#else
	char SEP = '/';
#endif

constexpr char NEWFOLDER[] = "renamedFiles";
constexpr int TAB = 70;

struct file_struct {

	fs::path fpath;
	uintmax_t fsize;

	file_struct(fs::path _fpath, uintmax_t _fsize) :
		fpath(_fpath), fsize(_fsize) {}
};

string getFileName(const string& s)
{
	size_t i = s.rfind(SEP, s.length());

	if (i != string::npos) {
		return(s.substr(i + 1, s.length() - i));
	}

	return("");
}

int main()
{
	setlocale(LC_ALL, "Rus");

	error_code err;
	vector<file_struct> list;

	fs::path currPath = fs::current_path();
	fs::path newPath = currPath / NEWFOLDER;

	cout << "\nCurrent directory: " << endl;
	cout << currPath << endl << endl;

	if (fs::exists(newPath))
	{
		cout << "Detected folder: " << NEWFOLDER << endl;

		fs::remove_all(newPath, err);
		if (err)
		{
			cout << "Error: can't remove folder: " << NEWFOLDER;
			return -1;
		}
		else
		{
			cout << "Folder removed!" << endl;
		}
	}

	if (!fs::create_directory(newPath, err))
	{
		cout << "Error: can't create new folder: " << NEWFOLDER;
		return -1;
	}

	cout << "Created new folder: " << NEWFOLDER << endl << endl;
	cout << "Coping files..." << endl;

	for (auto& entry : fs::recursive_directory_iterator(currPath))
	{
		if (!fs::is_directory(entry) && entry.path().parent_path() != newPath)
		{
			fs::path pathFile = newPath / entry.path().filename();

			if (fs::copy_file(entry, pathFile, fs::copy_options::skip_existing))
			{
				file_struct currFile(pathFile, fs::file_size(pathFile));
				list.push_back(currFile);
				cout << entry.path() << endl;
			}
		}
	}

	sort(list.begin(), list.end(),
		[](const file_struct& l1, const file_struct& l2) -> bool
		{
			return l1.fsize < l2.fsize; 
		});

	cout << "\nSorted files in folder: " << NEWFOLDER << endl;
	cout << setiosflags(ios::left) << setw(TAB) << "File:" << "Size:" << endl;

	for (size_t i = 0; i < list.size(); ++i)
	{
		string newFileName = to_string(i + 1) + '.' + getFileName(list[i].fpath.string());
		fs::rename(newPath / list[i].fpath.filename(), newPath / newFileName, err);
		cout << setw(TAB) << newFileName << list[i].fsize << " bytes" << endl;
	}

	return 0;
}
