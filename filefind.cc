#include <errno.h>
#include <dirent.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class File
{
public:
	std::vector<std::string> file_names;
	static std::unordered_multimap<int, std::string> getdir(std::string dir);
	void find_all_ext(std::string dir, std::string ext); 
	
protected:

private:
	void find_sub_dirs(std::string dir);
	std::vector<std::string> sub_directory;
	void find_files(std::string dir, std::string ext);
};
/*function... might want it in some class?*/
unordered_multimap<int, string> File::getdir (string dir)
{
	unordered_multimap<int, string> files;
    DIR *dp;
    struct dirent *dirp;
	int errno;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        throw errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.insert({dirp->d_type, string(dirp->d_name)});
    }
    closedir(dp);
    return files;//error
}

void File::find_files(string dir, string ext)
{
	auto fl = File::getdir(dir);
	int l = ext.size();
	for(auto a : fl) {
		if(a.second.size() >= l) {
			if(a.first == 8 && a.second.compare(a.second.size() - l, l, ext) == 0)
				file_names.push_back(dir + "/" + a.second);
		}
	}
}

void File::find_sub_dirs(string dir)
{
	sub_directory.push_back(dir);
	auto fl = File::getdir(dir);
	for(auto f : fl) {
		if(f.first == 4 && f.second!= "." && f.second != "..") {
			find_sub_dirs(dir + "/" + f.second);
		}
	}
}

void File::find_all_ext(string dir, string ext)
{
	find_sub_dirs(dir);
	for(auto d : sub_directory) find_files(d, ext);
}

int main(int argc, char** argv) {

	File f;
	if(argc < 3) {
		cout << "usage : " + string(argv[0]) + " [directory] [file extension]" << endl;
		return 0;
	} else {
		f.find_all_ext(argv[1], argv[2]);
		for(auto a : f.file_names) cout << a << " " << endl;
		auto a = f.getdir(argv[1]);
		for(auto& b : a) cout << b.first << ' ' << b.second << endl;
	}
}
